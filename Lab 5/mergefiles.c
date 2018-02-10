#include"record.c"
#ifndef DEFINITIONS
#include"list.h"
#endif
FILE* mergeFiles(FILE* f1, FILE *f2){
	FILE* f;
	f = fopen("tx","w");
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
	return f;
}
