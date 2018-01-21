#include"queue.h"
Queue newQ(){
    Queue q = (struct queue*)malloc(sizeof(struct queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}
int lengthQ(Queue q){
    Node curr = q->head;
    int count = 0;
    while(curr!=NULL){
        count++;
        curr = curr->next;
    }
    return count;
}
Boolean isEmptyQ(Queue q){
    if(q->head == NULL)
        return true;
    else
        return false;
}
Queue delQ(Queue q){
    if(lengthQ(q)==1){
        q->head = NULL;
        q->tail = NULL;
        return q;
    }
    //else
    q->head = q->head->next;
    return q;
}
Element front(Queue q){
    return q->head->e;
}
Queue addQ(Queue q, Element e){
    Node n = (Node)malloc(sizeof(struct node));
    n->e = e;
    n->next = NULL;
    if(lengthQ(q)==0){
        q->head = n;
        q->tail = n;
        return q;
    }
    //else
    n->next = q->head;
    q->head = n;
    return q;
}

