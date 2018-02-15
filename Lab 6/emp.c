#include<stdio.h>
#include<stdlib.h>
#include"emp.h"
Stack createStack(){
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->head = NULL;
	return s;
}
Stack push(Stack s,int a,int b){
	Pair p = (Pair)malloc(sizeof(struct pair));
	p->start = a;
	p->end = b;
	p->next = NULL;
	if(s->head==NULL){
		s->head = p;
		return s;
	}
	p->next=s->head;
	s->head = p;
	return s;
}
Pair pop(Stack s){
	if(s->head==NULL)
		return s->head;
	Pair p = s->head;
	s->head = s->head->next;
	return p;
}
Employee createEmployee(char* name, long long id){
	Employee e = (Employee)malloc(sizeof(struct employee));
	e->name=name;
	e->empID = id;
	return e;
}
int compareEmployees(Employee a, Employee b){
	if(a!=NULL&&b!=NULL){
		if(a->empID<b->empID)
			return -1;
		else return 1;
	}
	else
		return 0;
}

