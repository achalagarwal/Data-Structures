#define LIST_H
#ifndef ELEMENT
#define ELEMENT
#define ELEMENT_B
struct element;
typedef struct element* Element;
struct element{
    char* value;
    int key;
};
#endif
struct node;
typedef struct node* Node;
struct node{
    Element e;
    Node next;
};

struct list;
typedef struct list* List;
struct list{
    Node head;
    int count;
};


List addToList(List l, Node n);
List addEToList(List l, Element e);
void deleteFromList(List n, Element e);
List createList();


