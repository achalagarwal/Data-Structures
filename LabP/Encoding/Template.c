#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"FixedEncode.h"
#include"BinaryEncode.h"
#include<sys/time.h>
Element createElement(int a, char* action){
    Element e = (Element)malloc(sizeof(struct element));
    e->action = (char*)malloc(sizeof(char)*30);
    e->value = a;
    //sprintf(e->value,"%d",a);
    strcpy(e->action,action);
    return e;
}


Bin createTemplate(int k,int max){
    Bin b = createBin(k);
    char* action = (char*)malloc(sizeof(char)*30);
    for(int i = 0;i<max;i++){
        sprintf(action,"thisIsActionFor%d",i);
        //createElement(i,action);
        b = addBin(b,createElement(i,action));
    }
    return b;
}

void profile(int max, int k){
    Bin b = createTemplate(k,max);
    for(int i = 0;i<max;i++){
        for(int j = 0;j<(max-i);j++){
            getBin(b,i);
        }
    }
    return;
}
int main(){
    int max = 1000;
    for(int i = 1;i<100;i++){
    struct timeval t1;
    struct timeval t2;
    gettimeofday(&t1,NULL);
    profile(max,i);
    gettimeofday(&t2,NULL);
    double mseconds1 = t1.tv_sec*1000 + t1.tv_usec/1000;
    double mseconds2 = t2.tv_sec*1000 + t2.tv_usec/1000;
    printf("%lf\n",mseconds2-mseconds1);
    }
   // Bin b = createTemplate(4,10000);
   // for(int i = 0;i<100000;i++)
  //     printf("%s",getBin(b,0));
   // printf("Done");
   // int a = 3*2;
   // for(int i = 0;i<100000;i++)
//        printf("%s",getBin(b,9999));
    //printf("\nDone");
}

