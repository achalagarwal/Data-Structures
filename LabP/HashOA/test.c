#include"hash.h"
#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

struct element{
    int value;
    int index;
};

typedef struct element* Element;


/* Define two functions 
   isEqual - compares two elements for equality
   hash - returns bounded hash value
*/

int hash(void* e, int bound){
    int x = ((Element)e)->value;
    x = ((x >> 16) ^ x) * 0x45d9f3b % bound;
    x = ((x >> 16) ^ x) * 0x45d9f3b % bound;
    x = (x >> 16) ^ x;
    return x%bound;
}

int isEqual(void* e1, void* e2){
    if(((Element)e1)->value == ((Element)e2)->value)
        return 1;
    else
        return 0;
}

Element createElement(int v,int i){
    Element e = (Element)malloc(sizeof(struct element));
    e->value = v;
    e->index = i;
    return e;
}


Graph createGraph(int size){
    Graph g = (Graph)malloc(sizeof(struct graph));
    int** adj = (int**)malloc(sizeof(int*)*size);
    for(int i = 0;i<size;i++)
        adj[i] = (int*)malloc(sizeof(int)*size);
    for(int i = 0;i<size;i++)
        for(int j = 0;j<size;j++)
            adj[i][j] = 0;
    g -> arr = adj;
    g -> size = size;
    return g;
}

Graph createGraphFromFile(char* name){
    HT ht = createHT(10000000,&hash,&isEqual);
    FILE* f = fopen(name,"r");
    int source;
    int sink;
    int a = fscanf(f,"%d %d",&source,&sink);
    int total = 0;
    List l = createList();

    while(a!=EOF){
        Edge e = (Edge)malloc(sizeof(struct edge));
        e -> source = source;
        e -> sink = sink;
        l = addElementToBack(l,e);
        if(addToHT(ht,createElement(source,total))==1)
            total++;
        if(addToHT(ht,createElement(sink,total))==1)
            total++;
        a = fscanf(f,"%d %d",&source,&sink);
    }
//    printf("Misses = %d",total);
    Graph g = createGraph(total);
    while(isEmpty(l)==0){
        Edge e = getElementFront(l);
        Element source = createElement(e->source,-1);
        Element sink = createElement(e->sink,-1);
        g->arr[((Element)(ht->table[lookup(ht,source)]))->index][((Element)(ht->table[lookup(ht,sink)]))->index] = 1;
        removeElementFromFront(l);
    }
    g->v = ht;
    return g;
}

int main(){
    Graph g = createGraphFromFile("c.txt");
    printf("Done");
}



