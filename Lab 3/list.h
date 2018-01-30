struct node{
    struct node* next;
    int value;
    void* id;
};
typedef struct node* Node;
struct list{
    Node head;
};
typedef struct list* List;
List createList(int N);
List createCycle(List ls);

