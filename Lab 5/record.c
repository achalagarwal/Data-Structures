#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mergesort.h"
#ifndef DEFINITIONS
#include"list.h"
#endif
int record(FILE* f,int k){
	char name[10];
	float cg;
	int a = fscanf(f,"%10s,%f",&name,&cg);
	int fileId = 0;
	char buf[10];
	sprintf(buf,"temp%d\0",fileId);
	Element e = (Element)malloc(sizeof(struct element)*k);	
	while(a!=EOF){
	int count = 0;
	while(a!=EOF&&count<k){
	strcpy(&(e[count].name[0]),&name[0]);
	e[count].key = cg;
	count++;
	a = fscanf(f,"%10s,%f",&name,&cg);
//	printf("%s",&name);
//	printf("\n%d",&cg);
	}
	e =(Element)mergesort(e,count);
	FILE *fnew;
	fnew = fopen(buf,"w");
	fileId++;
	for(int i = 0;i<count;i++){
		fprintf(fnew,"%s,%f\n",e[i].name,e[i].key);
	}
	fclose(fnew);
	sprintf(buf,"temp%d.txt",fileId);
	}
	return fileId;
}	
void  mergeFiles(FILE* f1, FILE* f2,int abc){
	FILE* f;
	//FILE* f1;
	//FILE* f2;
	//f1 = fopen(fn1,"r");
	//f2 = fopen(fn2,"r");
	char nname[10];
	sprintf(nname,"%s%d\0","t",abc);
	f = fopen(nname,"w");
	char name1[10];
	char name2[10];
	float key1;
	float key2;
	int a = fscanf(f1,"%10s,%f",&name1,&key1);
	int b = fscanf(f2,"%10s,%f",&name2,&key2);
	while(a!=EOF&&b!=EOF){
		if(key1<=key2){
			fprintf(f,"%10s,%f\n",name1,key1);
			a = fscanf(f1,"%10s,%f",&name1,&key1);
			
		}
		else{
			fprintf(f,"%10s,%f\n",name2,key2);
			b = fscanf(f2,"%10s,%f",&name2,&key2);
		}
	}
	while(a!=EOF){
		fprintf(f,"%10s,%f\n",name1,key1);
		a = fscanf(f1,"%10s,%f",&name1,&key1);
	}
	while(b!=EOF){
		fprintf(f,"%10s,%f\n",name2,key2);
		b = fscanf(f2,"%10s,%f",&name2,&key2);
	}
	fclose(f1);
	fclose(f2);
	fclose(f);
}
int main(){
	FILE* f;
	f = fopen("111.txt","r");
	int abc =record(f,100);
	fclose(f);
	printf("%d",abc);
	FILE *f1;
	FILE *f2;
	int id = 2;
	char a[11]="temp0";
	char b[11]= "temp1.txt";
//	strcpy(&a,"temp0\0");
//	strcpy(&b,"temp1.txt\0");
	f1 = fopen("temp0","r");
	f2 = fopen("temp1.txt","r");
	FILE* g;
	FILE* temp;
	char xyz[5];
	int iid = id;
	mergeFiles(f1,f2,1);
	g = fopen("t1","r");
	while(id<abc){
	sprintf(b,"temp%d.txt",id++);
	temp = fopen(b,"r");
	mergeFiles(temp,g,iid);
	sprintf(xyz,"%s%d\0","t",iid++);
	g = fopen(xyz,"r");
	}
	fclose(g);
}
 
