#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"graph.h"

Vertex createVertex(int a,int r,int c){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
    v-> has = 0;
    v->row = r;
    v -> url = (char*)malloc(sizeof(char)*50);
    v->col = c;
	return v;
}
Graph createGraph(int n){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->n = n;
	g->adj = (int***)malloc(sizeof(int**)*n);
	for(int i = 0;i<n;i++){
		g->adj[i] = (int**)malloc(sizeof(int*)*n);
        for(int j =0;j<n;j++)
            g->adj[i][j] = (int*)malloc(sizeof(int)*(n*n));
    }
	g->vertices = (Vertex**)malloc(sizeof(Vertex*)*n);
    for(int i = 0;i<n;i++){
        g->vertices[i] = (Vertex*)malloc(sizeof(Vertex)*n);
        for(int j = 0;j<n;j++)
            g->vertices[i][j] = createVertex(0,i,j);
    }
    return g;
}

int hash2(char* string,int n){
    int a = 97;
    int i = 0;
    int hashV = 0;
    while(string[i]!='\0'){
        hashV = (hashV*a + string[i])%105943;
        i++;
    }
    return hashV%n;
}
int hash(char* string,int n){
    int a = 31;
    int i = 0;
    int hashV = 0;
    while(string[i]!='\0'){
        hashV = (hashV*a + string[i])%1000003;
        i++;
    }
    return hashV%n;
}

Vertex addVertex(Graph G, char* url){;
    int row = hash(url,G->n);
    int col = hash2(url,G->n);
    if(G->vertices[row][col]->has == 0){
        G->vertices[row][col]->has =1;
        strcpy(G->vertices[row][col]->url,url);
    return G->vertices[row][col];
    }
    return NULL;
}

Graph addEdge(Graph g,Vertex v, Vertex a){
	int*** vs = g->adj;
	int* vss = vs[v->row][v->col];
	    vss[g->n*(a->row)+a->col] = 1;
	return g;
}

Enumeration getAdjacent(Graph g, Vertex v){
	Vertex* vs = (Vertex*)malloc(sizeof(int)*(degree(g,v)));
	int* cs = g->adj[v->row][v->col];
	int index=0;
	for(int i =0;i< g->n*g->n;i++){
		if(cs[i] == 1)
			vs[index++] = g->vertices[i/(g->n)][i%g->n];
	}
	Enumeration e = (Enumeration)malloc(sizeof(struct enumeration));
	e -> size = index;
	e -> arr = vs;
	return e;
}

int degree(Graph g,Vertex v){
	int* cs = g->adj[v->row][v->col];
        int degree=0;
        for(int i =0;i< g->n*g->n;i++){
                if(cs[i] == 1)
                        degree++;
        }
	return degree;
}

void add(Q q, Enumeration e){
	for(int i = 0;i< e->size;i++){
		pushQ(q,e->arr[i]);
	}
}

int BFS(Graph g,Vertex r,Vertex s){
	Q q = createQ();
	pushQ(q,r);
	while(isEmpty(q)==0){
		Vertex c = getQElement(q);
		popQ(q);
		if(strcmp(c->url,s->url)==0)
			return 1;
		Enumeration e = getAdjacent(g,c);
		add(q,e);
	}
    return 0;
}
int miain(){
    Graph G = createGraph(5);

    printf("DONE");
}
