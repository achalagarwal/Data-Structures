#include<stdlib.h>
#include"iterator.h"
int hasMoreElements(Iterator it){
	if(it==NULL)
		return -1;
	if(it->nextIndex+1 <= it->size)
		return 1;
	else return 0;
}

Element getNextElement(Iterator it){
	if(hasMoreElements(it)==1)
		return(it->elements[it->nextIndex++]);
	else
		return NULL;
}

Iterator createIterator(int size){
	Iterator  i = (Iterator)malloc(sizeof(struct iterator));
	i -> elements = (Element*)malloc(sizeof(Element)*size);
	i -> size = size;
	i -> nextIndex = 0;
	return i;
}

void resetIterator(Iterator it){
	if(it!=NULL)
		it->nextIndex = 0;
}

