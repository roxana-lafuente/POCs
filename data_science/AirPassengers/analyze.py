#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Based on:
https://www.analyticsvidhya.com/blog/2016/02/time-series-forecasting-codes-python/ tutorial
"""


from statsmodels.tsa.stattools import adfuller
import pandas as pd
import numpy as np
import matplotlib.pylab as plt


def stationarity_test(ts):
    """@ brief Helper function to determine if a series is stationary."""
    # Determining rolling mean and variance.
    rol_mean = ts.rolling(window=12, center=False).mean()
    rol_std = ts.rolling(window=12, center=False).std()

    # Plot rolling statistics.
    plt.plot(ts, color='#da4264', label='Original')
    plt.plot(rol_mean, color='#391a5a', label='Rolling Mean')
    plt.plot(rol_std, color='#369acd', label='Rolling Std')
    plt.legend(loc='best')
    plt.title('Rolling Mean and Standard Deviation')
    plt.show()

    # Perform Dickey-Fuller test:
    print 'Results of Dickey-Fuller Test:'
    dftest = adfuller(ts, autolag='AIC')
    dfoutput = pd.Series(dftest[0:4], index=['Test Statistic',
                                             'p-value',
                                             '#Lags Used',
                                             'Number of Observations Used'])
    for key, value in dftest[4].items():
        dfoutput['Critical Value (%s)' % key] = value
    print dfoutput
    print "\nConclusion:"
    for key, value in dftest[4].items():
        if dfoutput['Test Statistic'] < dfoutput['Critical Value (%s)' % key]:
            print "Non-stationary series: Reject",
        else:
            print "Non-stationary series: Accept",
        print "at %s level" % key

# Read data from file
data = pd.read_csv('AirPassengers.csv')
ts = data['#Passengers']
"""
Step 1: Check if Time Series(TS) is stationary.

For practical purposes, a TS will be defined as stationary if:
- its mean and variance remain constant over time.
- its autocovariance does not depend on time, ie, the covariance of the i th
term and the (i + m) th term should not be a function of time

We can use the "Dickey-Fuller Test" to check stationarity. The null hypothesis
is that the TS is non-stationary. The test results comprise of:
    - a Test Statistic
    - some Critical Values for difference confidence levels.
When you reject the null, you get that your process is stationary.

If the 'Test Statistic' is less than the 'Critical Value', we can reject the
null hypothesis and say that the series is stationary.
Note:
Unless your time series is stationary, you cannot build a time series model!
"""
stationarity_test(ts)

"""
Step 2: Make TS stationary.

There are two main reasons why a TS is not stationary:

* Trending: The mean varies over time.
* Seasonality: Variations at specific time frames.

The underlying principle is to model the trend and seasonality in the series
and remove those from the series to get a stationary series. Then statistical
forecasting techniques can be implemented on this series. The final step would
be to convert the forecasted values into the original scale by applying trend
and seasonality constraints back.
"""

# Transformation plot
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle('Applying transformations to try to make series stationary',
             fontsize=14,
             fontweight='bold')

# Original
ax.plot(ts, 'r', label='Original', color='#FA8258')

# Log
ts_log = np.log(ts)
ax.plot(ts_log, 'r', label='log', color='#bf00ff')

# SQRT
ts_sqrt = np.sqrt(ts)
ax.plot(ts_sqrt, 'r', label='sqrt', color='#39004d')

# Show plot
ax.set_xlabel('Time')
# ax.set_xlim([0, 100])
ax.set_ylabel('# Passengers')
# ax.set_ylim([0, 5])
ax.set_title("Potential transformations")
ax.legend()

"""
As we can see when we run the code, the transformation technique was not useful
this time. So we will try other techniques:
- Aggregation - taking average for a time period like monthly/weekly averages
"""

# Aggregation technique plot
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle('Using aggregation to try to make series stationary',
             fontsize=14,
             fontweight='bold')

# Aggregated series
s = pd.Series(ts.values, index=pd.to_datetime(ts.keys(), unit='s'))
ts_agg = s.resample('5S').mean()

# Plot aggregated series
ax.plot(ts_agg, 'r', label='Aggregated series', color='#bf00ff')

# Show plot
ax.set_xlabel('Time')
ax.set_ylabel('# Passengers')
ax.set_title("Potential transformations")
ax.legend()

"""
Since the aggregation technique did not work, we will try with the next one:
- Smoothing - taking rolling averages
"""
# Visualize moving average
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle('Smoothing - plotting moving average',
             fontsize=14,
             fontweight='bold')

moving_avg = ts_log.rolling(window=12, center=False).mean()
plt.plot(ts_log, label='Time series')
plt.plot(moving_avg, label='Moving average', color='red')

# Smoothing technique plot
fig, ax = plt.subplots(figsize=(12, 8))
fig.suptitle('Using smoothing to make series stationary',
             fontsize=14,
             fontweight='bold')

# Smoothed series
smooth_ts = ts_log - moving_avg
# First N values will be NaN, we drop them.
smooth_ts.dropna(inplace=True)
ax.plot(smooth_ts, 'r', label='Smoothed log series', color='#bf00ff')

# Show plot
ax.set_xlabel('Time')
ax.set_ylabel('# Passengers')
ax.set_title("Potential transformations")
ax.legend()

stationarity_test(smooth_ts)

"""
- Polynomial Fitting - fit a regression model

We won't cover this technique as smooth_series is already stationary.
"""

plt.show()
