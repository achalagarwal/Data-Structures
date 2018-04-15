#include<stdlib.h>
#include"queue.h"

QNode createQNode(void* e){
    QNode qn = (QNode)malloc(sizeof(struct qnode));
    qn -> e = e;
    qn->next = NULL;
    return qn;
}

Queue pushQ(Queue q, void* e){
    if(q->head == NULL){
        //q->tail == NULL
        q->head = createQNode(e);
        q->tail = q->head;
        return q;
    }
    //else
    QNode qn = createQNode(e);
    q->tail->next = qn;
    q->tail = qn;
    return q;
}
Queue popQ(Queue q){
    if(q->tail == NULL)
        return NULL;
    if(q->head == q->tail){
        q->head = NULL;
        q->tail = NULL;
        return q;
    }
    q->head = q->head->next;
    return q;
}

void* getQ(Queue q){
    if(q->head == NULL)
        return NULL;
    return q->head->e;
}

Queue createQ(){
    Queue q = (Queue)malloc(sizeof(struct queue));
    q-> head = NULL;
    q->tail = NULL;
    return q;
}
