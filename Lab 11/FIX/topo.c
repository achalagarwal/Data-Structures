#include"topo.h"
#include<stdlib.h>
#include<stdio.h>
Array topologicalSort(Graph G){
    int vertices = G->size;
	//int vertices = G->vertices;
	int* arr = (int*)malloc(sizeof(int)*G->vertices);
	int** copy = (int**)malloc(sizeof(int*)*vertices);
	for(int i = 0;i<vertices;i++)
		copy[i] = (int*)malloc(sizeof(int)*vertices);
	for(int i =0;i<vertices;i++)
		for(int j = 0;j<vertices;j++)
			copy[i][j] = G->arr[i][j];
	printf("\nFinished making a copy\n");
    int* edgeCount = (int*)malloc(sizeof(int)*vertices);
    for(int i = 0;i<vertices;i++)
        edgeCount[i] = 0;
	//init to 0
	for(int i = 0;i<vertices;i++)
		for(int j = 0;j<vertices;j++)
			edgeCount[j]+=G->arr[i][j];
	int index = 0;
	while(index<vertices){
	for(int i = 0;i<vertices;i++){
		if(edgeCount[i] ==0){
			arr[index++] =i;
			edgeCount[i] = -1;
		}
	}
	for(int i = 0;i<vertices;i++){
		if(edgeCount[i]>0){
			for(int j = 0;j<index;j++){
				if(G->arr[arr[j]][i] ==1){
						edgeCount[i] -=1;
						G->arr[arr[j]][i] =0;}
				}
		}
	}
    
    printf("Vertices sorted: %d",index);
    fflush(NULL);
	}
	Array a = (Array)malloc(sizeof(struct array));
	a -> vertices = arr;
	a ->size =vertices;
	G->arr = copy;
	return a;

}
