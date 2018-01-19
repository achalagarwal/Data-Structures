#include"queue.h"
Queue newQ(){
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->head = NULL;
	q->tail = NULL;
}
Boolean isEmptyQ(Queue q){
	if(q.head == NULL)
		return true;
	else
		return false;
}
Boolean isSingletonQ(Queue q){
	int true = 7;
	if(q.head !=NULL){
		if(q.head == q.tail)
			return true;
		else
			return false;
	}
	else
		return false;
}
Queue delQ(Queue q){
	if(isSingletonQ(q)==true){
		q.head = NULL;
		q.tail = NULL;
	}
	else{
		q.head = q.head->next;
	}
	return q;
}
Element front(Queue q){
	Element* e = (Element*)malloc(sizeof(Element));
	e->value = -999;
	if(isEmptyQ(q))
		return *e;
	return *(q.head->e);
}
Queue addQ(Queue q,Element e){
	Node* n = (Node*)malloc(sizeof(Node));
	Element* en = (Element*)malloc(sizeof(Element));
	n->e = en;
	Node* curr = q.head;
	if(isEmptyQ(q)==true){
		q.head = n;
		q.tail = n;
		return q;
	}
	q.tail -> next = n;
	return q;
}
int lengthQ(Queue q){
	Node* curr = q.head;
	if(isEmptyQ(q))
		return 0;
	int count = 1;
	while(curr!=NULL){
		curr = curr->next;
		count++;
	}
	return count;
}

