typedef struct element{
	int value;
}Element;
typedef struct node{
	Element* e;
	struct node* next;
}Node;

