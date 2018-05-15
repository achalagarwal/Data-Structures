#include<stdio.h>
#include<stdlib.h>





void printMaze(int** arr, int n, int row, int col){
    for(int i = n-1;i>=0;i--){
        for(int j =0;j<n;j++){
            if(j!=col || i!=row)
                printf("%d\t",arr[i][j]);  
            else
                printf(".%d\t",arr[i][j]);

        }
        printf("\n");
    }
}


void initMaze(int** arr, int n){
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            arr[i][j] = rand()%8-1;
}

struct pos{
    int n;
    int t;
    int e;
};

typedef struct pos* Pos;

struct vertex{
    int row;
    int col;
    int top;
};
typedef struct vertex* Vertex;

int main(){
   int n = 5; //edge size of square 
   int **arr = (int**)malloc(sizeof(int*)*n);
   for(int i = 0;i<n;i++)
       arr[i] = (int*)malloc(sizeof(int)*n);
   initMaze(arr,n); 
   printMaze(arr,n,0,0);
   //init pos
   int s = arr[0][0];
   if(s == 0){
        for(int i = 1;i<=6;i++){
            int t = i;
            if(t==1||t==6){
                int n = 3;
                int e = 2;
                struct pos p;
                p.
                int n = 4;
                int e = 2;
                int n = 3;
                int e = 5;
                int n = 4;
                int e = 5;
                
            }
        }
    }
