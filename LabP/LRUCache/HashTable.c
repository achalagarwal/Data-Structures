#include"Element.h"
#include"HashTable.h"
#include<stdlib.h>
//include mem defined allocs

// returns hash value of 

int getHash(Key k, int max){

    return k%max;
}

// inserts element into the hash table

HTable insertElementHT(HTable ht, Element e){
    
    //get key from element in node
    Key k = getElementKey(e);

    //compute hash from key
    int hash = getHash(k, ht->size);

    //get list from corresponding location
    DList dl = ht -> table[hash];

    //insert element in list
    insertElement(dl,e);

    return ht;
}

// create and return a hash table

HTable createHTable(int size){

    //allocate memory for table
    HTable ht = (HTable)malloc(sizeof(struct _hashtable));
    ht -> table = (DList*)malloc(sizeof(DList)*size);
    //intializing table
    ht -> size = size;
    for(int i = 0; i<size ; i++)
        ht -> table[i] = createDList();
    
    return ht;
}


