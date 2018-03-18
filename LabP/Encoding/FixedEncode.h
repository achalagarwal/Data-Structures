#include<stdlib.h>
#define FIXEDENCODE_H
#ifndef ELEMENT
#define ELEMENT
struct element;
typedef struct element* Element;
struct element{
    int value;
    char* action; //null terminated
};
#endif

struct fix;
typedef struct fix* Fix;

struct fix{
    int k;
    Element* array;
};

Fix createFix(int size);
char*  get(Fix f,int value);
Fix update(Fix f,int value, Element e);
Fix resize(Fix f, int newSize);
Fix add(Fix f, Element e);
