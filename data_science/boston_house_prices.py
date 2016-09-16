from sklearn.datasets import load_boston
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt
from math import exp, log, sqrt
import statsmodels.api as sm
import pandas as pd
import numpy as np

"""
DATA SET INFO:
Feature names:
    'CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT'

Attribute Information (in order):
    - CRIM     per capita crime rate by town
    - ZN       proportion of residential land zoned for lots over 25,000 sq.ft.
    - INDUS    proportion of non-retail business acres per town
    - CHAS     Charles River dummy variable (= 1 if tract bounds river; 0 otherwise)
    - NOX      nitric oxides concentration (parts per 10 million)
    - RM       average number of rooms per dwelling
    - AGE      proportion of owner-occupied units built prior to 1940
    - DIS      weighted distances to five Boston employment centres
    - RAD      index of accessibility to radial highways
    - TAX      full-value property-tax rate per $10,000
    - PTRATIO  pupil-teacher ratio by town
    - B        1000(Bk - 0.63)^2 where Bk is the proportion of blacks by town
    - LSTAT    Percentage lower status of the population
    - MEDV     Median value of owner-occupied homes in $1000's    

Number of Instances:
    506
"""

# Load dataset
N = 506
dataset = load_boston()
boston = pd.DataFrame(dataset.data, columns=dataset.feature_names)
boston['MEDV'] = dataset.target

# Analise data
print boston.describe()
print "\n" * 10
print boston.corr(method='pearson')
print "\n" * 10
corr_with_target = boston.corr(method='pearson').ix[-1][:-1]
print corr_with_target[abs(corr_with_target).argsort()[::-1]]

# Predict - Ordinary Least Squares (OLS)
X = sm.add_constant(boston['LSTAT'])
y = dataset.target
model = sm.OLS(y, X)
theta = model.fit()
theta = theta.params

# Predict - Ordinary Least Squares (OLS) - Multivariate: LSTAT + RM
X = pd.DataFrame(boston['LSTAT'])
ones = np.ones(N)
X = sm.add_constant(np.column_stack((X['LSTAT'], ones)))
X = sm.add_constant(boston['LSTAT'])
X['RM'] = boston['RM']
multi_model = sm.OLS(y, X)
multi_theta = multi_model.fit()
multi_theta = multi_theta.params

# Predict - Ordinary Least Squares (OLS) + Log Transformation.
log_X = sm.add_constant(boston['LSTAT'])
log_y = np.log(dataset.target)
log_model = sm.OLS(log_y, log_X)
log_theta = log_model.fit()
log_theta = log_theta.params

# Predict - Ordinary Least Squares (OLS) - Multivariate: LSTAT + RM + Log Transformation.
X = pd.DataFrame(boston['LSTAT'])
ones = np.ones(N)
X = sm.add_constant(np.column_stack((X['LSTAT'], ones)))
X = sm.add_constant(boston['LSTAT'])
X['RM'] = boston['RM']
multilog_model = sm.OLS(np.log(y), X)
multilog_theta = multilog_model.fit()
multilog_theta = multilog_theta.params

# Plot data set.
fig, ax = plt.subplots(figsize=(12,8))

# Linear model.
x = np.linspace(boston.min()['MEDV'], boston.max()['MEDV'], N)
f = theta[0] + (theta[1] * x)
prediction = lambda x: theta[0] + (theta[1] * x)

# Linear model - Multivariate: LSTAT + RM.
x = np.linspace(boston.min()['LSTAT'], boston.max()['LSTAT'], N)
y = np.linspace(boston.min()['RM'], boston.max()['RM'], N)
multi_f = multi_theta[0] + (multi_theta[1] * x) + (multi_theta[2] * y)
multi_prediction = lambda x, y: multi_theta[0] + (multi_theta[1] * x) + (multi_theta[2] * y)

# Linear model + Log Transformation.
x = np.linspace(boston.min()['MEDV'], boston.max()['MEDV'], N)
log_f = np.exp(log_theta[0] + (log_theta[1] * x))
log_prediction = lambda x : np.exp(log_theta[0] + (log_theta[1] * x))

# Linear model. Multivariate: LSTAT + RM + Log Transformation.
x = np.linspace(boston.min()['LSTAT'], boston.max()['LSTAT'], N)
multilog_f = np.exp(multilog_theta[0] + (multilog_theta[1] * x) + (multilog_theta[2] * y))
multilog_prediction = lambda x, y : np.exp(multilog_theta[0] + (multilog_theta[1] * x) + (multilog_theta[2] * y))

# Plot linear model.
ax.plot(x, f, 'r', label='OLS Prediction', color='Black')

# Plot linear model + Log Transformation.
ax.plot(x, log_f, 'r', label='OLS Prediction + Log Transformation', color='Red')

# Scatter
ax.scatter(boston['MEDV'], boston['LSTAT'], label='Dataset', color='Cyan')
ax.legend(loc=2)

# Set labels.
ax.set_xlabel('LSTAT')
ax.set_ylabel('MEDV')
ax.set_title("MEDV vs LSTAT")

# We need values without the one column for calculating the errors.
X = boston['LSTAT']
X1 = boston['RM']
y = dataset.target

# Calculate and print errors.
print "RSME - Root Square Mean Error"
rms = sqrt(mean_squared_error(boston['MEDV'], f))
log_rms = sqrt(mean_squared_error(boston['MEDV'], log_f))
multi_rsme = sqrt(mean_squared_error(boston['MEDV'], multi_f))
multilog_rsme = sqrt(mean_squared_error(boston['MEDV'], multilog_f))
print "Linear model:", rms, "Log model:", log_rms,
print "Multivariate model:", multi_rsme, "Multivariate log model:", multilog_rsme
print "\n"

print "SSE - Error Sum of Squares or Residual Sum of Squares"
# SSE can be interpreted as a measure of how much variation in y is left
# unexplained by the model - that is, how much cannot be attributed to a
# linear relationship.
SSE = np.sum(np.square(np.subtract(y, prediction(X))))
log_SSE = np.sum(np.square(np.subtract(y, log_prediction(X))))
multi_SSE = np.sum(np.square(np.subtract(y, multi_prediction(X, X1))))
multilog_SSE = np.sum(np.square(np.subtract(y, multilog_prediction(X, X1))))
print "Linear model:", SSE, "Log model:", log_SSE, "Multivariate model:",
print multi_SSE, "Multivariate log model:", multilog_SSE
print "\n"

print "SST - Total Sum of Squares"
# A quantitative measure of the total amount of variation in observed y
# values is given by the total sum of squares.
SST = np.sum(np.square(np.subtract(y, np.mean(y))))
print "All models:", SST
print "\n"


print "R^2 - Coefficient of determination"
# It is interpreted as the proportion of observed y variation that can be
# explained by the simple linear regression model (attributed to an approximate
# linear relationship between y and x).
print "Linear model:", (1 - SSE/SST), "Log model:", (1 - log_SSE/SST),
print "Multivariate model:", (1 - multi_SSE/SST),
print "Multivariate log model:", (1 - multilog_SSE/SST),

plt.show()