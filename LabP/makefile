compile: filter.o hash.o 
	gcc filter.o hash.o main.c
filter.o:
	gcc filter.c -c
hash.o:
	gcc hash.c -c
debug: dfilter dhash
	gcc filter.o hash.o main.c -g
dfilter:
	gcc filter.c -c -g
dhash:
	gcc hash.c -c -g
