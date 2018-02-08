
#include"string.h"
#include<stdio.h>
#include<stdlib.h>
#include"mergesort.h"
Element read(){
	FILE* f;
	f= fopen("10240.txt","r");
	char name[10];
	float cgpa;
	int a = 1;
	int size = 0;
	Element array = (Element)malloc(5*sizeof(struct element));
	int capacity = 5;
	while(a!=EOF){
		if(size==capacity-1){
			array = realloc(array,sizeof(struct element)*capacity*2);
			capacity*=2;
		}
		a = fscanf(f,"%10s,%f",name,&cgpa);
		strcpy(array[size].name,name);
		array[size].key = cgpa;
		size++;
	}
//	printf("DONE");
	fclose(f);
	return array;
}
int main(){
	Element a = read();
	a = mergesort(a,10240);
	FILE* f;
	f = fopen("sorted.txt","w");
	for(int i = 0;i<10240;i++){
		fprintf(f,"%s,%f\n",a[i].name,a[i].key);
}
fclose(f);
printf("\nPLEASE CHECK sorted.txt FOR RESULTS");
return 0;
}
