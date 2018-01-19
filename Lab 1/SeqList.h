
#include <stdio.h>
#include <stdlib.h>

typedef struct key{
int value;
}Key;

typedef struct element{
int value;
}Element; 

typedef struct node{
Key k;
Element e;
struct node* next; 
}Node;

typedef struct seqlist{
Node* first;
Node* last;
}SeqList;

SeqList newList();
SeqList insertInOrder(SeqList sl, Element e);
SeqList insertAtFront(SeqList sl, Element e);
SeqList insertAtEnd(SeqList sl, Element e);
SeqList delete(SeqList sl, Element e);
SeqList deleteAtFront(SeqList sl);
Element find(SeqList sl, Key k);

