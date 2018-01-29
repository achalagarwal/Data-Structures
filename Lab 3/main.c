#include"cycle.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
    List l = createList(10000);
    l = createCycle(l);
    int o = testCyclic(l);
    printf("%d",o);
}

