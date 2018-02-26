#define BLOOMFILTER
struct bloomfilter{
    int* filter;
    int size;
};
typedef struct bloomfilter* BF;
void increment(BF bf,int index);
int getCount(BF bf,int index);
BF createFilter(int size);
void decrement(BF bf,int index);
void batchIncrement(BF bf, int* indices, int size);
void batchDecrement(BF bf, int* indices,int size);


