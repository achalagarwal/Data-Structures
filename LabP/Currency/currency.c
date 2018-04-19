#include"currency.h"
#include<stdlib.h>
#include<stdio.h>
Currency createCurrency(char* key){
    Currency c = (Currency)malloc(sizeof(struct currency));
    c->key = (char*)malloc(sizeof(char)*4);
    sprintf(c->key,"%3s",key);
    return c;
}

int main(){
    Currency c1 = createCurrency("USD");
    Currency c2 = createCurrency("INR\0");
    Currency c3 = createCurrency("DN");
}
