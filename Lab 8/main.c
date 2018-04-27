#include<stdio.h>
#include<stdlib.h>
#include"BST.h"
int counter = 140;
int getR(){
	return rand()%20+150;
}

Element createElement(){
	Element e = (Element)malloc(sizeof(struct element));
	e->value = counter++;
    if(e->value==160)
        counter=140;
	return e;
}
Bst addElements(Bst b){
	for(int i = 1;i<1000;i++){
		b = addB(b, createElement());
        visualizeBst(b);
        printf("THE I VALUE IS %d",i);
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
//	printf(getHeight(b));
	visualizeBst(b);
    for(int i = 0;i<1000;i++){
	b=deleteB(b, e);
    visualizeBst(b);
    } 
  //  visualizeBst(b);
	printf("done");
}
