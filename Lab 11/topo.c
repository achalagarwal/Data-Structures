#include"topo.h"
#include<stdlib.h>
Array topologicalSort(Graph G){
	int size = G->size;
	int* arr = (int*)malloc(sizeof(int)*size);
	int** copy = (int**)malloc(sizeof(int*)*size);
	for(int i = 0;i<size;i++)
		copy[i] = (int*)malloc(sizeof(int)*size);
	for(int i =0;i<size;i++)
		for(int j = 0;j<size;j++)
			copy[i][j] = G->arr[i][j];
	int* edgeCount = (int*)malloc(sizeof(int)*size);
	for(int i = 0;i<size;i++)
		for(int j = 0;j<size;j++)
			edgeCount[j]+=G->arr[i][j];
	int index = 0;
	while(index<size){
	for(int i = 0;i<size;i++){
		if(edgeCount[i] ==0){
			arr[index++] = i;
			edgeCount[i] = -1;
		}
	}
	for(int i = 0;i<size;i++){
		if(edgeCount[i]>0){
			for(int j = 0;j<size;j++){
				if(G->arr[j][i] ==1){
					if(edgeCount[j] == -1){
						edgeCount[i] -=1;
						G->arr[j][i] =0;}
				}
			}
		}
	}
	}
	Array a = (Array)malloc(sizeof(struct array));
	a -> vertices = arr;
	a ->size =size;
	G->arr = copy;
	return a;

}
