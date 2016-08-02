# BST - Binary Search Tree

## How to run in Linux:
- make clean; make; ./bst

## How to install Google Test:

### Get source code
- Please get the latest version on https://github.com/google/googletest
- Go to the folder where you downloaded the code

### Build Google test

````
sudo apt-get install cmake
cd HERE_GOES_THE_FOLDER_PATH_WHERE_YOU_DOWNLOADED_THE_CODE/googletest
cmake -DBUILD_SHARED_LIBS=ON -Dgtest_build_samples=ON -Dgtest_build_tests=ON .
make
````

### Check Google test is installed correctly
````
make test
````
You should see the following output: "100% tests passed, 0 tests failed out of 41"

### Copy headers and libs to the system
Try:
````
ls
````
If you do not see the *.a, then try and look for the appropriate file:

````
find . -name "libgtest.a"
cd to the file where the .a are
````
Then just copy them:
````
sudo cp -a include/gtest /usr/include
sudo cp -a libgtest_main.so libgtest.so /usr/lib/
````

### Check the linker knows the libs
````
sudo ldconfig -v | grep gtest
````


## How to run the test suite:
- make clean; tests; ./tests

## Supported platforms:
- Linux (Ubuntu / Debian).

## Project Status:
- In progress.
