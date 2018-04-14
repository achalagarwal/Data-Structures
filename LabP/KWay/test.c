#include<stdlib.h>
#include"heap.h"

struct element{
    int key;
};

typedef struct element* Element;

int compare(void* e1, void* e2){
    Element a = (Element)e1;
    Element b = (Element)e2;
    if(a->key<b->key)
        return -1;
    if(a->key>b->key)
        return 1;
    else
        return 0;
}

int main(){
    Heap h = createHeap(5,&compare);
    Element e1 = (Element)malloc(sizeof(struct element));
    e1 -> key = 1;
    Element e2 = (Element)malloc(sizeof(struct element));
    e2 -> key = 2;
    Element e3 = (Element)malloc(sizeof(struct element));
    e3 -> key = 3;
    Element e4 = (Element)malloc(sizeof(struct element));
    e4 -> key = 4;
    Element e5 = (Element)malloc(sizeof(struct element));
    e5 -> key = 5;
    insertElement(h,e1);
    insertElement(h,e2);
    insertElement(h,e3);
    insertElement(h,e4);
    insertElement(h,e5);

}
