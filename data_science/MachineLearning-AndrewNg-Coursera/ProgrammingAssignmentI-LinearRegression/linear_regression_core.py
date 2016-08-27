# Author: Roxana Anabel Lafuente
# Following tutorial: https://github.com/jdwittenauer/ipython-notebooks/blob/master/notebooks/ml/ML-Exercise1.ipynb
# Started on: August 2016

import os
import numpy
import pandas
import matplotlib.pyplot

def compute_cost(X, y, theta):
    """
    Cost function: least squares.
    
    This evaluates the quality of the model. This is done by
    calculating the error between the model's prediction (using
    the model parameters) and the actual data point.
    """
    term = numpy.power(((X * theta.T) - y), 2)
    return numpy.sum(term) / (2 * len(X))

def gradient_descent(X, y, theta, alpha, iters):
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
        cost[i] = compute_cost(X, y, theta)
        
    return theta, cost