#include"list.h"

struct hashtable;

typedef struct hashtable* HashTable;

struct hashtable{
    int size;
    int elementCount;
    int insertionCost;
    int queryingCost;
    Node* heads;
};

HashTable createTable(int size);
HashTable insertIntoTable(HashTable h, Element e);
HashTable insertAllIntoTable(HashTable h, char** book, int words);
Element lookup(HashTable h, char* input);
int lookupAll(HashTable h, char** input, int inputs, int m);


