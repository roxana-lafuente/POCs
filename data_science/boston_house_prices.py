# Author: Roxana Anabel Lafuente
# Started on: September 2016

from sklearn.cross_validation import train_test_split
from sklearn.datasets import load_boston
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt
from math import exp, log, sqrt
import statsmodels.api as sm
import pandas as pd
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import copy

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

""" *************** LOAD DATA **************** """

# Load dataset
dataset = load_boston()
boston = pd.DataFrame(dataset.data, columns=dataset.feature_names)
N = len(boston)
boston['MEDV'] = dataset.target
# Divide data set: 70% training data, 30% testing data.
boston_training, boston_testing = train_test_split(boston, test_size = 0.3)

# Training data.
x1_training = sm.add_constant(boston_training['LSTAT'])
x2_training = sm.add_constant(boston_training['RM'])

# Testing data.
x1_testing = boston_testing['LSTAT']
x2_testing = boston_testing['RM']

# 
y_training = boston_training['MEDV'].as_matrix()
y_testing = boston_testing['MEDV'].as_matrix()
y_training_log = np.log(boston_training['MEDV'])
y_testing_log = np.log(boston_testing['MEDV'])
y_training_squared = np.sqrt(boston_training['MEDV'])
y_testing_squared = np.sqrt(boston_testing['MEDV'])

# Whole dataset.
X = sm.add_constant(boston['LSTAT'])

# Log data.
y_log = np.log(dataset.target)
y_squared = np.sqrt(dataset.target)

# Whole multivariate data set.
mX = copy.deepcopy(X)
mX['RM'] = boston['RM']
mX_training = sm.add_constant(boston_training['LSTAT'])
mX_training['RM'] = boston_training['RM']
y = dataset.target

# Analise data
# print boston.describe()
# print "\n" * 10
# print boston.corr(method='pearson')
# print "\n" * 10
# corr_with_target = boston.corr(method='pearson').ix[-1][:-1]
# print corr_with_target[abs(corr_with_target).argsort()[::-1]]

""" *************** TRAIN - Ordinary Least Squares (OLS) **************** """

# Train model with all data.
model = sm.OLS(y, X)
model = model.fit()
theta = model.params

# Train model with training data only.
model_train = sm.OLS(y_training, x1_training)
model_train = model_train.fit()
theta_train = model_train.params

# Prediction function.
prediction = lambda x: theta[0] + (theta[1] * x)
prediction_train = lambda m: theta_train[0] + (theta_train[1] * m)

""" ********** TRAIN - Multivariate Ordinary Least Squares (OLS) *********** """
# Multivariate: LSTAT + RM. Train model with all data.
multi_model = sm.OLS(y, mX)
multi_model = multi_model.fit()
multi_theta = multi_model.params

# Train model with training data only.
multi_model_train = sm.OLS(y_training, mX_training)
multi_model_train = multi_model_train.fit()
multi_theta_train = multi_model_train.params

# Prediction function.
multi_prediction = lambda x, y: multi_theta[0] + (multi_theta[1] * x) + (multi_theta[2] * y)
multi_prediction_train = lambda x, y: multi_theta_train[0] + (multi_theta_train[1] * x) + (multi_theta_train[2] * y)

""" ********** TRAIN - Ordinary Least Squares (OLS) + Log Transformation. *********** """
log_model = sm.OLS(y_log, X)
log_model = log_model.fit()
log_theta = log_model.params

log_model_train = sm.OLS(y_training_log, x1_training)
log_model_train = log_model_train.fit()
log_theta_train = log_model_train.params

# Prediction function.
log_prediction = lambda x : np.exp(log_theta[0] + (log_theta[1] * x))
log_prediction_train = lambda x : np.exp(log_theta_train[0] + (log_theta_train[1] * x))

""" ********** TRAIN - Ordinary Least Squares (OLS) + Log Transformation. *********** """
# Multivariate: LSTAT + RM + Log Transformation.
multilog_model = sm.OLS(y_log, mX)
multilog_model = multilog_model.fit()
multilog_theta = multilog_model.params

multilog_model_train = sm.OLS(y_training_log, mX_training)
multilog_model_train = multilog_model_train.fit()
multilog_theta_train = multilog_model_train.params

# Prediction function.
multilog_prediction = lambda x, y : np.exp(multilog_theta[0] + (multilog_theta[1] * x) + (multilog_theta[2] * y))
multilog_prediction_train = lambda x, y : np.exp(multilog_theta_train[0] + (multilog_theta_train[1] * x) + (multilog_theta_train[2] * y))

