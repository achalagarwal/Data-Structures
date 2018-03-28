#include<stdlib.h>
#include<string.h>
#ifndef ELEMENT
#include"list.h"
int areEqualElements(Element a, Element b){
    return strcmp(a -> value, b -> value);
}
#endif

#ifndef ELEMENT_B
#include"list.h"
#endif

List createList(){
    List n = (List)malloc(sizeof(struct list));
    n -> head = NULL;
    n -> count = 0;
    return n;
}

List addToList(List l, Node n){
    if(n==NULL)
        return l;
    n->next = l->head;
    l->head = n;
    l->count++;
    return l;
}

List addEToList(List l, Element e){
    Node n = (Node)malloc(sizeof(struct node));
    n -> e = e;
    n -> next = NULL;
   return addToList(l,n);
}

//delete returns 1 if deleted else 0

int deleteFromList(List l, Element e){
    Node n = l->head;
    Node prev= l->head;
    if(areEqualElements(n -> e, e)==1){
            l->head = n->next;
            l->count--;
            return 1;
    }
    n = n->next;
    while(n!=NULL){
        if(areEqualElements(n -> e, e)==1){
            prev -> next = n -> next;
            l->count--;
            return 1;
        }
        prev = n;
        n = n -> next;
    }
    return 0;
}

