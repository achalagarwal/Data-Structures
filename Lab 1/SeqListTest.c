#include"SeqListUses.c"
/*int main(){
	printf("Hi");
	SeqList sl = newList();
	printf("Hi");
	Element* e = (Element*)malloc(sizeof(Element));
	e->value = 2;
	sl = insertInOrder(sl,*e);
	sl = insertAtFront(sl,*e);
	sl = insertAtEnd(sl,*e);
	sl = delete(sl,*e);
	Key* k = (Key*)malloc(sizeof(Key));
	k->value = 1;
	Element found = find(sl,*k);
	Node* current = sl.first;
	while(current!=NULL){
		printf("%d",current->k.value);
		current = current->next;
	}
}
*/
int main(){
	SeqList sl = newList();
	printf("Hi");
	Element* e= (Element*)malloc(sizeof(Element));
	e->value = 1;
	Element *e2 = (Element*)malloc(sizeof(Element));
	e2->value = 2;
	sl = insertAtFront(sl,*e);
	sl = insertAtEnd(sl,*e2);
	SeqList sl2 = newList();
	sl2 = insertAtFront(sl2,*e);
	SeqList sl3 = merge(sl,sl2);
	Node* current = sl3.first;
        while(current!=NULL){
                printf("%d",current->e.value);
                current = current->next;
        }
}
