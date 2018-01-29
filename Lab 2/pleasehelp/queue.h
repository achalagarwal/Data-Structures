#include<stdio.h>
#include<stdlib.h>
#include"bool.h"
struct element{
    long value;
};
typedef struct element* Element;
struct node{
    struct node* next;
    Element e;
};
typedef struct node* Node;
struct queue{
    Node head;
    Node tail;
};
typedef struct queue* Queue;
Queue newQ();
Boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);
