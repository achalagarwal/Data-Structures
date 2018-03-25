#include<stdio.h>
#include<stdlib.h>
#include"hash.h"
#include"hasht.h"
#ifndef LIST_H
    #include"list.h"
#endif
HashTable createTable(int size){
    HashTable h = (HashTable)malloc(sizeof(struct hashtable));
    h -> size = size;
    h -> elementCount = 0;
    h -> insertionCost = 0;
    h -> queryingCost = 0;
    h -> heads = (List)malloc(sizeof(struct list)*size);
    return h;
}

HashTable insertIntoTable(HashTable h, Element e){
    int hash = hash(e -> value, 1000003, h -> size);
    List n = h -> heads[hash];
    int oc = n->count;
    n = addEToList(n,e);
    int nc = n->count;
    if(nc = oc+1){
        h -> elementCount++;
        if(n -> count > h -> insertionCost)
            h -> insertionCost = n -> count;
    }
    return h;
}

int insertAllIntoTable(HashTable h, Element* book, int words){
    for(int i = 0 ; i < words; i++)
        insertIntoTable(h, book[i]);
    return h->insertionCost; 
}

Element lookup(HashTable h, char* input){
    int hash = hash(input, 1000003, h->size);
    List l = h -> heads[hash];
    Node n = l -> head;
    int c = 0;
    while(n!=NULL){
        c++;
        if(areEqualElement(n->e,e))
            break;
        n = n->next;
    }
    if(h -> queryingCost > c)
        h -> queryingCost = c;
    if(n == NULL)
        return NULL;
    return n -> e;
}

}

