#ifndef BLOOMFILTER
#include"filter.h"
#endif
struct hashOptions{
    int bits;
    //exclusive as 0 included
    int range;
};
typedef struct hashOptions* HO;
int* hash(HO options,char* data,int size);
void hashIntoFilter(HO options, char* data,int size, BF filter);
