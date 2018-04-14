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

/* C implementation QuickSort */
 
// A utility function to swap two elements
void swapp(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swapp(&arr[i], &arr[j]);
        }
    }
    swapp(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    while (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        low = pi+1;

//        quickSort(arr, pi + 1, high);
    }
}
void sortFile(FILE* f,char* prefix,int index){
   int* arr = (int*)malloc(sizeof(int)*10);
   int size = 10;
   int count = 0;
   int v;
   int a = fscanf(f,"%d",&v);
   while(a!=EOF){
    if(count == size){
        size *=2;
        arr = realloc(arr,size*sizeof(int));
    }
    arr[count++] = v;
    a = fscanf(f,"%d",&v);
   }
   arr = realloc(arr,count*sizeof(int));
   quickSort(arr,0,count-1);
   fclose(f);
   char* name = (char*)malloc(sizeof(char)*10);
   sprintf(name,"%s%d",prefix,index);
   f = fopen(name,"w");
   for(int i = 0;i<count;i++)
       fprintf(f,"%d\n",arr[i]);
   fclose(f);
   free(arr);
}

void sortk(struct array filedata){
    FILE** arr = (FILE**)filedata.arr;
    int files = filedata.size;
    printf("Starting K-way sort\n");
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
    printf("********************\n");
    struct array a = getFiles("file\0");
    printf("Sorting individual files\n");
    for(int i = 0;i<a.size;i++){
        sortFile(a.arr[i],"file\0",i);
        printf("Sorted File %d/%d\n",(i+1),a.size);
    }
    a = getFiles("file\0");
    sortk(a);
    printf("********************\n");

}
