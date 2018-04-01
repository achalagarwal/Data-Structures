#include<stdio.h>
#include<stdlib.h>
#include"treenode.h"
#ifndef ITERATOR_H
#include"iterator.h"
//printf("d");
#endif

TNode createTNode(int children){
	TNode t = (TNode)malloc(sizeof(struct treenode));
	t->i = createIterator(children);
    for(int i = 0;i<children;i++){
        t->i->elements[i] = createTNode(0);
    }
	t->r = NULL;

	return t;
}


Tree createTree(int children){
	Tree t = (Tree)malloc(sizeof(struct tree));
	TNode root  = createTNode(children);
	t->root = root;
	return t;
}

void resetChildren(TNode t, int c){
	t->i = createIterator(c);
    for(int i = 0;i<c;i++){
        t->i->elements[i] = createTNode(0);
    }
}

int getRandom(int bound){
	srand(rand());
	return rand()%bound;
}
void helperCST(TNode t, int bound, int remLevels){
	if(remLevels ==0)
		return;
	resetChildren(t,getRandom(bound));
	Iterator i = t->i;
	while(hasMoreElements(i)==1){
		TNode child = (TNode)getNextElement(i);
		helperCST(child, bound, remLevels-1);
	}
}

Tree createSpecificTree(int bound){
	Tree t = createTree(0);
	helperCST(t->root,bound,5);
	return t;
}

int main(){
	createSpecificTree(10);
	printf("done");
}
