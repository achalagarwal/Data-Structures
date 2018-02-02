#include<stdio.h>
#include<stdlib.h>
int main(){
FILE *f;
f = fopen("test","r");
int a;
char ab[10];
char cd[10];
int b;
fscanf(f,"%s,%d/%d,%s",&ab[0],&a,&b,&cd[0]);
fclose(f);
}
