TARGET = a
CC = g++
FLAGS = -std=c++11
CFLAGS = -c
OFLAGS = -o

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(FLAGS) $(OFLAGS) $(TARGET) main.o

main.o: main.cpp
	$(CC) $(CFLAGS) $(FLAGS) main.cpp bst.h

clean:
	clear
	rm -f $(TARGET) *.o *.gch *~
