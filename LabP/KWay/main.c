#include"heap.h"
#include<stdio.h>
#include<stdlib.h>

struct array{
    void** arr;
    int size;
};
//do not spam
typedef struct array* Array;

struct element{
    int value;
    int fileIndex;
};

typedef struct element* Element;

int compare(void* a, void* b){
    if(((Element)a)->value<((Element)b)->value)
        return -1;
    else if(((Element)a)->value>((Element)b)->value)
        return 1;
    else
        return 0;
}


int read(FILE* f){
    int value;
    int a = fscanf(f,"%d",&value);
    if(a!=EOF)
        return value;
    else
        return EOF;
}

Element createElement(int value, int index){
    Element e = (Element)malloc(sizeof(struct element));
    e -> value = value;
    e -> fileIndex = index;
    return e;
}

void sort(struct array filedata){
    FILE** arr = (FILE**)filedata.arr;
    int files = filedata.size;
    Heap h = createHeap(files,&compare);
    int eofs = 0;
    for(int i = 0;i<files;i++){
        int v = read(arr[i]);
        if(v!=EOF)
            insertElement(h,createElement(v,i));
        else
            eofs++;
    }
    
    FILE* file = fopen("sorted.txt","w");
    while(1){
        Element t =(Element) getMin( h);
        deleteMin(h);
        fprintf(file,"%d\n",t->value);
        int v = read(arr[t->fileIndex]);
        if(v!=EOF){
            insertElement(h,createElement(v,t->fileIndex));
        }
        else{
            eofs++;
            printf("End of file %d/%d : %d\n",eofs,files,t->fileIndex);
        }
        if(eofs == files)
            break;

    }
    fclose(file);
    return;

    


}


struct array getFiles(char* prefix){
    
    FILE** files = (FILE**)malloc(sizeof(FILE*)*10);
    int size = 10;
    int count = 0;
    char* name = (char*)malloc(sizeof(char)*20);
    sprintf(name,"%s%d",prefix,count);
    FILE* f = fopen(name,"r");
    while(f!=NULL){
        if(count==size){
            size *=2;
            files = realloc(files,sizeof(FILE*)*size);
        }
        files[count++] = f;
        sprintf(name,"%s%d",prefix,count);
        f = fopen(name,"r");
    }
    files = realloc(files,sizeof(FILE*)*count);
    struct array a;
    a.arr =(void**) files;
    a.size = count;
    return a;
}

int main(){
    struct array a = getFiles("file\0");
    sort(a);

}
