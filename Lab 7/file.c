#include<stdio.h>
#include<stdlib.h>
int main(){
	char num[9];
	char pool[10]="0123456789";
	int j = 1000000;
	FILE *f;
	f = fopen("data.txt","w");
	while(j-->0){
		for(int i = 0;i<9;i++){
			int r;
			if(i==0)
			r = rand()%9 +1;	
			else		
			r = rand()%10;
			num[i] = pool[r];
			}
		int number = atoi(&num[0]);
		fprintf(f,"%d\n",number);
		}
		fclose(f);
		}
