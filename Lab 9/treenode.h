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
#define LIST_ELEMENT_H
#include"iterator.h"
typedef Iterator LElement;
#include"list.h"

struct treenode{
	Iterator i;
	Record r;
};

struct tree{
	TNode root;
    List currentSet;
};

typedef struct tree* Tree;

Tree createTree(int children);

int isEmptyTree(Tree);

Element getRootVal(Tree t);

Iterator getChildren(Tree t);

TNode selectNextNode(Tree t);
Iterator identifyMoreNodes(TNode n);
void addMoreNodes(TNode* set, Iterator i);
