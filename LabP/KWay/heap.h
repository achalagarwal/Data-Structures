#define HEAP_H


void* e;

struct heap{
    int size;
    void** heap;
    int last;
    int (*compare)(void*,void*);
};

typedef struct heap* Heap;

Heap createHeap(int size,int (*f)(void*,void*));
int insertElement(Heap h, void* e);
int deleteMin(Heap h);
void** sortDestroy(Heap h);
void* getMin(Heap h);
