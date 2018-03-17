#include<stdio.h>
#include<stdlib.h>

Btree createBtree(Element e){
    Btree bt = (Btree)malloc(sizeof(struct btree));
    bt->e = e;
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

Btree addBtree(Btree bt, Element e, int k){
    BTree c = bt;
    int i = 0;
    while(c!=NULL){
        if(compare(c->e,e,i,k)<0){
            c = c->left;
        }
        else if(compare(c->e,e,i,k)>0){
            c = c->left;


        
