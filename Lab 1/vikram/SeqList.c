#include<stdio.h>
#include "SeqList.h"


void print(){
    printf("%s", "Hello");
}

struct SeqList newList(){
    struct SeqList list;
    list.head = NULL;
    return list;
}

struct SeqList insertAtFront(struct SeqList sl, struct Element e){
    e.next=sl.head;
    sl.head = &e;
    return sl;
}
