TARGET = a
TESTS = tests
CC = g++
FLAGS = -std=c++11
CFLAGS = -c
OFLAGS = -o

all: $(TARGET)

test: $(TESTS)

$(TARGET): tests.o
	$(CC) $(FLAGS) $(OFLAGS) $(TARGET) main.o

$(TESTS): tests.o main.o
	$(CC) $(OFLAGS) $(TESTS) /usr/lib/libgtest.a /usr/lib/libgtest_main.a -lgtest -lpthread

main.o: main.cpp
	$(CC) $(CFLAGS) $(FLAGS) main.cpp bst.h

tests.o: tests.cpp
	$(CC) /usr/lib/libgtest.a /usr/lib/libgtest_main.a -std=c++11 $(CFLAGS) tests.cpp -lpthread -lgtest -lgtest_main

clean:
	rm -f $(TARGET) $(TESTS) *.o *.gch
	clear