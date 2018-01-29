#include"queue.h"
Queue newQ(){
    Queue q = (Queue)malloc(sizeof(struct queue));
    q->head =(Node)NULL;
    q->tail = (Node)NULL;
    return q;
}
int lengthQ(Queue q){
    Node curr = q->head;
    int count = 0;
    if(q->tail == NULL)
        return 0;
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
    if(lengthQ(q)==0)
        return q;
    if(lengthQ(q)==1){
        q->head = (Node)NULL;
        q->tail = (Node)NULL;
        return q;
    }
    //else
    q->head = q->head->next;
    return q;
}
Element front(Queue q){
    if(q->head!=NULL)
        return q->head->e;
    else
        return NULL;
}
Queue addQ(Queue q, Element e){
    Node n = (Node)malloc(sizeof(struct node));
    Element el = (Element)malloc(sizeof(struct element));
    n->e = el;
    n->e->value = e->value;
    n->next = (Node)NULL;
    if(lengthQ(q)==0){
        q->head = n;
        q->tail = n;
        return q;
    }
    //else
    q->tail->next = n;
    q->tail = n;
    return q;
}

