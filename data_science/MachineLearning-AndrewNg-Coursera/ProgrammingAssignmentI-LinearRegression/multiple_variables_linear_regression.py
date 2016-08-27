# Author: Roxana Anabel Lafuente
# Following tutorial: https://github.com/jdwittenauer/ipython-notebooks/blob/master/notebooks/ml/ML-Exercise1.ipynb
# Started on: August 2016

import os
import numpy
import pandas
import matplotlib.pyplot
from linear_regression_core import compute_cost, gradient_descent

# Path to the data set file.
data_path = '/data/ex1data2.txt'
path = os.getcwd() + data_path

if __name__ == "__main__":
    # Get data from file.
    data = pandas.read_csv(path,
                           header=None,
                           names=['Size', 'Bedrooms', 'Price'])
    # Data normalization.
    data = (data - data.mean()) / data.std()

    # add ones column
    data.insert(0, 'Ones', 1)

    # set X (training data) and y (target variable)
    cols = data.shape[1]
    X = data.iloc[:,0:cols-1]
    y = data.iloc[:,cols-1:cols]

    # convert to matrices and initialize theta
    X = numpy.matrix(X.values)
    y = numpy.matrix(y.values)
    theta = numpy.matrix(numpy.array([0,0,0]))

    # Set alpha and number of iterations.
    alpha = 0.01
    iters = 1000

    # Choose model parameters with gradient descent.
    theta, cost = gradient_descent(X, y, theta, alpha, iters)

    print "Optimal parameters are:", theta[0, 0], "and",
    print theta[0, 1], "and", theta[0, 2]
    print "Regression: ", theta[0, 0], "+", theta[0, 1],
    print "* size +", theta[0, 2], "* bedrooms = price"

    # Plot.
    fig, ax = matplotlib.pyplot.subplots(figsize=(12,8))
    ax.plot(numpy.arange(iters), cost, 'r', color='Cyan')
    matplotlib.pyplot.xlim([0, iters])
    ax.set_xlabel('Iterations')
    ax.set_ylabel('Cost')
    ax.set_title('Error vs. Training Epoch')

    # Show graphics
    matplotlib.pyplot.show()