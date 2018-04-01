#define TREENODE_H 
#ifndef RECORD_H
#define RECORD_H 
struct record{
	int value;
};
typedef struct record* Record;
#endif

struct treenode;
typedef struct treenode* TNode;

typedef TNode Element;
#define ITERATOR_ELEMENT_H
#include"iterator.h"

struct treenode{
	Iterator i;
	Record r;
};

struct tree{
	TNode root;
};

typedef struct tree* Tree;

Tree createTree(int children);

int isEmpty(Tree);

Element getRootVal(Tree t);

Iterator getChildren(Tree t);
