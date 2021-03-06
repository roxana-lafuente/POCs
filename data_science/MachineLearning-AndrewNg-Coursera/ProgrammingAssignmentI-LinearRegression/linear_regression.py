# Author: Roxana Anabel Lafuente
# Following tutorial: https://github.com/jdwittenauer/ipython-notebooks/blob/master/notebooks/ml/ML-Exercise1.ipynb
# Started on: August 2016

import os
import numpy
import pandas
import matplotlib.pyplot
from linear_regression_core import gradient_descent

# Path to the data set file.
data_path = '/data/ex1data1.txt'
path = os.getcwd() + data_path

if __name__ == "__main__":
    # Get data from file.
    data = pandas.read_csv(path,
                       header=None,
                       names=['Population', 'Profit'])

    # Insert ones.
    data.insert(0, 'Ones', 1)

    # Set X (training data) - Ones and Population.
    cols = data.shape[1]
    X = data.iloc[:,0:cols-1]
    X = numpy.matrix(X.values)

    # Set y (target variable) - profit.
    y = data.iloc[:,cols-1:cols]
    y = numpy.matrix(y.values)
    theta = numpy.matrix(numpy.array([0,0]))

    # Set alpha and number of iterations.
    alpha = 0.01
    iters = 1000

    # Choose model parameters with gradient descent.
    theta, cost = gradient_descent(X, y, theta, alpha, iters)

    # Linear model data preparation for plotting.
    x = numpy.linspace(data.Population.min(), data.Population.max(), 100)
    f = theta[0, 0] + (theta[0, 1] * x)
    print "Optimal parameters are:", theta[0, 0], "and", theta[0, 1]
    print "Regression: ", theta[0, 0], "+", theta[0, 1], "* population = profit"

    # Plot linear model.
    fig, ax = matplotlib.pyplot.subplots(figsize=(12,8))
    ax.plot(x, f, 'r', label='Prediction', color='Cyan')

    # Plot data set.
    ax.scatter(data.Population, data.Profit, label='Training Data')
    ax.legend(loc=2)

    # Set labels.
    ax.set_xlabel('Population')
    ax.set_ylabel('Profit')
    ax.set_title('Predicted Profit vs. Population Size')

    # Plotting cost function - Should decrease on each iteration (convergence).
    fig, ax = matplotlib.pyplot.subplots(figsize=(12,8))
    ax.plot(numpy.arange(iters), cost, 'r', color='Cyan')
    matplotlib.pyplot.xlim([0, iters])
    ax.set_xlabel('Iterations')
    ax.set_ylabel('Cost')
    ax.set_title('Error vs. Training Epoch')

    # Show graphics
    matplotlib.pyplot.show()