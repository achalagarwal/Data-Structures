#include<stdlib.h>
#include"filter.h"
#ifdef MEM
    malloc = myalloc;
    realloc = myrealloc;
    free = myfree;
#endif
BF createFilter(int size){
    BF bf = (BF)malloc(sizeof(struct bloomfilter));
    bf->size = size;
    bf->filter = (int*)malloc(sizeof(int)*size);
    for(int i = 0;i<size;i++)
        bf->filter[i] = 0;
    return bf;
}
void increment(BF bf,int index){
    if(index>=0 && index<bf->size)
        bf->filter[index]++;
}
void decrement(BF bf,int index){
    if(index>=0 && index<bf->size)
        if(bf->filter[index]>0)
            bf->filter[index]--;
}
int getCount(BF bf, int index){
    if(index>=0 && index<bf->size)
        return bf->filter[index];
    else 
        return -1;
}
void batchIncrement(BF bf,int* indices,int size){
    for(int i = 0;i<size;i++)
        if(indices[i]>=0 && indices[i]<bf->size)
            bf->filter[indices[i]]++;
}
void batchDecrement(BF bf, int* indices,int size){
    for(int i = 0;i<size;i++)
        if(indices[i]>=0 && indices[i]<bf->size)
            if(bf->filter[indices[i]]>0)
                bf->filter[indices[i]]--;
}
