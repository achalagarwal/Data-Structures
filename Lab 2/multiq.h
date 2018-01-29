#include"queue.h"
struct taskid{
    long value;
};
struct priority{
    int value;
};
typedef struct taskid* TaskID;
typedef struct priority* Priority;
struct task{
    TaskID tid;
    Priority p;
};
typedef struct task* Task;
struct multiq{
    int num;
    Queue queues;
};
//typedef Task Element;
typedef struct multiq* MultiQ;
MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq);
Task delNextMQ(MultiQ mq);
Boolean isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, Priority p);
Queue getQueueFromMQ(MultiQ mq, Priority p);
