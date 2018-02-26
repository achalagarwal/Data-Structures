#include"filter.h"
#include"hash.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
    char* input = (char*)malloc(sizeof(char)*5);
    input = "achal";
    BF bf = createFilter(100);
    HO opt = (HO)malloc(sizeof(struct hashOptions));
    opt->range = 100;
    opt->bits = 3;
    int * data = hash(opt,input,5);
};

