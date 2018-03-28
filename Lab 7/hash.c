#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include"hash.h"

int hash(char* str, int base, int size){
	char ch = str[0];
	int hash =  0;
	int i = 0;
	int a = 33;
	while(ch!='\0'){
		hash = (int)ch + hash*31;
        hash = hash%base;
		//hash*=a;
		ch = str[++i];
	}
	hash = hash%base;
	return hash%size;
}

int insertInOrder(int* arr, int size, int n){
	//assume arr[size-1] contains the elements
	int temp = arr[size-1];
	for(int i = size-2;i>=0;i--){
		if(arr[i]>temp){
			arr[i+1] = arr[i];
		}
		else if(arr[i] == temp){
			arr[i+1] = temp;
			return 1;
		}
		else{
			arr[i+1] = temp;
			return 0;
		}
	}
	arr[0]  = temp;
	return 0;
}

int collisionCount(char** strarr, int arrsize, int base, int size){
	int* arr = (int*)malloc(sizeof(int)*arrsize);
	int count = 0; 
	for(int i = 0;i<arrsize;i++){
		arr[i] = hash(strarr[i],base,size);
		int c = insertInOrder(arr,i+1,arr[i]);
		if(c == 1)
			count++;
	}
    FILE* f = fopen("data.txt","w");
    for(int i = 0;i<arrsize;i++){
        fprintf(f,"%d\n",arr[i]);
    }
	return count;
}

char* clean(char* word){
	int i = 0;
	char* n = (char*)malloc(sizeof(char)*30);
	char ch = word[0];
	int index = 0;
	while(ch!='\0'){
		if((int)ch>0)
			n[index++] = ch;
		ch =  word[++i];
	}
    n[index] = ch;
	return n;
}

/*struct array{
	char** arr;
	int size;
};
typedef struct array* Array;
*/
int unique(char* word, char** arr, int size){
    for(int i = 0;i<size;i++){
        if(strcmp(arr[i],word)==0){
            return 0;
        }
    }
    return 1;
}

int isValid(char* str){
	char ch = str[0];
	int i = 0;
	while(ch!='\0'){
		if(!isalpha((int)ch))
			return 0;
		ch = str[++i];
	}
	return 1;
}

Array parser(char* name){
	FILE* f = fopen(name,"r");
	char** strarr = (char**)malloc(sizeof(char*)*10);
	for(int i = 0;i<10;i++){
		strarr[i] = (char*)malloc(30*sizeof(char));
	}
	int size = 10;
	int count = 0;
	char* word =  malloc(sizeof(char)*30);
	int a = fscanf(f,"%s",word);
	while(a!=EOF){
		if(count==size){
			strarr = (char**)realloc(strarr,sizeof(char*)*size*2);
			size = size*2;
			for(int i = count;i<size;i++)
				strarr[i] = (char*)malloc(30*sizeof(char));
		}
//		word = clean(word);
		if(isValid(word)){
//            if(unique(word,strarr,count-1))
	    	    strcpy(strarr[count++],word);
        }
		a = fscanf(f,"%s",word);
	}
	Array ret = (Array)malloc(sizeof(struct array));
	ret->arr = strarr;
	ret->size = count;
	return ret;
}
int mains(){
	char* ch = "aliceinwonderland.txt";
	Array a = parser(ch);
	int c = collisionCount(a->arr, a->size,1000003,1000003);
	printf("%d\n",a->size);
	printf("%d",c);
}
