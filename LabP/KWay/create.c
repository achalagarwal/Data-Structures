#include<stdio.h>
#include<stdlib.h>
int count =0;

int getRandom(int bound){
    count++;
    if(count%20==0){
        count = 0;
        srand(rand());
    }
    int r = rand();
    return r%(bound+1);
}

void insert(int*arr,int value,int size){
    int i = 0;
    for(i = size-1;i>=0;i--){
        if(arr[i]>value){
            arr[i+1] = arr[i];
        }
        else{
            arr[i+1] = value;
            break;
        }
    }
    if(i == -1)
        arr[0] = value;
}

void fill(FILE* f){
    int s = getRandom(1000000);
    printf("Created File with %d elements\n",s);
    int* arr = (int*)malloc(sizeof(int)*s);
    int c =0;
    while(c<s){
    //    insert(arr,getRandom(100000),c++);
        fprintf(f,"%d\n",getRandom(1000000000));
        c++;
    }/*
    for(int i = 0;i<s;i++){
        fprintf(f,"%d\n",arr[i]);
    }
    */
    free(arr);

}

void createFiles(){
    int files = getRandom(20);
    printf("Will create %d files\n",files);
    char* prefix = "file\0";
    char* name = (char*)malloc(sizeof(char)*10);
    int count = 0;
    sprintf(name,"%s%d",prefix,count++);
    while(count<=files){
        FILE* f = fopen(name,"w");
        fill(f);
        fclose(f);
        sprintf(name,"%s%d",prefix,count++);
    }
    printf("Filled all files\n");
    return;
}

int main(){
    printf("******************\n");
    createFiles();
    printf("******************\n");
}
