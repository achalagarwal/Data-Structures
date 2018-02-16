#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char alphs[] = "abcdefghijklmnopqrstuvwxyz";
	char nums[] = "0123456789";

	char *temp1 = (char*)malloc(sizeof(char)*10);
	char *temp2 = (char*)malloc(sizeof(char)*12);
	long long temp3;
	FILE* f= fopen("haha.txt","w");
	int j = 50000000;
	while(j-->0){
		for(int i = 0;i<12;i++){
			int rand1 = rand();
			if(i == 0)
				rand1 = rand1%9 + 1;
			else
				rand1 = rand1%10;
			temp2[i] = nums[rand1];
			temp3 = atoll(temp2);
		}
		for(int i =0;i<10;i++){
			int rand2 = rand();
			rand2 = rand2%26;
			//add null here
			temp1[i] = alphs[rand2];
		}
		fprintf(f,"%s %lld\n",temp1,temp3);
	}
	fclose(f);
}
