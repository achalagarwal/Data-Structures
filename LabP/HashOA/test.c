#include"hash.h"
#include<stdio.h>
#include<stdlib.h>


struct element{
    int value;
};

typedef struct element* Element;


/* Define two functions 
   isEqual - compares two elements for equality
   hash - returns bounded hash value
*/

int hash(void* e, int bound){
    int x = ((Element)e)->value;
    x = ((x >> 16) ^ x) * 0x45d9f3b % bound;
    x = ((x >> 16) ^ x) * 0x45d9f3b % bound;
    x = (x >> 16) ^ x;
    return x%bound;
}

int isEqual(void* e1, void* e2){
    if(((Element)e1)->value == ((Element)e2)->value)
        return 1;
    else
        return 0;
}

Element createElement(int v){
    Element e = (Element)malloc(sizeof(struct element));
    e->value = v;
    return e;
}

int main(){
    Element* arr = (Element*)malloc(sizeof(Element)*10);
    for(int i = 0;i<10;i++)
        arr[i] = createElement(rand());
    HT h = createHT(100,&hash,&isEqual);
    int flag;
    int index = 0;
    do{
        flag = addToHT(h,arr[index++]);
    }
    while(flag == 1 && index<10);
    
    printf("done");
}



