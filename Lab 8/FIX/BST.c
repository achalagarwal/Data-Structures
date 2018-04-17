#include"BST.h"
#ifndef STACK_H
#include"stack.h"
#endif
#include<stdlib.h>

BST createBST(int (*f)(void*,void*)){
    BST b = (BST)malloc(sizeof(struct bst));
    b -> root = NULL;
    b -> size = 0;
    b -> f = f;
    return b;
}

BNode createBNode(void* e){
    BNode n = (BNode)malloc(sizeof(struct bnode));
    n -> left = NULL;
    n -> right = NULL;
    n -> e = e;
    n -> height = 0;
    return n;
}

int getHeight(BNode b){
    if(b==NULL)
        return -1;
    return b->height;
}

void setHeight(BNode b){

    b->height = getHeight(b->left)>getHeight(b->right)?1+getHeight(b->left):1+getHeight(b->right);

}

BST insertInBST(BST b,void* e){
    Stack s = createStack();
    BNode n = createBNode(e);
    addToStack(s,e);
    
}

