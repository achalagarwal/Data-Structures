#include<stdlib.h>
#include<stdio.h>

int** create2D(int row, int col){
    int** arr = (int**)malloc(sizeof(int*)*row);
    for(int i = 0;i<row;i++)
        arr[i] = (int*)malloc(sizeof(int)*col);
    //intitalize to zeros
    for(int i = 0;i<row;i++)
        for(int j = 0;j<col;j++)
            arr[i][j] = 0;
    return arr;
}

int** update2D(int** arr, int oldr,int oldc, int newr, int newc){
    arr = realloc(arr,sizeof(int*)*newr);
    for(int i = 0;i<newr;i++){
        if(i<oldr){
            arr[i] = realloc(arr[i],newc*sizeof(int));
        }
        else{
            arr[i] = (int*)malloc(sizeof(int)*newc);
        }
    }
    //initalize new cells to 0
    for(int i = oldr;i<newr;i++){
        for(int j = 0;j<newc;j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0;i<newr;i++){
        for(int j = oldc;j<newc;j++){
            arr[i][j] = 0;
        } 
    }
    return arr;

}

void print2D(int** arr, int r, int c){
    for(int i = 0;i<c*2;i++)
        printf("*");
    printf("\n");
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    for(int i = 0;i<c*2;i++)
        printf("*");
    printf("\n");
}

//test
int main(){
    int** arr = create2D(10,10);
    print2D(arr,10,10);
    for(int i = 0;i<10;i++)
        for(int j = 0;j<10;j++)
            arr[i][j] = rand()%10;
    print2D(arr,10,10);
    arr = update2D(arr,10,10,5,15);
    print2D(arr,5,15);
    arr = update2D(arr,5,15,10,10);
    print2D(arr,10,10);
    arr = update2D(arr,10,10,15,5);
    print2D(arr,15,5);
    arr = update2D(arr,15,5,10,10);
    print2D(arr,10,10);
}

