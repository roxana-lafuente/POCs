# Based on https://www.analyticsvidhya.com/blog/2016/02/time-series-forecasting-codes-python/ tutorial

from statsmodels.tsa.stattools import adfuller
import pandas as pd
import numpy as np
import matplotlib.pylab as plt
# from matplotlib.pylab import rcParams
# rcParams['figure.figsize'] = 15, 6

def stationarity_test(ts):
    # Determining rolling mean and variance.
    rol_mean = ts.rolling(window=12, center=False).mean()
    rol_std = ts.rolling(window=12, center=False).std()

    # Plot rolling statistics.
    plt.plot(ts, color='#da4264',label='Original')
    plt.plot(rol_mean, color='#391a5a', label='Rolling Mean')
    plt.plot(rol_std, color='#369acd', label = 'Rolling Std')
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
        dfoutput['Critical Value (%s)'%key] = value
    print dfoutput
    print "\nConclusion:"
    for key, value in dftest[4].items():
        if dfoutput['Test Statistic'] < dfoutput['Critical Value (%s)' % key]:
            print "Stationary: Reject",
        else:
            print "Non-stationary: Accept",
        print "at %s level" % key

data = pd.read_csv('AirPassengers.csv')
print data.head()
print '\n Data Types:'
print data.dtypes
print data.index
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
Note: unless your time series is stationary, you cannot build a time series model!
"""
stationarity_test(ts)

# plt.plot(ts)
# plt.show()