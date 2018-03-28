#include<string.h>
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
    h -> heads = (List*)malloc(sizeof(List)*size);
    for(int i = 0;i<size;i++)
        h->heads[i] = (List)malloc(sizeof(struct list));
    return h;
}

HashTable insertIntoTable(HashTable h, Element e){
    int hashV = hash(e -> value, 1000003, h -> size);
    List n = h -> heads[hashV];
    int oc = n->count;
    n = addEToList(n,e);
    int nc = n->count;
    if(nc ==oc+1){
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
    int hashV = hash(input, 1000003, h->size);
    List l = h -> heads[hashV];
    Node n = l -> head;
    int c = 0;
    while(n!=NULL){
        c++;
        if(strcmp(n->e->value,input)==0)
            break;
        n = n->next;
    }
    if(h -> queryingCost > c)
        h -> queryingCost = c;
    if(n == NULL)
        return NULL;
    return n -> e;
}

int lookupAll(HashTable h, char** input, int words, int m){
    h->queryingCost = 0;
    for(int i = 0;i<m*words/100;i++){
        lookup(h,input[i]);
    }
    return h->queryingCost;
}

int profile(HashTable h, char** input, int words){
    for(int i = 1;i<10;i++){
        if(lookupAll(h,input,words,10*i)>h->insertionCost)
            return i*10;
    }
    return 0;
}
Element* createElements(char** arr,int size){
    Element* e = (Element*)malloc(sizeof(Element)*size);
    for(int i = 0;i<size;i++){
        e[i] = (Element)malloc(sizeof(struct element));
        e[i]->value = (char*)malloc(sizeof(char)*30);
        strcpy(e[i]->value,arr[i]);
        e[i]->key = 1;
    }
    return e;
}

int main(){
    char*ch = "aliceinwonderland.txt";
    Array a = parser(ch);
    printf("%d\n",a->size);
    HashTable h = createTable(1000);
    Element* e = createElements(a -> arr,a->size);
    int cost = insertAllIntoTable(h,e,a->size);
    printf("%d\n",cost);
    int p = profile(h,a->arr,a->size);
    printf("%d\n",p);
}
