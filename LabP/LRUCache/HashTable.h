//separate chaining HashTable
#ifndef ELEMENT
#include"Element.h"
#endif
#include"DoubleList.h"

struct _hashtable;
typedef struct _hashtable* HTable;

struct _hashtable{
    DList* table;
    int size;
};

HTable insertElementHT(HTable ht, Element e);
HTable createHTable(int size);
//implement remove from table
