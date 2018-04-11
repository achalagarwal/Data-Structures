#include<stdlib.h>
#include"list.h"

List createList(){
    List l = (List)malloc(sizeof(struct list));
    l -> head = NULL;
    l -> tail = NULL;
    return l;
}

int isEmpty(List s){
    if(s->head == NULL)
        return 1;
    else
        return 0;
}

LElement getElementFront(List s){
    if(s==NULL)
        return NULL;
    return s->head->e;
}

LElement getElementBack(List s){
    if(s==NULL)
        return NULL;
    return s->tail->e;
}

Node createNode(LElement e){
    Node n = (Node)malloc(sizeof(struct list_node));
    n ->e = e;
    n->next = NULL;
    return n;
}

List addElementToFront(List s,LElement e){
    Node n = createNode(e);
    if(s == NULL)
        return NULL;
    if(isEmpty(s)==1){
        s -> head = n;
        s -> tail = n;
        return s;
    }
    n->next = s->head;
    s->head = n;
    return s;
}

List addElementToBack(List s, LElement e){
    Node n = createNode(e);
    if(s == NULL)
        return NULL;
    if(isEmpty(s)==1){
        s -> head = n;
        s -> tail = n;
        return s;
    }
    s->tail->next = n;
    s->tail = n;
    return s;
}

List removeElementFromFront(List s){
    if(s==NULL)
        return NULL;
    if(s->head == s->tail){
        s->head = NULL;
        s->tail = NULL;
        return s;
    }
    Node t = s->head;
    s->head = t->next;
    free(t);
    return s;
}


