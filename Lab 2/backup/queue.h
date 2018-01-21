#include<stdlib.h>
#include"bool.h"
#include"node.h"
typedef struct queue{
        Node* head;
        Node* tail;
}Queue;
Queue newQ();
Boolean isEmptyQ(Queue q);
Queue delQ(Queue q);
Element front(Queue q);
Queue addQ(Queue q, Element e);
int lengthQ(Queue q);

