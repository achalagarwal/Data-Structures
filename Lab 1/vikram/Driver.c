#include<stdio.h>
#include"SeqList.c"

int main(){


    struct SeqList sl = newList();
    struct Element e;
    e.next=NULL;
    e.data=1;
    sl = insertAtFront(sl,e);

    struct Element e1;
    e1.next=NULL;
    e1.data=2;
    sl = insertAtFront(sl,e1);

    printf("%d\n",sl.head->next->data);
    printf("%d\n",sl.head->data);
    printf("%d\n",sl.head->next->data);
    return 0;
}