""" ********** TRAIN - Ordinary Least Squares (OLS) + SQRT Transformation. *********** """
squared_model = sm.OLS(y_squared, X)
squared_model = squared_model.fit()
squared_theta = squared_model.params

squared_model_train = sm.OLS(y_training_squared, x1_training)
squared_model_train = squared_model_train.fit()
squared_theta_train = squared_model_train.params

# Prediction function.
squared_prediction = lambda x : np.square(squared_theta[0] + (squared_theta[1] * x))
squared_prediction_train = lambda x : np.square(squared_theta_train[0] + (squared_theta_train[1] * x))

""" ********** TRAIN - Ordinary Least Squares (OLS) + SQRT Transformation. *********** """
# Multivariate: LSTAT + RM + Log Transformation.
smultilog_model = sm.OLS(y_squared, mX)
smultilog_model = smultilog_model.fit()
smultilog_theta = smultilog_model.params

smultilog_model_train = sm.OLS(y_training_squared, mX_training)
smultilog_model_train = smultilog_model_train.fit()
smultilog_theta_train = smultilog_model_train.params

# Prediction function.
smultilog_prediction = lambda x, y : np.square(smultilog_theta[0] + (smultilog_theta[1] * x) + (smultilog_theta[2] * y))
smultilog_prediction_train = lambda x, y : np.square(smultilog_theta_train[0] + (smultilog_theta_train[1] * x) + (smultilog_theta_train[2] * y))

""" ********************* PLOTS & PREDICTIONS ********************** """
# We need values without the one column for calculating the errors.
X1 = boston['RM'].as_matrix()
# Training data.
x1_training = boston_training['LSTAT'].as_matrix()
x2_training = boston_training['RM'].as_matrix()
# Whole dataset.
X = boston['LSTAT'].as_matrix()
mX_training = boston_training['LSTAT'].as_matrix()

# Prepare plots.
fig, ax = plt.subplots(figsize=(12,8))

# Scatter plot.
ax.scatter(boston['MEDV'], boston['LSTAT'], label='Dataset', color='Cyan')

# Linear model prediction.
f = prediction(boston['LSTAT'])
f_training = prediction_train(x1_training)
f_testing = prediction_train(x1_testing.as_matrix())
# Linear model plot.
x = np.linspace(boston.min()['LSTAT'], boston.max()['MEDV'], N)
ax.plot(x, prediction(x), 'r', label='OLS 100%', color='Green')
ax.plot(x, prediction_train(x), 'r', label='OLS 80%', color='Blue')

# Linear model - Multivariate: LSTAT + RM Prediction.
multif = multi_prediction(boston['LSTAT'], boston['RM'])
multif_training = multi_prediction_train(x1_training, x2_training)
multif_testing = multi_prediction_train(x1_testing, x2_testing)

# Linear model + Log Transformation Prediction.
x = np.linspace(boston.min()['LSTAT'], boston.max()['MEDV'], N)
log_f = log_prediction(boston['LSTAT'])
log_f_training = log_prediction_train(x1_training)
log_f_testing = log_prediction_train(x1_testing)
# Linear model + Log Transformation Plot.
ax.plot(x, log_prediction(x), 'r', label='OLS 100% + Log Transformation', color='Red')

# Linear model + SQRT Transformation Prediction.
x = np.linspace(boston.min()['LSTAT'], boston.max()['MEDV'], N)
squared_f = squared_prediction(boston['LSTAT'])
squared_f_training = squared_prediction_train(x1_training)
squared_f_testing = squared_prediction_train(x1_testing)
# Linear model + Log Transformation Plot.
ax.plot(x, squared_prediction(x), 'r', label='OLS 100% + SQRT Transformation', color='Purple')

# Linear model. Multivariate: LSTAT + RM + Log Transformation.
multilogf = multilog_prediction(boston['LSTAT'], boston['RM'])
multilogf_training = multilog_prediction_train(x1_training, x2_training)
multilogf_testing = multilog_prediction_train(x1_testing, x2_testing)

# Linear model. Multivariate: LSTAT + RM + SQRT Transformation.
smultilogf = smultilog_prediction(boston['LSTAT'], boston['RM'])
smultilogf_training = smultilog_prediction_train(x1_training, x2_training)
smultilogf_testing = smultilog_prediction_train(x1_testing, x2_testing)

# Plot settings.
ax.set_xlabel('LSTAT')
ax.set_ylabel('MEDV')
ax.set_title("MEDV vs LSTAT")
ax.legend()

