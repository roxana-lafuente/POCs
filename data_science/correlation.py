# Author: Roxana Anabel Lafuente
# Started on: September 2016

import pandas
import os
import numpy

# Path to the data set file.
data_path = '/MachineLearning-AndrewNg-Coursera/ProgrammingAssignmentI-LinearRegression/data/ex1data1.txt'
path = os.getcwd() + data_path

"""
CORRELATION:
Given n numerical pairs (x1, y1), ..., (xn, yn):
- x and y have a positive relationship if large x’s are paired with large y’s
and small x’s with small y’s. 
- if large x’s are paired with small y’s and small x’s with large y’s, then a
negative relationship between the variables is implied.
"""

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
    """
    Sample correlation coefficient (r): it measures the degree of linear
    relationship among variables.

    === Properties ===
        1. The value of r does not depend on which of the two variables under study
    is labeled x and which is labeled y.
        2. The value of r is independent of the units in which x and y are measured.
        3. -1 <= r <= 1
        4. r = 1 if and only if all (xi, yi) pairs lie on a straight line with
    positive slope, and r = -1 iff all (xi, yi) pairs lie on a straight line
    with negative slope.
        5. The square of the sample correlation coefficient gives the value of the
    coefficient of determination that would result from fitting the simple
    linear regression model; in symbols (r)^2 = r^2.

    === Interpreting r ===
        - Weak: -.5 <= r <= .5
        - Moderate: -.8 < r <-.5 or .5 < r < .8
        - Strong: r>=.8 or r<=-.8
    """
    print "r = ", numpy.corrcoef(x, y)[0][1]