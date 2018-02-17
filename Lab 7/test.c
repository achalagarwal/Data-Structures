#include"list.h"
#include"bsort.h"
#include<stdio.h>
int main(){
	//List l = createList();
	BBucket b = createBBucket();
	FILE *f = fopen("data.txt","r");
	/*for(int i = 1;i<15;i++)
	add(b,i);
	//remove(b);
	for(int i = 0;i<11;i++)
		printf("%d",rem(b)->a);
*/	int num;

	int a = fscanf(f,"%d",&num);
	int count = 1;
	while(a!=EOF){
		printf("%d\n",count);
		count++;
		addB(b,num);
		a = fscanf(f,"%d",&num);
	}
	fclose(f);
	Node n = remB(b);
	while(n!=NULL){
		printf("%d\n",n->a);
		n = remB(b);
	}
	}
