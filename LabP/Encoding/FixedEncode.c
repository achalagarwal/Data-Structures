#include<string.h>
#ifndef FIXEDENCODE_H
#include"FixedEncode.h"
#endif

char* get(Fix f, int value){
/*    Element* temp = f->array;
    int start = 0;
    int end = f->k-1;
    int mid;
    for(int i = 0;i<3;i++){
        if(temp[i]->value ==value)
            return temp[i]->action;
    }
    while(start<end){
        mid = (start+end)/2;
        if(temp[mid]->value == value)
            return temp[i]->action;
        else if(temp[mid]->value>value)
            end = mid-1;
        else if(temp[mid]->value<value)
            start = start+1;
    }
    */
    return f->array[value]->action;
}

Fix update(Fix f, int value, Element e){
    Element* temp = f->array;
    for(int i = 0; i<f->k;i++){
        if(temp[i]->value == value){
            temp[i] = e;
            return f;
        }
    }
    return f;
}

Fix resize(Fix f, int n){
    int o = f->k;
    f->array = realloc(f,n*sizeof(Element));
    Element* temp = f->array;
    for(int i = 0;i<n;i++){
        temp[i] = NULL;
    }
    return f;
}

Fix createFix(int k){
    Fix f = (Fix)malloc(sizeof(struct fix));
    f->k = k;
    f->array = (Element*)malloc(sizeof(Element)*k);
    Element* temp = f->array;
    for(int i = 0;i<k;i++)
        temp[i] = NULL;
    return f;
}

Fix add(Fix f,Element e){
    Element* temp = f->array;
    for(int i = 0;i<f->k;i++){
        if(temp[i]==NULL){
            temp[i] = e;
            return f;
        }
    }
    return f;
}
