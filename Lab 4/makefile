compile : list.o memory.o qsort.o read.o
	gcc -g -pg memory.o list.o qsort.o read.o 
list.o : list.h list.c
	gcc -c -g -pg list.c
memory.o : memory.h memory.c
	gcc -c -g -pg memory.c
read.o : read.c 
	gcc -c -g -pg read.c
qsort.o : qsort.h qsort.c
	gcc -g qsort.c -pg -c
