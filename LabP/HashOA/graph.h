#define GRAPH_H
#include<stdio.h>
struct edge{
	int source;
	int sink;
};

typedef struct edge* Edge;

typedef Edge LElement;

#define LIST_ELEMENT_H
#include"list.h"

struct graph{
	int** arr;
	HT v;
	int size;
	List edgeList;
};

typedef struct  graph* Graph;


Graph createGraph(int size);
List edgeList(FILE* f);

