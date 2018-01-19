#include"SeqList.h"
SeqList newList(){
	SeqList *sl = (SeqList*)malloc(sizeof(SeqList));
	return *sl;
	}
SeqList insertInOrder(SeqList sl, Element e){ //you have not malloced a new Node
	Node *new = (Node *)malloc(sizeof(Node));
	new->e = e;
	Key *k =(Key*)malloc(sizeof(Key));
	new->k = *k;
	Node *current = sl.first;
	int  flag = 0;
	if(current==NULL){ //no elements present initially
		new->k.value= 0;
		sl.first =new;
		sl.last = new;
		flag = 1;
	}
	while(current!=NULL&&flag==0){
		if(current->e.value > e.value)
			break;
		else
			current = current->next;
	}
	if(flag==0){
		new->next = current->next;
		current->next = new;
		flag = 1;
		if(current==sl.last){
			sl.last = current->next;
			new->k.value = current->k.value+1;
		}
		else{ //set key, not the last node
			new->k.value = (new->next->k.value + current->k.value) /2;
		}

	}
	if(flag == 1)
		return sl;
	else
		return sl;
}

SeqList insertAtFront(SeqList sl, Element e){ //unfinished
	Node *current = sl.first;
	Node *new = (Node *)malloc(sizeof(Node));
	Key *k =(Key*)malloc(sizeof(Key));
	new->k = *k;
	new->e = e;	
	if(current==NULL){
		sl.first = new;
		sl.last = new;
		new->k.value = 0;
	}
	else{
		new->next = sl.first;  //e will be a node
		sl.first = new;
		new->k.value = new->next->k.value-1;
	}
	return sl;
}
SeqList insertAtEnd(SeqList sl, Element e){
	Node* current = sl.last;
	Node* new = (Node *)malloc(sizeof(Node));
	Key *k = (Key*)malloc(sizeof(Key));
	new->k =*k;
	new->e = e;
	new->next = NULL;
	if(sl.last == NULL){
		sl.last = new;
		sl.first = new;
		new->k.value = 0;
		return sl;
	}
	sl.last->next = new;
	new->k.value = sl.last->k.value + 1;
	sl.last = new;
	return sl;
}
SeqList delete(SeqList sl, Element e){
	Node* current = sl.first;
	Node* prev;
	//check if first element is the one
	if(current->e.value == e.value){
		sl.first = current->next;
		if(sl.last==current)
			sl.last=sl.first;
		return sl;
	}
	//if not first element
	prev = current;
	current = current->next;
	while(current!=NULL){
		if(current->e.value == e.value){
			prev->next = current->next;
			if(sl.last == current)
				sl.last = prev;
			return sl;
		}
	prev = current;
	current = current->next;
	}	
	return sl;
}
SeqList deleteAtFront(SeqList sl){
	Node* current = sl.first;
	if(current == NULL)
		return sl;
	else if(sl.first == sl.last){
		sl.first = NULL;
		sl.last = NULL;
		return sl;
	}
	else{
		sl.first = sl.first->next;
		return sl;
	}
}
Element find(SeqList sl, Key k){
	Node* current = sl.first;
	while(current!=NULL){
		if(current->k.value == k.value){
			return current->e;
		}
	current = current -> next;
	}
}
				

