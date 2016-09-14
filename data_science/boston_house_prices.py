from sklearn.datasets import load_boston
import matplotlib.pyplot as plt
import statsmodels.api as sm
import pandas as pd
import numpy

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

# Plot data set.
fig, ax = plt.subplots(figsize=(12,8))

# Linear model.
x = numpy.linspace(boston.min()['LSTAT'], boston.max()['LSTAT'], N)
f = theta[0] + (theta[1] * x)

# Plot linear model.
ax.plot(x, f, 'r', label='Prediction', color='Black')

# Scatter
ax.scatter(boston['MEDV'], boston['LSTAT'], label='Dataset', color='Cyan')
ax.legend(loc=2)

# Set labels.
ax.set_xlabel('LSTAT')
ax.set_ylabel('MEDV')
ax.set_title("MEDV vs LSTAT")

plt.show()

# TODO: - log o log, exp
#       graficar la curva 