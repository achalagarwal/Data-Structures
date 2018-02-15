#include<stdio.h>
#include<stdlib.h>
int main(){
	char* a;
	int b;
	scanf("%ms %d",&a,&b);
	printf("%u",&a);
	printf("%s %d",a,b);
	scanf("%ms",&a);
	printf("%s",a);
	free(a);
}
