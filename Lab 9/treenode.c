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
    t->r = (Record)malloc(sizeof(struct record));
    for(int i = 0;i<children;i++){
        t->i->elements[i] = createTNode(0);
    }

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
        child->r->value = getRandom(99);
		helperCST(child, bound, remLevels-1);
	}
    resetIterator(i);
}

Tree createSpecificTree(int bound){
	Tree t = createTree(0);
	helperCST(t->root,bound,3);
	return t;
}

TNode selectNextNode(Tree t){
    if(t==NULL)
        return NULL;
    return getNextElement((Iterator)(getElementFront(t->currentSet)));
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

TNode bfsT(Tree n){
 //   Tree n  = createSpecificTree(3);
    if(isEmpty(n->currentSet)==1){
    Iterator i = identifyMoreNodes(n->root);
    addMoreNodesBFS(n->currentSet, i);
    }
    while(isEmpty(n->currentSet)==0){
        TNode t = selectNextNode(n);
        if(t!=NULL){

            printf("%d  ",t->r->value);
            addMoreNodesBFS(n->currentSet,identifyMoreNodes(t));
            return t;
        }
        else{    
            resetIterator(getElementFront(n->currentSet));
            removeElementFromFront(n->currentSet);
            printf("\n");
            fflush(NULL);
        }
    }
    return NULL;
}
int main(){
	Tree n = createSpecificTree(10);
    TNode t;

    do{
        t = bfsT(n);//   printf("%d\n",t->r->value);
    }
	while(t!=NULL);
    printf("done");
}
