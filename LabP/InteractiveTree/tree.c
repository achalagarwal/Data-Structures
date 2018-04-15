#include"tree.h"
#ifndef LIST_H
#include"list.h"
#endif
#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
Tree createTree(){
    Tree t = (Tree)malloc(sizeof(struct tree));
    t->root = NULL;
    return t;
}

TNode createTNode(int v){
    TNode n = (TNode)malloc(sizeof(struct tnode));
    n->value = v;
    n->l = createList();
    return n;
}

//fill tree assumes that root is empty as its a batch operation

int insertB(TNode n){
    int v;
    while(1){
        scanf("%d",&v);
        if(v==0)
            return 0;
        TNode c = createTNode(v);
        n->l = addElementToBack(n->l,c);
        insertB(c);
    }
}

Tree fillTree(Tree t){
    int v;
    scanf("%d",&v);
    if(v==0)
        return t;
    t->root = createTNode(v);
    insertB(t->root);
    return t;
}

void printNode(){

}
void printTree(Tree t){
    Queue q = createQ();
    pushQ(q,t->root->l);
    printf("%d\n",t->root->value);
    while(getQ(q)!=NULL){
        List c = (List)getQ(q);
       // pushQ(getElementFront(l)->l);
        int flag = 0;
        while(isEmpty(c)==0){
            printf("%d,",getElementFront(c)->value);
            pushQ(q,getElementFront(c)->l);
            removeElementFromFront(c);
            flag=1;
        }
        if(flag == 1)
        printf("\n");
        popQ(q);
    }
}

int main(){
    Tree t = createTree();
    fillTree(t);
    printTree(t);
    printf("Wow");
}
