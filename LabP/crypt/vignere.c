#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE* file = fopen("data.txt","r");
    int a = fgetc(file);
    FILE** f = (FILE**)malloc(sizeof(FILE*));
    char* ch = (char*)malloc(sizeof(char)*6);
    for(int i = 0;i<26;i++){
        sprintf(ch,"data%d.txt",i);
        f[i] = fopen(ch,"w");
        fclose(f[i]);
    }
    
for(int i = 0;i<26;i++){
sprintf(ch,"data%d.txt",i);
FILE* f2 = fopen(ch,"w");    
    printf("%di\n",i);
    while(a!=EOF){
        a = a - 'A';
        int b = (a+i+1)%26;
        fputc(b+'A',f2);
        a = fgetc(file);
    }
    fclose(f2);
    fclose(file);
    file = fopen("data.txt","r");
    a = fgetc(file);
}

}







