#include"graph.h"
//#include<stdio.h>
#include<stdlib.h>
#include"topo.h"
int max =0;

List edgeList(FILE* f){

	List l = createList();
	int source;
	int sink;
	int a = fscanf(f,"%d %d",&source,&sink);
	if(source > max)
		max = source;
	if(sink > max)
		max = source;
	while(a!=EOF){
		if(source > max)
                	max = source;
		if(sink > max)
                	max = sink;
		Edge e = (Edge)malloc(sizeof(struct edge));
		e->source = source;
		e->sink = sink;
		l = addElementToBack(l,e);
		a = fscanf(f,"%d %d",&source,&sink);
	}
	return l;
}

Graph fillGraph(Graph g, List l){
	List n = createList();
	while(isEmpty(l)==0){
		Edge e = getElementFront(l);
		n = addElementToBack(n,e);
		g -> arr[e->source][e->sink] = 1;
		g->is[e->source] =1;
		g->is[e->sink]=1;
		removeElementFromFront(l);
	}
	g -> edgeList = n;
	return g; 
}

Graph createGraph(List l){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g -> arr = (int**)malloc(sizeof(int*)*(max+1));
	g -> size = max+1;
	g->is = (int*)malloc(sizeof(int)*g->size);
	for(int i = 0;i<=max;i++)
		g->arr[i] = (int*)malloc(sizeof(int)*(max+1));
	for(int i =0;i<=max;i++)
		for(int j = 0;j<=max;j++)
			g->arr[i][j] = 0;
	return fillGraph(g,l);
}




int main(){
	FILE* f = fopen("c.txt","r");
	List l = edgeList(f);
	//printf("Total Number %d\n",max);
	Graph g = createGraph(l);
	Array a = topologicalSort(g);
	for(int i =0;i< a->size;i++)
		if(g->is[a->vertices[i]] == 1)
			printf("%d\n",a->vertices[i]);
}

