#include<stdlib.h>
#include"hash.h"
#ifdef MEM
    malloc = myalloc;
    realloc = myrealloc;
    free = myfree;
#endif
int *hash(HO options,char* data,int size){
    int * indices = (int*)malloc(sizeof(int)*options->bits);
    int ind;
    int hashes = 0;
    while(hashes<options->bits){
        for(int i = 0;i<size*options->bits;i++){
            ind = i%size;
            data[ind] =(char)( data[ind]^data[(ind+1)%size]);
        }
        int index1 = 0;
        for(int i = 0;i<size;i++){
            index1+=(i+1)*(int)data[i]%options->range;
        }
        for(int i = 0;i<size*options->bits;i++){
             ind = i%size;
             data[ind] =(char)( data[ind]^data[(ind - 1)%size]);
        }
        int index2 = 0;
        for(int i = 0;i<size;i++){
            index2 +=(size-i)*(int)data[i]%options->range;
        }
        indices[hashes++]=(2*index1+3*index2)%options->range;
    }
    return indices;
}
#ifdef BLOOMFILTER
void hashIntoFilter(HO options,char* data,int size,BF filter){
    if(options->range>filter->size)
        options->range = filter->size;
    int* indices = hash(options,data,size);
    batchIncrement(filter,indices,options->bits);
}
#endif
