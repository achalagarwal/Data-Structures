#ifndef GRAPH_H
#include"graph.h"
#endif

struct array{
	int* vertices;
	int size;
};

typedef struct array* Array;

Array topologicalSort(Graph G);

