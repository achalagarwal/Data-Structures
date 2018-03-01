#ifndef ELEMENT
#define ELEMENT
struct _element{
    int value;
};
typedef int Key;
typedef struct _element* Element;
#endif
struct _dnode;
typedef struct _dnode* DNode;
struct _dlist;
typedef struct _dlist* DList;
struct _dlist{
    DNode head;
    DNode tail;
};
struct _dnode{
    DNode next;
    DNode prev;
    Element e;
};
int sizeDList(DList dl);
DList removeOldest(DList dl);
DList insertElement(DList dl, Element e);
DList insertNode(DList dl, DNode n);
DList createDList();