# Another plot.
fig2, ax2 = plt.subplots(figsize=(12,8))
ax2 = Axes3D(fig2)
# 3D Scatter plot.
ax2.scatter(x1_training, x2_training, y_training, label='Dataset', color='Cyan')
x1 = np.arange(0, 35, 0.5)
x2 = np.arange(4, 10, 0.5)
x1, x2 = np.meshgrid(x1, x2)
z = multi_prediction(x1, x2)
ax2.plot_surface(x1, x2, z, label='Multivariate OLS', color='Green', alpha=0.2)
z = multilog_prediction(x1, x2)
ax2.plot_surface(x1, x2, z, label='Multivariate OLS + Log', color='Red', alpha=0.2)
z = smultilog_prediction(x1, x2)
ax2.plot_surface(x1, x2, z, label='Multivariate OLS + SQRT', color='Purple', alpha=0.2)

# Plot settings.
ax2.set_xlabel('LSTAT')
ax2.set_ylabel('RM')
ax2.set_zlabel('MEDV')
ax2.set_title("MEDV vs RM vs LSTAT")

# Show plot.
# plt.show()

""" ********************* MODEL EVALUATION ********************** """

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


print "\n\n\nRMSE - Root Mean Square Error - Training"
# The less, the better.
# RMSE LINEAR MODEL.
rmse = sqrt(mean_squared_error(y, f))
rmse_train = sqrt(mean_squared_error(y_training, f_training))
rmse_test = sqrt(mean_squared_error(y_testing, f_testing))
print "* Univariate Linear model *"
print "RMSE Training:", rmse_train, "RMSE Testing:", rmse_test, "RMSE All:", rmse

# RMSE LINEAR MODEL + LOG TRANSFORMATION
log_rmse = sqrt(mean_squared_error(y, log_f))
log_rmse_train = sqrt(mean_squared_error(y_training, log_f_training))
log_rmse_test = sqrt(mean_squared_error(y_testing, log_f_testing))
print "\n* Univariate Linear model + Log *"
print "RMSE Training:", log_rmse_train, "RMSE Testing:", log_rmse_test, "RMSE All:", log_rmse

# RMSE LINEAR MODEL + - LOG TRANSFORMATION
squared_rmse = sqrt(mean_squared_error(y, squared_f))
squared_rmse_train = sqrt(mean_squared_error(y_training, squared_f_training))
squared_rmse_test = sqrt(mean_squared_error(y_testing, squared_f_testing))
print "\n* Univariate Linear model + SQRT *"
print "RMSE Training:", squared_rmse_train, "RMSE Testing:", squared_rmse_test, "RMSE All:", squared_rmse

# RMSE MULTIVARIATE
multi_rmse = sqrt(mean_squared_error(y, multif))
multi_RMSE_train = sqrt(mean_squared_error(y_training, multif_training))
multi_RMSE_test = sqrt(mean_squared_error(y_testing, multif_testing))
print "\n* Multivariate model *"
print "RMSE Training:", multi_RMSE_train, "RMSE Testing:", multi_RMSE_test, "RMSE All:", multi_rmse

# RMSE MULTIVARIATE + LOG
multilog_rmse = sqrt(mean_squared_error(y, multilogf))
multilog_RMSE_train = sqrt(mean_squared_error(y_training, multilogf_training))
multilog_RMSE_test = sqrt(mean_squared_error(y_testing, multilogf_testing))
print "\n* Multivariate model + Log *"
print "RMSE Training:", multilog_RMSE_train, "RMSE Testing:", multilog_RMSE_test, "RMSE All:", multilog_rmse

# RMSE MULTIVARIATE + SQRT
smultilog_rmse = sqrt(mean_squared_error(y, smultilogf))
smultilog_RMSE_train = sqrt(mean_squared_error(y_training, smultilogf_training))
smultilog_RMSE_test = sqrt(mean_squared_error(y_testing, smultilogf_testing))
print "\n* Multivariate model + SQRT *"
print "RMSE Training:", smultilog_RMSE_train, "RMSE Testing:", smultilog_RMSE_test, "RMSE All:", smultilog_rmse

print "\n\n* PREDICTION SAMPLES for LSTAT = 4.98 and RM = 6.575 *"
print "Linear univariate         =", model_train.predict([1.00000000e+00, 4.98])
print "Linear univariate + Log   =", np.exp(log_model_train.predict([1.00000000e+00, 4.98]))
print "Linear multivariate       =", multi_model_train.predict([1.00000000e+00, 4.98, 6.575])
print "Linear multivariate + Log =", np.exp(multilog_model_train.predict([1.00000000e+00, 4.98, 6.575]))

# 28.35521125793457
print "\n"