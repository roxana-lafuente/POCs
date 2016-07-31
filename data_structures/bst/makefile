TARGET = bst
TESTS = tests
CC = g++
FLAGS = -std=c++11
CFLAGS = -c -g
OFLAGS = -o

# TARGETS
all: $(TARGET)
test: $(TESTS)

# RULES
$(TARGET): main.o
	$(CC) main.o $(FLAGS) $(OFLAGS) $(TARGET)

$(TESTS): tests.o
	$(CC) tests.o -I/usr/lib/include -L/usr/lib $(FLAGS) $(OFLAGS) $(TESTS) -lpthread -lgtest -lgtest_main

# DEPENDENCIES
main.o: main.cpp
	$(CC) $(FLAGS) $(CFLAGS) main.cpp bst.h

tests.o: tests.cpp
	$(CC) -I/usr/lib/include -L/usr/lib $(FLAGS) $(CFLAGS) tests.cpp -lpthread -lgtest -lgtest_main

# REMOVE EXECUTABLE, OBJECT AND TEMPORAL FILES
clean:
	rm -f $(TARGET) $(TESTS) *.o *.gch
	clear