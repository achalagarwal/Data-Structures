#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int isDirectory(struct stat* s){
    if(s==NULL)
        return -1;
    if(S_ISDIR(s->st_mode))
        return 1;
    else 
        return 0;
}



int main(){

    struct stat* s = (struct stat*)malloc(sizeof(struct stat));
    FILE* f = fopen("Achal","r");
    DIR* d;
    struct dirent* dir;
    d = opendir(".");
    if(d){
        dir = readdir(d);
        while(dir!=NULL){
            printf("%s\n",dir->d_name);
        dir= readdir(d);
        }
    }
    /*
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
    */
}
