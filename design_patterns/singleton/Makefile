# @file   makefile
# @Author Roxana Anabel Lafuente (roxana.lafuente@gmail.com)
# @date   August, 2016
# @brief  Singleton Makefile.

CC = g++
CFLAGS = -c
FLAGS = -std=c++11 -g -Wall
TARGET = singleton
RM = rm

# Target
all: $(TARGET)

# Rule
$(TARGET): main.o
	$(CC) main.o $(FLAGS) -o $(TARGET)

# Dependencies
main.o: main.cpp
	$(CC) $(FLAGS) $(CFLAGS) main.cpp singleton.h

clean:
	$(RM) -f $(TARGET) *.o *.gch
	clear