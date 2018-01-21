#include"multiq.h"
MultiQ createMQ(int num){
    MultiQ mq = (MultiQ)malloc(sizeof(struct multiq));
    mq->num = num;
    mq->queues = (Queue)malloc(num*(sizeof(struct queue)));
    return mq;
}
MultiQ addMQ(MultiQ mq, Task t){
    //using priority int value
    int p = t->p->value;
    Element e = (Element)malloc(sizeof(struct element));
    e->value = t->tid->value;
    addQ(mq->queues+(p-1)*sizeof(struct queue),e);
    return mq;
}
Task nextMQ(MultiQ mq){
    int num = mq->num;
    Task t = (Task)malloc(sizeof(struct task));
    for(int i = 0;i<num;i++){
        if(isEmptyQ(mq->queues+i*sizeof(struct queue))==false){
            t->p->value = i+1;
            t->tid->value = front(mq->queues+i*sizeof(struct queue))->value;
            return t;
        }
    }
    //else
    return NULL;
}
Task delNextMQ(MultiQ mq){
    int num = mq->num;
    Task t = (Task)malloc(sizeof(struct task));
    for(int i = 0;i<num;i++){
        if(isEmptyQ(mq->queues+i*sizeof(struct queue))==false){
            t->p->value = i+1;
            t->tid->value = front(mq->queues+i*sizeof(struct queue))->value;
            delQ(mq->queues+i*sizeof(struct queue));
            return t;
        }
    }
    //else
    return NULL;
}
Boolean isEmptyMQ(MultiQ mq){
    int num = mq->num;
    for(int i=0;i<num;i++){
        if(isEmptyQ(mq->queues+i*sizeof(struct queue))==false)
            return false;
    }
    //else
    return true;
}
int sizeMQ(MultiQ mq){
    int num = mq->num;
    int count = 0;
    for(int i=0;i<num;i++){
        count+=lengthQ(mq->queues+i*sizeof(struct queue));
    }
    return count;
}
int sizeMQbyPriority(MultiQ mq, Priority p){
    //using int value of priority
    int pr = p->value;
    return lengthQ(mq->queues+(pr-1)*sizeof(struct queue));
}
Queue getQueueFromMQ(MultiQ mq, Priority p){
    //using int value of priority
    return mq->queues+(p->value)*sizeof(struct queue);
}





