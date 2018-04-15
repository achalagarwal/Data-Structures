#define LIST_H
#ifdef LIST_ELEMENT_H
struct list_node;
typedef struct list_node* Node;
struct list_node{
    LElement e;
    Node next;
};
#endif
#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H
struct list_element;
typedef struct element* LElement;
struct element {
    int value;
};
struct list_node;
typedef struct list_node* Node;
struct list_node{
    LElement e ;
    Node next;
};
#endif

struct list;
typedef struct list* List;

struct list{
    Node head;
    Node tail;
};


List addElementToFront(List s,LElement e);
List addElementToBack(List s, LElement e);
List removeElementFromFront(List s);
//List removeElementFromBack(List s);
LElement getElementFront(List s);
LElement getElementBack(List s);
List createList();
int isEmpty(List s);
