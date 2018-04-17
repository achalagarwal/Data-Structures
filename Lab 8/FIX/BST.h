#define BST_H

struct bnode;
typedef struct bnode* BNode;

struct bnode{
    BNode left;
    BNode right;
    void* e;
    int height;
};

struct bst;
typedef struct BST* BST;

struct BST{
    BNode root;
    int size;
    int (*compare)(void*,void*);
};

BST createBST(int(*f)(void*,void*));
BST insertInBST(BST b, void* e);
BST removeFromBST(BST b, void* e);
void* getFromBST(BST b,void* e);


