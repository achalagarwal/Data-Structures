#include<stdio.h>
#include<stdlib.h>
#include<hash.h>
HashTable createTable(int size){
    HashTable h = (HashTable)malloc(sizeof(struct hashtable));
    h -> size = size;
    h -> elementCount = 0;
    h -> insertionCost = 0;
    h -> queryingCost = 0;
    h -> heads = (Node)malloc(sizeof(struct node)*size);
    return h;
}

HashTable insertIntoTable(HashTable h, Element e){
    int hash = hash(e -> value, 1000003, h -> size);
    Node n = h -> heads[hash];
    h -> heads[hash] =  addToList(n,e);
    return h;
}

HashTable insertAllIntoTable(HashTable h, Element* book, int words){
    for(int i = 0 ; i < words; i++)
        insertIntoTable(h, book[i]);
    return h; 
}

Element lookup(HashTable h, char* input){
    int hash = hash(input, 1000003, h->size);
    Node n = h -> heads[hash];

}

