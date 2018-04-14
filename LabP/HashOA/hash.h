#define HASH_H

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

