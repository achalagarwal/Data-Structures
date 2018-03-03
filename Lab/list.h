#define DEFINITIONS
struct node{
	int key; //cgpa
	char name[10];
	struct node* next;
};
typedef struct node* Node;

struct list{
	Node head;
};
typedef struct list* List;
struct element{
	float key;
	char name[10];
};
typedef struct element* Element;
