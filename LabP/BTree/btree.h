#ifndef ELEMENT
#define ELEMENT
struct element;
typedef struct element* Element;
struct element{
    char* key;
    int size;
    char* value; //terminates with \0
};
#endif
struct btree;
typedef struct btree* Btree;
struct btree{
    Btree left;
    Btree right;
    Element e;
};

Btree add(Btree bt, Element e);
Btree remove(Btree bt, Element e);
Btree create();

