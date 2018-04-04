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
    t->currentSet = createList();
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

TNode selectNextNode(Tree t){
    if(t==NULL)
        return NULL;
    return getNextElement((getElementFront(t->currentSet)));
}

Iterator identifyMoreNodes(TNode n){
    return n->i;
}


void addMoreNodesBFS(List set,Iterator i){
    addElementToBack(set,i);
}

void addMoreNodesDFS(List set, Iterator i){
    addElementToFront(set,i);
}

void test(){
    Tree n  = createSpecificTree(5);
    Iterator i = identifyMoreNodes(n->root);
    addMoreNodesBFS(n->currentSet, i);
    while(isEmpty(n->currentSet)==0){
        TNode t = selectNextNode
    }
}
int main(){
	createSpecificTree(10);
	printf("done");
}
