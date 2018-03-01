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
<<<<<<< HEAD
    bf->filled = 0;
=======
>>>>>>> 6d79062d38d1c549ef84102c8ad0f084ea232daf
    return bf;
}
void increment(BF bf,int index){
    if(index>=0 && index<bf->size){
        bf->filter[index]++;
        if(bf->filter[index]==1)
            bf->filled++;
    }
}
void decrement(BF bf,int index){
    if(index>=0 && index<bf->size)
        if(bf->filter[index]>0){
            bf->filter[index]--;
            if(bf->filter[index]==0)
                bf->filled--;
        }
}
int getCount(BF bf, int index){
    if(index>=0 && index<bf->size)
        return bf->filter[index];
    else 
        return -1;
}
void batchIncrement(BF bf,int* indices,int size){
    for(int i = 0;i<size;i++)
        increment(bf,indices[i]);

    //    if(indices[i]>=0 && indices[i]<bf->size)
      //      bf->filter[indices[i]]++;
}
void batchDecrement(BF bf, int* indices,int size){
    for(int i = 0;i<size;i++)
        decrement(bf,indices[i]);

    //    if(indices[i]>=0 && indices[i]<bf->size)
      //      if(bf->filter[indices[i]]>0)
        //        bf->filter[indices[i]]--;
}
float getLoadFactor(BF bf){
    return bf->filled*1.0/(bf->size*1.0);
}
