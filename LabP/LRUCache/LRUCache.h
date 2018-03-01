#define CACHE
#include"Element.h"
#include"DoubleList.h"
#include"HashTable.h"

struct _lrucache;
typedef struct _lrucache* LRUCache;

struct _lrucache{
    HTable ht;
    DList dl;i
    int size;
};

// methods for cache

LRUCache createLRUCache(int size);
LRUCache cacheElement(Element e);



