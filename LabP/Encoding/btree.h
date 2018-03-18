#ifndef ELEMENT
#define ELEMENT
struct element;
typedef struct element* Element;
struct element{
    int value;
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
