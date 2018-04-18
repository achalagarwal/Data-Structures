//
//  hash.h
//
//
//  Created by Achal Agarwal on 16/04/18.
//
#define hash_h

struct hashtable{
    void** table;
    int size;
    int (*hash)(void*,int);
    int (*isEqual)(void*,void*);
    float load;
    int* marker;
};

typedef struct hashtable* HT;

HT createHT(int size,int (*f)(void*,int),int (*g)(void*,void*));
int addToHT(HT ht, void* e);
int deleteFromHT(HT ht, void* e);
int lookup(HT ht,void* e);
void* getHTElement(HT ht, int index);
