#define BINARYENCODE_H
#ifndef FIXEDENCODE_H
#include"FixedEncode.h"
#endif

struct bin;
typedef struct bin* Bin;
struct bin{
    Fix f;
    Bin next;
};

Bin createBin(int k);
Bin addBin(Bin b,Element e);
char* getBin(Bin b, int value);




