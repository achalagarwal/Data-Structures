#define QUEUE_H

#ifndef QUEUE_ELEMENT_H
#define QUEUE_ELEMENT_H
struct qelement;
typedef struct qelement* QElement;
struct qelement {
    int value;
};
#endif
struct qnode;
typedef struct qnode* QNode;
struct qnode{
    QElement e ;
    QNode next;
};

struct queue;
typedef struct queue* Q;

struct queue{
    QNode head;
    QNode tail;
};


//List addElementToFront(List s,LElement e);
Q pushQ(Q q, QElement e);
Q popQ(Q q);
//List removeElementFromBack(List s);
QElement getQ(Q q);
//LElement getElementBack(List s);
Q createQ();
int isEmpty(Q q);
