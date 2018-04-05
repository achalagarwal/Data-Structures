#include<stdlib.h>
#include"graph.h"

Graph createGraph(int n){
	Graph g = (Graph)malloc(sizeof(struct graph));
	g->n = n;
	g->adj = (int**)malloc(sizeof(int*)*n);
	for(int i = 0;i<n;i++)
		g->adj[i] = (int*)malloc(sizeof(int)*n);
	return g;
}

Graph addEdge(Graph g,Vertex v, Vertex a){
	int** vs = g->adj;
	int* vss = vs[v->index];
	vss[a->index] = 1;
	return g;
}

Vertex createVertex(int a){
	Vertex v = (Vertex)malloc(sizeof(struct vertex));
	v -> index = a;
	return v;
}

Enumeration getAdjacent(Graph g, Vertex v){
	Vertex* vs = (Vertex*)malloc(sizeof(int)*(degree(g,v)));
	int* cs = g->adj[v->index];
	int index=0;
	for(int i =0;i< g->n;i++){
		if(cs[i] == 1)
			vs[index++] = createVertex(i);
	}
	Enumeration e = (Enumeration)malloc(sizeof(struct enumeration));
	e -> size = index;
	e -> arr = vs;
	return e;
}

int degree(Graph g,Vertex v){
	int* cs = g->adj[v->index];
        int degree=0;
        for(int i =0;i< g->n;i++){
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
		Vertex c = getQ(q);
		popQ(q);
		if(c->index == s->index)
			return 1;
		Enumeration e = getAdjacent(g,c);
		add(q,e);
	}
}
