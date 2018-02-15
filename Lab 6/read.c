#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"qsort.h"
struct qair{
Employee emps;
int count;
};
struct qair read(){
	FILE* f;
	f = fopen("a.txt","r");
	char* name;
	long long id;
	int a = fscanf(f,"%ms %Ld",&name,&id);
	Employee emps = (Employee)malloc(10*sizeof(struct employee));
	int count = 0;
	int size = 10;
	while(a!=EOF){
		if(count+1==size){
			emps = (Employee)realloc(emps,sizeof(struct employee)*2*size);
			size = size*2;
		}
		emps[count].empID = id;
		int l = strlen(name);
		emps[count].name = (char*)malloc(sizeof(char)*l);
		strcpy(emps[count].name,name);
		count++;
		a = fscanf(f,"%ms %Ld",&name,&id);
	}
	struct qair ab;
	ab.emps = emps;
	ab.count = count;
	fclose(f);
	return ab;
}
int main(){
	Employee emps;
	struct qair q  = read();
	//int size = sizeof(emps)/sizeof(struct employee);

	emps = quickSort(q.emps,0,q.count,0);
}
