#include"SeqList.c"
SeqList merge(SeqList list1, SeqList list2){
	SeqList list3 = newList();
	Node* current1 =  list1.first;
	Node* current2 = list2.first;
	while(current1!=NULL || current2!=NULL){
		if(current1!=NULL){
			if(current2!=NULL){
				if(current1->e.value<=current2->e.value){
					list3 = insertAtEnd(list3, current1->e);
					current1 = current1->next;
				}
				else if(current1->e.value>current2->e.value){
					list3 = insertAtEnd(list3, current2->e);
					current2 = current2->next;
				}
			}
			else if(current2 == NULL){
				list3 = insertAtEnd(list3, current1->e);
				current1 = current1->next;
			}
		}
		else if(current1==NULL){
			list3 = insertAtEnd(list3,current2->e);
			current2 = current2->next;
		}
	}
	return list3;
}
SeqList insertionSort(SeqList list){
	Node* current = list.first;
	if(current == NULL)
		return list;
	SeqList temp = newList();
	temp = insertAtFront(temp,current->e);
	current = current->next;
	while(current!=NULL){
		temp = insertInOrder(temp, current->e);
		current = current->next;
	}
	return temp;
}
			

