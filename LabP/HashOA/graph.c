#include"graph.h"
#include<stdio.h>
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


void sort(int *arr,int size){
    for(int i = 1;i<size;i++){
        int v = arr[i];
        int j = i-1;
        for(;j>=0;j--){
            if(v>=arr[j]){
                arr[j+1] = v;
                break;
            }
            else{
                arr[j+1] = arr[j];
            }
            
        }
        if(j==-1)
            arr[0] = v;
    }
}

int binarySearch(int*arr,int size, int v){
    int lo = 0;
    int hi = size-1;
    while(lo<=hi){
    int mid = lo+(hi-lo)/2;
    if(arr[mid]>v)
        hi = mid-1;
    else if(arr[mid]<v)
        lo = mid+1;
    else
        return mid;
    }
    return -1;
}

Graph fillGraph(Graph g, List l){
	List n = createList();
    int count = 0;	
    while(isEmpty(l)==0){
        count++;
        if(count%288==0){
            printf("progress %d\n",count/288);
            fflush(NULL);
        }
		Edge e = getElementFront(l);
		n = addElementToBack(n,e);
		int source =binarySearch(g->v,g->size, e->source);
        int sink = binarySearch(g->v,g->size,e->sink);
		g -> arr[source][sink] = 1;
        
	//	g->is[e->source] =1;
	//	g->is[e->sink]=1;
		removeElementFromFront(l);
	}
	g -> edgeList = n;
	return g; 
}

struct temp{
	Array a;
	List l;
};

void insertSorted(int* arr, int size, int value){
int i = 0;
    for( i = size-1;i>=0;i--){
        if(arr[i]<=value){
            arr[i+1] = value;
            break;
}
        if(arr[i]>value)
            arr[i+1] = arr[i];
    }
if(i == -1)
    arr[0] = value;
}

struct temp getData(List l){
	int* arr = (int*)malloc(sizeof(int)*10);
	int size = 10;
	int count = 0;
	List n = createList();
	 while(isEmpty(l)==0){
                Edge e = getElementFront(l);
                n = addElementToBack(n,e);
		int i =0;
		i = binarySearch(arr,count,e->source);
		if(i==-1){
			if(count == size){
				size *=2;
				arr = realloc(arr,sizeof(int)*size);
			}
            insertSorted(arr,count++,e->source);
			//arr[count++] = e->source;
		}
		//add
		i = binarySearch(arr,count,e->sink);
		if(i == -1){
		  if(count == size){
                                size *=2;
                                arr = realloc(arr,sizeof(int)*size);
                        }
            insertSorted(arr,count++,e->sink);    
          //          arr[count++] = e->sink;
        }
    

		//add

                //g -> arr[e->source][e->sink] = 1;
                //g->is[e->source] =1;
                //g->is[e->sink]=1;
                removeElementFromFront(l);
                printf("current count: %d\n",count);
                fflush(NULL);
        }
	Array a = (Array)malloc(sizeof(struct array));
	a->vertices = arr;
	a->size = count;
    for(int i  = 0;i<count;i++)
        printf("%d\n",arr[i]);
	struct temp t;
	t.a = a;
	t.l = n;
	return t;
}

Graph createGraph(List l){
	Graph g = (Graph)malloc(sizeof(struct graph));
	struct temp t = getData(l);
	printf("Parsed List: %d",t.a->size);
    fflush(NULL);
    g->size = t.a->size;
    int size = g->size;
    l = t.l;
    g->v = t.a->vertices;
	g -> arr = (int**)malloc(sizeof(int*)*(size));
	//g->is = (int*)malloc(sizeof(int)*g->size);
	for(int i = 0;i<size;i++)
		g->arr[i] = (int*)malloc(sizeof(int)*size);
	for(int i =0;i<size;i++)
		for(int j = 0;j<size;j++)
			g->arr[i][j] = 0;
	g = fillGraph(g,l);
    printf("Finished filling adj matrix");
//	int total =0;
	//for(int i =0 ;i<size;i++)
	//	if(g->is[i] == 1)			total++;
	//g->v = (int*)malloc(sizeof(int)*total);
//	int index = 0;
	//g->vertices = total;
	//for(int i = 0;i<size;i++)
	//	if(g->is[i] == 1)
	//		g->v[index++] = i;
	//int** copy = (int**)malloc(sizeof(int*)*g->vertices);
	//for(int i = 0;i< g->vertices;i++)
	//	copy[i] = (int*)malloc(sizeof(int)*g->vertices);
	//for(int i =0;i< g->vertices;i++){
	//	for(int j = 0;j< g->vertices;j++){
	//		copy[i][j] = g->arr[g->v[i]][g->v[j]];
	//	}
	//}
	//free(g->arr);
	//g->arr = copy;
	return g;
}




int main(){
	FILE* f = fopen("c.txt","r");
	List l = edgeList(f);
	//printf("Total Number %d\n",max);
	/*Graph g = createGraph(l);
	*/
	//struct temp t = getData(l);
	//max = t.a->size-1;
    //printf("%d\n",t.a->size);
    //sort(t.a->vertices,t.a->size);
    //printf("%d",binarySearch(t.a->vertices,t.a->size,1000));
	Graph g = createGraph(l);
	Array a = topologicalSort(g);
	for(int i =0;i< a->size;i++)
			printf("%d\n",a->vertices[i]);
    
}

