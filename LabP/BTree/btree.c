#include<stdio.h>
#include<stdlib.h>

//Utility Function compares string

int compare(char* a,char* b){
    
}




Btree createBtree(Element e){
    Btree bt = (Btree)malloc(sizeof(struct btree));
    bt->e = e;
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

Btree addBtree(Btree bt, Element e, int k){
    BTree c = bt;
    BTree new = createBtree(e);
    int i = 0;
    while(c!=NULL){
        if(compare(c->e,e,i,k)<0){
            if(c->left == NULL){
                c->left = new;
                return bt;
            }
            //else
            c = c->left;
        }
        else if(compare(c->e->key,e->key,i,k)>0){
            if(c->right==NULL){
                c->right = new;
                return bt;
            }
            //else
            c = c->right;
        }
        //last case is equality
        else{
            c->e = e; //replacing incase meta data added later on
            return bt;
        }
    }
}

char* getValue(Btree bt,char* key,int k){
    while(bt!=NULL){
        if(compare(bt->e->key,key)<0){
            bt = bt->right;
        }
        else if(compare(bt->e->key,key)>0){
            bt = bt->left;
        }
        //last option is equality
        else{
            return bt->e->value;
        }
    }
    return NULL;
}

