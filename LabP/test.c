#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char* data = (char*)malloc(sizeof(char)*10);
    int size=10;
    while(size>3){
        scanf("%s",data);
        size = strlen(data);
        printf("%d",size);
    }
}
