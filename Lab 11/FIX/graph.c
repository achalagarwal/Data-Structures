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
		//lookup
		g -> arr[e->source][e->sink] = 1;
		g->is[e->source] =1;
		g->is[e->sink]=1;
		removeElementFromFront(l);
	}
	g -> edgeList = n;
	return g; 
}

struct temp{
	Array a;
	List l;
};

struct temp getData(List l){
	int* arr = (int*)malloc(sizeof(int)*10);
	int size = 10;
	int count = 0;
	List n = createList();
	 while(isEmpty(l)==0){
                Edge e = getElementFront(l);
                n = addElementToBack(n,e);
		int i =0;
		for(i= 0;i<count;i++){
			if(arr[i] == e->source)
				break;
		}
		if(i==count){
			if(count == size){
				size *=2;
				arr = realloc(arr,sizeof(int)*size);
			}
			arr[count++] = e->source;
		}
		//add
		for(i = 0;i<count;i++){
			if(arr[i] == e->sink)
				break;
		}
		if(i == count){
		  if(count == size){
                                size *=2;
                                arr = realloc(arr,sizeof(int)*size);
                        }
                        arr[count++] = e->sink;
                }

		//add

                //g -> arr[e->source][e->sink] = 1;
                //g->is[e->source] =1;
                //g->is[e->sink]=1;
                removeElementFromFront(l);
        }
	Array a = (Array)malloc(sizeof(struct array));
	a->vertices = arr;
	a->size = count;
	struct temp t;
	t.a = a;
	t.l = n;
	return t;
}

Graph createGraph(List l){
	Graph g = (Graph)malloc(sizeof(struct graph));
	struct temp t = getData(l);
	g->size = t.a->size;
	g -> arr = (int**)malloc(sizeof(int*)*(size));
	g->is = (int*)malloc(sizeof(int)*g->size);
	for(int i = 0;i<size;i++)
		g->arr[i] = (int*)malloc(sizeof(int)*size);
	for(int i =0;i<size;i++)
		for(int j = 0;j<size;j++)
			g->arr[i][j] = 0;
	g = fillGraph(g,l);
	int total =0;
	for(int i =0 ;i<size;i++)
		if(g->is[i] == 1)
			total++;
	g->v = (int*)malloc(sizeof(int)*total);
	int index = 0;
	g->vertices = total;
	for(int i = 0;i<size;i++)
		if(g->is[i] == 1)
			g->v[index++] = i;
	int** copy = (int**)malloc(sizeof(int*)*g->vertices);
	for(int i = 0;i< g->vertices;i++)
		copy[i] = (int*)malloc(sizeof(int)*g->vertices);
	for(int i =0;i< g->vertices;i++){
		for(int j = 0;j< g->vertices;j++){
			copy[i][j] = g->arr[g->v[i]][g->v[j]];
		}
	}
	free(g->arr);
	g->arr = copy;
	return g;
}




int main(){
	FILE* f = fopen("graph0.txt","r");
	List l = edgeList(f);
	//printf("Total Number %d\n",max);
	/*Graph g = createGraph(l);
	Array a = topologicalSort(g);
	for(int i =0;i< a->size;i++)
			printf("%d\n",a->vertices[i]);
	*/
	//struct temp t = getData(l);
	//max = t.a->size-1;
	Graph g = createGraph(l);
	Array a = topologicalSort(g);
}

