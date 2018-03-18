#include<stdio.h>
#include<stdlib.h>
#include"BinaryEncode.h"

int extract(char* value,int k){
    //assumed number in value
    char ch = value[0];
    int i = 0;
    int num = 0;
    while(ch!='\0'){
        int d = (int)ch - 48;
        num = num*10 + d;
        if(num>k)
            return num;
        ch = value[++i];
    }
    return num;
}
    
int insideBin(int data, Bin b){
    if(data<b->f->k)
        return 1;
    else
        return 0;
}

Bin createBin(int k){
    Bin b = (Bin)malloc(sizeof(struct bin));
    b->f = createFix(k);
    b->next = NULL;
    return b;
}

Bin addBin(Bin b,Element e){
    Bin c = b; 
    Bin p;
    while(c!=NULL){
        //sync with extract
       // int data = extract(e->value,c->f->k);
        //sync with insideBin
        if(insideBin(e->value,b)){
            c->f = add(c->f,e);
            return b;
        }
        else{
            e->value -= c->f->k;
            p = c;
            c = c->next;
        }
    }
    p->next = createBin(p->f->k);
    addBin(p->next,e);
    return b;
}

char* getBin(Bin b,int value){
    while(b!=NULL){
        //sync with extract
       // int data = extract(value,b->f->k);
        //sync with insideBin
        if(insideBin(value,b)){
            return get(b->f,value);
        }
        else{
            value = value-b->f->k;
            b = b->next;
        }
    }
    return NULL;
}


