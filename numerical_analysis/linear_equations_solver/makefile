COMPILER = gcc
FLAGS_C = -c -Wall -pedantic -std=c99 -lm -g
FLAGS_O = -Wall -pedantic -std=c99 -lm -g -o
EXE = linear_equation_solver


$(EXE): functions.o read_file.o main.o
	$(COMPILER) $(FLAGS_O) $(EXE) functions.o read_file.o main.o

functions.o: functions.c
	$(COMPILER) $(FLAGS_C) functions.h functions.c

read_file.o: read_file.c
	$(COMPILER) $(FLAGS_C) read_file.h read_file.c

main.o: main.c
	$(COMPILER) $(FLAGS_C) main.c

clean:
	rm -f $(EXE) *.o *.gch *~
	clear