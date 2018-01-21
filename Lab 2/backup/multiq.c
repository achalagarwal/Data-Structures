#include"multiq.h"
MultiQ createMQ(int num){
	MultiQ* mq = (MultiQ*)malloc(sizeof(MultiQ));
	mq->queues = (Queue*)malloc(num*sizeof(Queue));
	mq->num = num;
	return *mq;
}
MultiQ addMQ(MultiQ mq, Task t){
	Element* e = (Element*)malloc(sizeof(Element));
    int p = t.p->value;
    long id = t.tid->value;
    e->value = id;
    mq.queues[p-1] = addQ(mq.queues[p-1],*e);
    return mq;
}
Task nextMQ(MultiQ mq){
    Task* t = (Task*)malloc(sizeof(Task));
    int n = mq.num;
    for(int i = 0;i<n;i++){
        Element e = front(mq.queues[i]);
        if(e.value != -999){
            t->tid->value = e.value;
            t->p->value = i+1;
            return *t;
        }
    }
    t->p->value = -1;
    t->tid->value = -999;
    return *t;
}
Task delNextMQ(MultiQ mq){
    Task* t = (Task*)malloc(sizeof(Task));
    int n = mq.num;
    for(int i = 0;i<n;i++){
        Element e = front(mq.queues[i]);
        if(e.value != -999){
            mq.queues[i] = delQ(mq.queues[i]);
            t->tid->value = e.value;
            t->p->value = i+1;
            return *t;
        }
    }
    t->p->value = -1;
    t->tid->value = -999;
    return *t;
}
Boolean isEmptyMQ(MultiQ mq){
    int n = mq.num;
    for(int i = 0;i<n;i++){
        Element e = front(mq.queues[i]);
        if(e.value!=-999)
            return false;
    }
    return true;
}
int sizeMQ(MultiQ mq){
    int n = mq.num;
    int l = 0;
    for(int i = 0;i<n;i++){
        l+=lengthQ(mq.queues[i]);
    }
    return l;
}
int sizeMQbyPriority(MultiQ mq, Priority p){
    return lengthQ(mq.queues[p.value-1]);
}
Queue getQueueFromMQ(MultiQ mq, Priority p){
    return mq.queues[p.value-1];
}







