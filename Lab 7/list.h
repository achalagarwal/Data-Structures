
#define LIST
struct node{
	int a;
	struct node* next;
	};
typedef struct node* Node;
struct list{
	Node head;
	};
typedef struct list* List;
void push(List l, int a);
Node pop(List l);
List createList();

