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

Node createList(Element e){
    Node n = (Node)malloc(sizeof(struct node));
    n -> e = e;
    n -> next = NULL;
    return n;
}

Node addToList(Node n, Element e){
    Node new = createList(e);
    new -> next = n;
    return new;
}

Node deleteFromList(Node n, Element e){
    Node copy = n;
    Node prev = n;
    if(areEqualElements(n -> e, e)==1)
        return n->next;
    n = n -> next;
    while(n!=NULL){
        if(areEqualElements(n -> e, e)==1){
            prev -> next = n -> next;
            return copy;
        }
        prev = n;
        n = n -> next;
    }
    return NULL;
}

