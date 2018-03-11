#include<stdlib.h>

Queue createQ(int size){
    if(size<=0)
        return NULL;
    Queue q = (Queue)malloc(sizeof(struct queue));
    q -> size = size;
    q -> head = NULL;
    q -> tail = NULL;
    return q;
}

Queue pop(Queue q){
    if(q -> tail == NULL)
        return q;
    Node n = q->tail->next;
    free(q->tail);
    q -> tail = n;
    return q;
}

Queue pushHead(Queue q, Node n){
    q -> head -> next = n;
    q -> head = n;
    return q;
}

Node popHead(Queue q){
    if(q -> head ==  NULL)
        return;
    
    Node n = q -> head;
    q -> head = q -> head -> prev;
    return n;
}

Queue push(Queue q, Node new){
  
    //search for element
    
    Node n = q -> head;

    if(n->value == new->value)
        return q;

    Node p = n;
    n = n->prev;

    while(n != NULL){
        if(n->value == new->value){
            p -> next = n -> next;
            n -> next = q -> first;
            q -> first = n;
            return q;
        }
        p = n;
        n = n->prev;
    }

    if(q->capacity > 0){
        new -> next = q -> first;
        q -> first = new;
    }

    if(q -> capacity == 0){


