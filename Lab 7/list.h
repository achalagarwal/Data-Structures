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

Node addToList(Node n, Element e);
Node deleteFromList(Node n, Element e);
Node createList(Element e);


