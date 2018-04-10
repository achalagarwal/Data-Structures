#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(){

    struct stat* s = (struct stat*)malloc(sizeof(struct stat));
    FILE* f = fopen("Achal","r");
    DIR* c;
    do{
    int fd = fileno(f);
    int fs = fstat(fd,s);
    if(S_ISDIR(s->st_mode)){
    printf("yes");
    c = fdopendir(fd);
    struct dirent* d = readdir(c);
    if(d==NULL)
        f = fopen("treenode.c","r");
    }
    else break;
    }
    while(1);
}
