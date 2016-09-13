# Author: Roxana Anabel Lafuente
# Started on: September 2016

import pandas
import os
import numpy

# Path to the data set file.
data_path = '/MachineLearning-AndrewNg-Coursera/ProgrammingAssignmentI-LinearRegression/data/ex1data1.txt'
path = os.getcwd() + data_path

if __name__ == "__main__":
    # Get data from file.
    data = pandas.read_csv(path,
                       header=None,
                       names=['Population', 'Profit'])
    # Set X (training data) - Ones and Population.
    cols = data.shape[1]
    x = data.iloc[:,0:cols-1]
    x = numpy.matrix(x.values)
    x = [int(j[0]) for j in x]

    # Set y (target variable) - profit.
    y = data.iloc[:,cols-1:cols]
    y = numpy.matrix(y.values)
    y = [int(j[0]) for j in y]

    # Calculate correlation
    print "r = ", numpy.corrcoef(x, y)[0][1]