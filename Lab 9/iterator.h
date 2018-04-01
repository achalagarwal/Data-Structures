#define ITERATOR_H 
#ifndef ITERATOR_ELEMENT_H
struct element{
    int value;
};
typedef struct element* Element;
#define ITERATOR_ELEMENT_H 
#endif
//struct iterator;
//typedef struct iterator* Iterator;
struct iterator{
	Element* elements;
	int size;
	int nextIndex;
};

typedef struct iterator* Iterator;

int hasMoreElements(Iterator it);
Element getNextElement(Iterator it);
Iterator createIterator(int size);

