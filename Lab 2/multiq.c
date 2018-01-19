#include"multiQ.h"
MultiQ createMQ(int num){
	MultiQ* mq = (MultiQ*)malloc(sizeof(MultiQ));
	mq->queues = (Queue*)malloc(sizeof(num*Queue));
	mq->num = num;
	return mq;
}
MultiQ addMQ(MultiQ mq, Task t){
	Task *n = (Task*)malloc(sizeof(Task));
	*n = t;
	
}
