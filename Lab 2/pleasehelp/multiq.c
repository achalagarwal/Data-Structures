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
    addQ(&mq->queues[p-1],e);
    return mq;
}
Task nextMQ(MultiQ mq){
    int num = mq->num;
    Task t = (Task)malloc(sizeof(struct task));
    Priority p = (Priority)malloc(sizeof(struct priority));
    TaskID tid = (TaskID)malloc(sizeof(struct taskid));
    t->p = p;
    t->tid = tid;
    for(int i = 0;i<num;i++){
        if(isEmptyQ(&mq->queues[i])==false){
            t->p->value = i+1;
            t->tid->value = front(&mq->queues[i])->value;
            return t;
        }
    }
    //else
    return NULL;
}
Task delNextMQ(MultiQ mq){
    int num = mq->num;
    Task t = (Task)malloc(sizeof(struct task));
    Priority p = (Priority)malloc(sizeof(struct priority));
    TaskID tid = (TaskID)malloc(sizeof(struct taskid));
    t->p = p;
    t->tid = tid;
    for(int i = 0;i<num;i++){
        if(isEmptyQ(&mq->queues[i])==false){
            t->p->value = i+1;
            t->tid->value = front(&mq->queues[i])->value;
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
        if(isEmptyQ(&mq->queues[i])==false)
            return false;
    }
    //else
    return true;
}
int sizeMQ(MultiQ mq){
    int num = mq->num;
    int count = 0;
    for(int i=0;i<num;i++){
        count+=lengthQ(&mq->queues[i]);
    }
    return count;
}
int sizeMQbyPriority(MultiQ mq, Priority p){
    //using int value of priority
    int pr = p->value;
    return lengthQ(&mq->queues[pr-1]);
}
Queue getQueueFromMQ(MultiQ mq, Priority p){
    //using int value of priority
    return &mq->queues[p->value];
}





