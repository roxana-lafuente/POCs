# Author: Roxana Anabel Lafuente
# Following tutorial: https://github.com/jdwittenauer/ipython-notebooks/blob/master/notebooks/ml/ML-Exercise1.ipynb
# Started on: August 2016

import os
import numpy
import pandas
import matplotlib.pyplot

# Path to the data set file.
data_path = '/data/ex1data1.txt'
path = os.getcwd() + data_path

def computeCost(X, y, theta):
    """
    Cost function: least squares.
    
    This evaluates the quality of the model. This is done by
    calculating the error between the model's prediction (using
    the model parameters) and the actual data point.
    """
    term = numpy.power(((X * theta.T) - y), 2)
    return numpy.sum(term) / (2 * len(X))

def gradientDescent(X, y, theta, alpha, iters):
    """
    Optimization function: Gradient Descent.

    It is used to find the optimal parameters for a linear model.
    Given a function defined by a set of parameters, the algorithm
    starts with an initial set of parameters and iteratively moves
    toward a set of parameter values that minimize the function, ie,
    a local minimum.
    """
    temp = numpy.matrix(numpy.zeros(theta.shape))
    parameters = int(theta.ravel().shape[1])
    cost = numpy.zeros(iters)
    
    for i in range(iters):
        error = (X * theta.T) - y
        
        for j in range(parameters):
            term = numpy.multiply(error, X[:,j])
            temp[0,j] = theta[0,j] - ((alpha / len(X)) * numpy.sum(term))
            
        theta = temp
        cost[i] = computeCost(X, y, theta)
        
    return theta, cost


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
    theta, cost = gradientDescent(X, y, theta, alpha, iters)

    # Linear model.
    x = numpy.linspace(data.Population.min(), data.Population.max(), 100)
    f = theta[0, 0] + (theta[0, 1] * x)
    print "Optimal parameters are:", theta[0, 0], "and", theta[0, 1]
    print "Regression: ", theta[0, 0], "+", theta[0, 1], "* x"

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

    # Show graphics
    matplotlib.pyplot.show()