# Author: Roxana Anabel Lafuente
# Following tutorial: https://github.com/jdwittenauer/ipython-notebooks/blob/master/notebooks/ml/ML-Exercise1.ipynb
# Started on: August 2016

import os
import numpy
import pandas
import matplotlib.pyplot
from sklearn import linear_model

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

    # Sklearn linear regression.
    model = linear_model.LinearRegression()
    model.fit(X, y)

    # Print parameters.
    print "Coefficients: ", model.coef_

    # Prepare data for printing.
    x = numpy.array(X[:, 1].A1)
    f = model.predict(X).flatten()

    # Plot.
    fig, ax = matplotlib.pyplot.subplots(figsize=(12,8))
    ax.plot(x, f, 'r', label='Prediction', color='Cyan')
    ax.scatter(data.Population, data.Profit, label='Traning Data')
    ax.legend(loc=2)
    ax.set_xlabel('Population')
    ax.set_ylabel('Profit')
    ax.set_title('Predicted Profit vs. Population Size')

    # Show graphics
    matplotlib.pyplot.show()