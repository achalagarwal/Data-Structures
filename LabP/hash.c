#include<stdlib.h>
<<<<<<< HEAD
#include<stdio.h>
=======
>>>>>>> 6d79062d38d1c549ef84102c8ad0f084ea232daf
#include"hash.h"
#ifdef MEM
    malloc = myalloc;
    realloc = myrealloc;
    free = myfree;
#endif
<<<<<<< HEAD
int hashString(char* word,int size){
    int hashAddress = 0;
    for(int i = 0;i<size;i++)
        hashAddress = word[i] + (hashAddress << 6) + (hashAddress << 16) +(hashAddress <<20) - hashAddress;
//    printf("%d\n",hashAddress);
    return hashAddress;
}
    //make use of perms.c for hash generation
=======
>>>>>>> 6d79062d38d1c549ef84102c8ad0f084ea232daf
int *hash(HO options,char* data,int size){
    int * indices = (int*)malloc(sizeof(int)*options->bits);
    int ind;
    int hashes = 0;
    char* dataNew = (char*)malloc(sizeof(char)*size);
    for(int i = 0;i<size;i++){
        dataNew[i] = (char)((int)data[i]+options->bits);
    }
    while(hashes<options->bits){
        for(int i = 0;i<size*options->bits;i++){
            ind = i%size;
            dataNew[ind] =(char)( dataNew[ind]^dataNew[(ind+1)%size]);
        }
        int index1 = 0;
<<<<<<< HEAD
      /*  for(int i = 0;i<size;i++){
            index1+=(i+1)*(int)dataNew[i]%options->range;
        }
    */
        index1 = hashString(dataNew,size);
        for(int i = 0;i<size*options->bits;i++){
             ind = i%size;
             dataNew[ind] =(char)( (dataNew[ind]+options->bits)^dataNew[abs((ind - 1)%size)]);
        }
        int index2 = 0;
        index2 = hashString(dataNew,size);
       /* for(int i = 0;i<size;i++){
            index2 +=(size-i)*(int)dataNew[i]%options->range;
        }
        */
       /* while(index1<options->range)
            index1*=91;
        index1*=91;
        */
=======
        for(int i = 0;i<size;i++){
            index1+=(i+1)*(int)dataNew[i]%options->range;
        }
        for(int i = 0;i<size*options->bits;i++){
             ind = i%size;
             dataNew[ind] =(char)( (dataNew[ind]+options->bits)^dataNew[(ind - 1)%size]);
        }
        int index2 = 0;
        for(int i = 0;i<size;i++){
            index2 +=(size-i)*(int)dataNew[i]%options->range;
        }
        while(index1<options->range)
            index1*=91;
        index1*=91;
>>>>>>> 6d79062d38d1c549ef84102c8ad0f084ea232daf
        indices[hashes++]=abs((2*index1+3*index2)%options->range);
    }
    return indices;
}
void hashIntoFilter(HO options,char* data,int size,BF filter){
    if(options->range>filter->size)
        options->range = filter->size;
    int* indices = hash(options,data,size);
    batchIncrement(filter,indices,options->bits);
}
