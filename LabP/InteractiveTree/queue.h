

struct qnode{
    void* e;
    struct qnode* next;
};
typedef struct qnode* QNode;

struct queue;
typedef struct queue* Queue;

struct queue{
    QNode head;
    QNode tail;
};

Queue pushQ(Queue q,void* e);
Queue popQ(Queue q);
Queue createQ();
void* getQ(Queue q);
