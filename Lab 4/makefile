compile : list.o memory.o qsort.o read.o
	gcc -g memory.o list.o qsort.o read.o 
list.o : list.h list.c
	gcc -c -g list.c
memory.o : memory.h memory.c
	gcc -c -g memory.c
read.o : read.c
	gcc -c -g read.c
qsort.o : qsort.h qsort.c
	gcc -g qsort.c -c
