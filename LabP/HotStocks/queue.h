struct node;
typedef struct node* Node;
struct queue;
typedef struct queue* Queue;

struct queue{
    Node head;
    Node tail;
    int capacity;
};

struct node{
    Node next;
    Node prev;
    int value;
};

Queue create(int size);
Queue push(Queue q, Node n);
Queue pop(Queue q);

