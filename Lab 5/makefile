default: run
	./a.out
run: merge.o mergesort.o read.c
	gcc -g merge.o mergesort.o read.c
merge.o: merge.c merge.h
	gcc -g -c merge.c
mergesort.o: mergesort.h mergesort.c
	gcc -g -c mergesort.c
