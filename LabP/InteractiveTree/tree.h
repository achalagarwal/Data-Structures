


struct tnode;
typedef struct tnode* TNode;
typedef TNode LElement;

#define LIST_ELEMENT_H
#include"list.h"


struct tnode{
    int value;
    List l;
};

struct tree{
    TNode root;
};

typedef struct tree* Tree;


Tree createTree();
Tree fillTree(Tree t);


