#include"list.h"
#include<stdlib.h>
#include<stdio.h>
int data = 0;
List global;
int removeFromList( void* id){
    List ls = global;
    Node p = ls->head;
    int v;
    if(p!=NULL){
        if(p->id==id)
            ls->head = p->next;
    }
    else
        return 0;
    Node c = ls->head->next;
    while(c!=NULL){
        if(c->id == id){
            p->next = c->next;
            return c->value;
        }
        p = c;
        c = c->next;
    }
    return 0;
}
void insertFront( int value, void* id){
    if(global == NULL)
        global = (List)malloc(sizeof(struct list));
    List ls = global;
    Node n = (Node)malloc(sizeof(struct node));
    n->value = value;
    n -> id = id;
    n ->next = ls->head;
    ls->head = n;
}
void* myalloc(int m){
    List ls = global;
    void* ptr = malloc(m);
    insertFront(m,ptr);
    data += m;
    return ptr;
}
void myfree(void* ptr){
    List ls = global;
    int v = removeFromList(ptr);
    free(ptr);
    data -= v;
}






