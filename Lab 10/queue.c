#include<stdlib.h>
#include"queue.h"

Q createQ(){
    Q q = (Q)malloc(sizeof(struct queue));
    q -> head = NULL;
    q -> tail = NULL;
    return q;
}

int isEmpty(Q q){
    if(q->head == NULL)
        return 1;
    else
        return 0;
}

QElement getQElement(Q q){
    if(q==NULL)
        return NULL;
    return q->head->e;
}

QNode createQNode(QElement e){
    QNode n = (QNode)malloc(sizeof(struct qnode));
    n ->e = e;
    n->next = NULL;
    return n;
}


Q pushQ(Q q, QElement e){
    QNode n = createQNode(e);
    if(q == NULL)
        return NULL;
    if(isEmpty(q)==1){
        q -> head = n;
        q -> tail = n;
        return q;
    }
    q->tail->next = n;
    q->tail = n;
    return q;
}

Q popQ(Q q){
    if(q==NULL)
        return NULL;
    if(q->head == q->tail){
        q->head = NULL;
        q->tail = NULL;
        return q;
    }
    QNode t = q->head;
    q->head = t->next;
    free(t);
    return q;
}

