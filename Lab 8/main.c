#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

int getR(){
	return rand()%20+150;
}

Element createElement(){
	Element e = (Element)malloc(sizeof(struct element));
	e->value = getR();
	return e;
}
Bst addElements(Bst b){
	for(int i = 1;i<10000;i++){
		b = addB(b, createElement());
		if(i%100 == 0)
			srand(rand());
	}
	return b;
}

int main(){
	Element e = (Element)malloc(sizeof(struct element));
	e -> value = 160;
	Bst b = create(e);
	b = addElements(b);
	printf(getHeight(b));
	for(int i = 0;i<1000;i++)
		deleteB(b, e);
	printf("done");
}
