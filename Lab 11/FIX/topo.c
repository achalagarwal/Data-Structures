#include"topo.h"
#include<stdlib.h>
Array topologicalSort(Graph G){
	//int size = G->size;
	int vertices = G->vertices;
	int* arr = (int*)malloc(sizeof(int)*G->vertices);
	int** copy = (int**)malloc(sizeof(int*)*vertices);
	for(int i = 0;i<vertices;i++)
		copy[i] = (int*)malloc(sizeof(int)*vertices);
	for(int i =0;i<vertices;i++)
		for(int j = 0;j<vertices;j++)
			copy[i][j] = G->arr[i][j];
	int* edgeCount = (int*)malloc(sizeof(int)*vertices);
	//init to 0
	for(int i = 0;i<vertices;i++)
		for(int j = 0;j<vertices;j++)
			edgeCount[j]+=G->arr[i][j];
	int index = 0;
	while(index<vertices){
	for(int i = 0;i<vertices;i++){
		if(edgeCount[i] ==0){
			arr[index++] =G-> v[i];
			edgeCount[i] = -1;
		}
	}
	for(int i = 0;i<vertices;i++){
		if(edgeCount[i]>0){
			for(int j = 0;j<vertices;j++){
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
	a ->size =vertices;
	G->arr = copy;
	return a;

}
