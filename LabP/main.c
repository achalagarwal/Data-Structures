#include"filter.h"
#include"hash.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printArray(int* arr, int size){
    for(int i= 0;i<size;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}
int isMember(char* d,int size,HO options,BF filter){
    int *data = hash(options,d,size);
    int count;
    int i;
    for(int i = 0;i<options->bits;i++){
        count = getCount(filter,data[i]);
        if(count==0)
            return 0;
    }
    return 1;
}
char* initialise(int size){
    char* ch = (char*)malloc(sizeof(char)*size);
    for(int i = 0;i<size;i++)
        ch[i]= 'A';
    return ch;
}
int recurse(char* data,int size, HO options,BF filter){
    int count=0;
    int a,i,j;
    while(size<=5){
    count+= isMember(data,size,options,filter);
    for(i = size-1;i>=0;i--)
        if(data[i] != 'Z'){
            data[i] =(char)((int)(data[i]) + 1);
            for(int j = i+1;j<size;j++)
                data[j]='A';
            break;
        }
        if(i<0){
            data = initialise(size+1);
            size++;
        }
       // printf("%s",data);
    }
    return count;
}
void test(HO opts,BF bf,int min, int max){
    char* data = initialise(min);
    printf("\n%d",recurse(data,min,opts,bf));
}
void testHast(BF filter,HO opts){
    char* data = initialize(min);

}
int main(){
    char* input = (char*)malloc(sizeof(char)*10);
  //  input = "achak";
    input[0]='a';
    input[1]='c';
    input[2]='h';
    input[3]='a';
    input[4]='l';
    input[5] = '\0';
    BF bf = createFilter(10000);
    HO opt = (HO)malloc(sizeof(struct hashOptions));
    opt->range = 10000;
    opt->bits =4 ;
    int size;
    int count = 0;
    FILE* f = fopen("new.txt","r");
    int a = fscanf(f,"%s",input);
   // printArray(data,opt->bits);
    while(a!=EOF){
    size = strlen(input);
    if(size>=3 && size<=5){
        count++;
    hashIntoFilter(opt,input,size,bf);
    }
    a = fscanf(f,"%s",input);
    //printArray(data,opt->bits);
    }
    printf("%d\n",count);
    printArray(bf->filter,bf->size);
    test(opt,bf,3,5);
};

