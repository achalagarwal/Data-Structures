#ifndef LIST
#include"list.h"
#endif
#include<stdlib.h>
void push(List l,int a){
	Node t = (Node)malloc(sizeof(struct node));
	t->next = NULL;
	t->a = a;
	if(l->head==NULL)
		l->head = t;
	else if(a<=l->head->a){
		t->next = l->head;
		l->head = t;
}
	else{
		Node p = l->head;
		Node c = l->head->next;
		while(c!=NULL){
			if(a<=c->a){
				p->next = t;
				t->next = c;
				break;
			}
			c=c->next;
			p=p->next;
		}
		if(c==NULL)
		p->next = t;
		}
	}
Node pop(List l){
	if(l->head == NULL)
	return NULL;
	Node t = l->head;
	l->head = l->head->next;
	return t;
	}	
List createList(){
	List l = (List)malloc(sizeof(struct list)*10);
	for(int i =0;i<10;i++)
	l[i].head = NULL;
	return l;
	}
			
