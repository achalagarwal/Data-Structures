#define GRAPH_H
//element for vertex

struct vertex{
	int index;
};

typedef struct vertex* Vertex;

#define QUEUE_ELEMENT_H
typedef Vertex QElement;
#include"queue.h"

struct graph{
	Vertex* vertices;
	int n;
	int** adj;
};

typedef struct graph* Graph;

struct enumeration{
	Vertex* arr;
	int size;
};

typedef struct enumeration* Enumeration;

Graph createGraph(int numV);
Enumeration getAdjacent(Graph g, Vertex v);
Graph addEdge(Graph G, Vertex v, Vertex a);
int degree(Graph g, Vertex v);

