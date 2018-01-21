typedef struct element{
long value;
}Element;
typedef struct node{
	Element* e;
	struct node* next;
}Node;

