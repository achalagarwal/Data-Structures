#include"heap.h"
#include<stdlib.h>

Heap createHeap(int size,int (*f)(void*,void*)){
    Heap h = (Heap)malloc(sizeof(struct heap));
    h->heap = (void**)malloc(size*sizeof(void*));
    h->size = size;
    h->last = -1;
    h->compare = f;
    return h;
}


// push last element in correct position

void swap(Heap h, int index1, int index2){
    void* temp  = h->heap[index1];
    h->heap[index1] = h->heap[index2];
    h->heap[index2] = temp;
}  

void pull(Heap h){
    int current = h->last;
    while(current>0){
        if(h->compare(h->heap[current],h->heap[(current-1)/2])<0)
            swap(h,current,(current-1)/2);
        else
            break;

        current = (current-1)/2;
    }
}

int insertElement(Heap h,void* e){
    if(h == NULL)
        return -1;
    if(h->last == h->size-1)
        return -1;
    h->last = h->last+1;
    h->heap[h->last] = e;
    pull(h);
    return 1;
}

int hasLeftChild(Heap h, int index){
    if(h==NULL)
        return 0;
    if(h->last<(index*2+1))
        return 0;
    else
        return 1;
}

int hasRightChild(Heap h, int index){
    if(h==NULL)
        return 0;
    if(h->last<(index*2+2))
        return 0;
    else
        return -1;
}

void push(Heap h){
    int current = 0;
    while(current<h->last){
        if(hasRightChild(h,current)==0){
            //no right child
            if(hasLeftChild(h,current)==0){
                //no left child
                //no children
                return;
            }
            else{
                //has left child
                if(h->compare(h->heap[current],h->heap[current*2 + 1])>0){
                    //needs swapping
                    swap(h,current, current*2+1);
                    current = current*2+1;
                }
                else{
                    return;
                }
            }
        }
        else{
            //has right child => has left child
            if(h->compare(h->heap[current*2+1],h->heap[current*2+2])<0){
                //left child < right child
                if(h->compare(h->heap[current*2+1],h->heap[current])<0){
                    //left child < parent
                    swap(h,current,current*2+1);
                    current = current*2+1;
                }
                else{
                    //parent is smallest
                    return;
                }
            }
            else{
                //right child < left child
                if(h->compare(h->heap[current*2+2],h->heap[current])<0){
                    //right child < parent
                    swap(h,current*2+2,current);
                    current = current*2+2;
                }
                else{
                    //parent is smallest
                    return;
                }
            }
        }
    }
}

int deleteMin(Heap h){
    if(h==NULL)
        return -1;
    if(h->last == -1)
        return -1;
    h->heap[0] = h->heap[h->last--];
    push(h);
    return 1;
}

void* getMin(Heap h){
    if(h==NULL)
        return NULL;
    if(h->last == -1)
        return NULL;
    else
        return h->heap[0];
}

void** sortDestroy(Heap h){
    void** heap = (void**)malloc(sizeof(void*)*(h->last+1));
    for(int i = 0; i<h->last+1;i++){
        heap[i] = getMin(h);
        if(deleteMin(h)!=1)
            break;
    }
    free(h->heap);
    free(h);
    return heap;
}

