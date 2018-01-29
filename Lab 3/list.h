struct node{
    struct node* next;
    int value;
};
typedef struct node* Node;
struct list{
    Node head;
    int value;
};
typedef struct list* List;
List createList(int N);
List createCycle(List ls);

