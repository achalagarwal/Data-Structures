#include "List.h"
int globalCounter=0;
List createList(Student array, int size){
	List list = (List)myalloc(sizeof(struct list));
	list->count = 0;
	list->first = NULL;
	list->last = NULL;
	Node tempN;
	Student tempS; //not needed
	//proceed if array not empty
	if(size>0){
		//adding first element
		Node first = (Node)myalloc(sizeof(struct node));
		first->record = &array[0];
		first->next = NULL;
		tempN = first;
		list->first = tempN;
		list->count++;
		}
	Node curr;
	//if there are more elements to add
	for(int i = 1;i<size;i++){
		curr = (Node)myalloc(sizeof(struct node));
		tempS = &array[i]; //not needed
		curr->record = tempS;
		curr->next = NULL;
		tempN->next = curr;
		tempN = tempN->next;
		list->count++;
	}
	list->last = tempN;
	return list;
	}
void insertInOrder(List list,Node n){
	Node c = NULL;	
	Node p = list->first;
	if(p==NULL){
		list->first = n;
		list->last = n;
		list->count++;
		return ;
	}
	if(p!=NULL)
	c = list->first->next;
	//first pos check
	if(n->record->marks<=p->record->marks){
		n->next = p;
		list->first = n;
		list->count++;
		return ;
	}
	int inserted = 0;	
	while(c!=NULL){
		if(n->record->marks<=c->record->marks){
			p->next = n;
			n->next = c;
			inserted = 1;
			list->count++;
			break;
		}
		p = p->next;
		c = c->next;
	}
	//last element insert
	if(inserted == 0){
		p->next = n;
		
		list->last = n;
		list->count++;
	}
	return ;
}
List insertionSort(List list){
	List new = (List)myalloc(sizeof(struct list));
	Node c = list->first;
	Node t;
    int i = 0;
	while(c!=NULL){
		t = c->next;
		c->next = NULL;
		insertInOrder(new,c);
		c = t;
        printf("%d\n",i++);
	}
    //myfree(list);
	return new;
}
double measureSortingTime(List list){
	struct timeval t1;
	struct timeval t2;
	gettimeofday(&t1,NULL);
	list = insertionSort(list);
	gettimeofday(&t2,NULL);
	double mseconds1 = t1.tv_sec*1000 + t1.tv_usec/1000;
	double mseconds2 = t2.tv_sec*1000 + t2.tv_usec/1000;
	return mseconds2-mseconds1;
}
void * myalloc(int size){
	int* data = malloc(size+4);
	if(data == NULL)
		return data;
	*data = size;
	data++;
	globalCounter+=size;
	return (void*)data;
}
void myfree(void* ptr){
	if(ptr==NULL)
		return;
	int *d = (int*)ptr;
	d--;
	int a = *d;
	free(d);
	globalCounter -=a;
}
