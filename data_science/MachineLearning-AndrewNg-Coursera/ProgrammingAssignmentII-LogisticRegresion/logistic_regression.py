# Author: Roxana Anabel Lafuente
# Following tutorial: https://github.com/jdwittenauer/ipython-notebooks/blob/master/notebooks/ml/ML-Exercise2.ipynb
# Started on: September 2016

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os
import scipy.optimize as opt

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

def cost(theta, X, y):
    theta = np.matrix(theta)
    X = np.matrix(X)
    y = np.matrix(y)
    first = np.multiply(-y, np.log(sigmoid(X * theta.T)))
    second = np.multiply((1 - y), np.log(1 - sigmoid(X * theta.T)))
    return np.sum(first - second) / (len(X))

def gradient(theta, X, y):
    theta = np.matrix(theta)
    X = np.matrix(X)
    y = np.matrix(y)
    
    parameters = int(theta.ravel().shape[1])
    grad = np.zeros(parameters)
    
    error = sigmoid(X * theta.T) - y
    
    for i in range(parameters):
        term = np.multiply(error, X[:,i])
        grad[i] = np.sum(term) / len(X)
    
    return grad

def predict(theta, X):
    probability = sigmoid(X * theta.T)
    return [1 if x >= 0.5 else 0 for x in probability]

if __name__ == "__main__":
    # Load data.
    path = os.getcwd() + '/data/ex2data1.txt'
    data = pd.read_csv(path, header=None, names=['Exam 1', 'Exam 2', 'Admitted'])

    # Get positive and negative admissions.
    positive = data[data['Admitted'].isin([1])]
    negative = data[data['Admitted'].isin([0])]

    # Scatter plot.
    fig, ax = plt.subplots(figsize=(12,8))
    ax.scatter(positive['Exam 1'], positive['Exam 2'], s=50, c='c', marker='o', label='Admitted')
    ax.scatter(negative['Exam 1'], negative['Exam 2'], s=50, c='r', marker='x', label='Not Admitted')
    ax.set_xlabel('Exam 1 Score')
    ax.set_ylabel('Exam 2 Score')

    # Add a ones column - this makes the matrix multiplication work out easier.
    data.insert(0, 'Ones', 1)

    # Set X (training data) and y (target variable).
    cols = data.shape[1]
    X = data.iloc[:,0:cols-1]
    y = data.iloc[:,cols-1:cols]

    # Convert to numpy arrays and initalize the parameter array theta.
    X = np.array(X.values)
    y = np.array(y.values)
    theta = np.zeros(3)

    # Logistic regression.
    result = opt.fmin_tnc(func=cost, x0=theta, fprime=gradient, args=(X, y))
    theta_min = np.matrix(result[0])
    predictions = predict(theta_min, X)

    # Calculate model accuracy.
    correct = [1 if ((a == 1 and b == 1) or (a == 0 and b == 0)) else 0 for (a, b) in zip(predictions, y)]
    accuracy = (sum(map(int, correct)) % len(correct))
    print 'accuracy = {0}%'.format(accuracy)

    # Plot decision boundary
    x = np.linspace(data['Exam 1'].min(), data['Exam 1'].max(), 100)
    f = (-1./theta_min[0, 2]) * (theta_min[0, 1] * x + theta_min[0, 0])
    ax.plot(x, f, 'r', label='Logistic regression decision boundary', color='Black')
    ax.legend()

    plt.show()