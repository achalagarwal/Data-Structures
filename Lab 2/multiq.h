#include"task.h"
typedef struct multiq{
	int num;
	Queue* queues;
}MultiQ;
MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Tast t);
Task nextMQ(MultiQ mq);
Task delNextMQ(MultiQ mq);
Boolean isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ, Priority p);

