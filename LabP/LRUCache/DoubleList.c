#include"DoubleList.h"
#include<stdio.h>
#include<stdlib.h>
#ifdef MEM
    malloc = myalloc;
    realloc = myrealloc;
    free - myfree;
#endif

// Creates and Returns a DList

DList createDList(){
    DList dl = (DList)malloc(sizeof(struct _dlist));
    dl -> head = NULL;
    dl -> tail = NULL;
    return dl;
}

// Returns the size of DList

int sizeDList(DList dl){
    DNode n = dl -> tail;
    int count = 0;
    while(n != NULL){
        n = n -> next;
        count++;
    }
    return count;
}

// Inserts Element inside the DList

DList insertElement(DList dl, Element e){

    //create node from element
    DNode n = (DNode)malloc(sizeof(struct _dnode));
    n -> e = e;

    //insert node into list
    return insertNode(dl, n);
}

// Inserts Node inside the DList

DList insertNode(DList dl, DNode n){
    
    // if empty node
    if(n == NULL)
        return dl;

    //initialise node to be added
    n -> prev = NULL;
    n -> next = dl -> tail;

    //if empty list
    if(sizeDList(dl) == 0)
        dl -> head = n;
    
    // insert in list
    dl -> tail = n;
    
    if( n -> next != NULL)
        n -> next -> prev = n;

    return dl;
}

// Removes Node from inside the DList

DList removeNode(DList dl, DNode n){
    
    //if list is empty
    if(sizeDList(dl) == 0)
        return dl;
    
    //if node is the first element
    if(dl -> head == n){

        // if node is the only element
        if(sizeDList(dl) == 1){
            dl -> head = NULL;
            dl -> tail = NULL;

            //free node

            return dl;
        }
        
        // else if other elements are present
        dl -> head = n -> prev;
        dl -> head -> next = NULL;

        //free node

        return dl;
    }

    //if node is the last element and other elements are present
    if(dl -> tail == n){
        dl -> tail = n -> next;
        dl -> tail -> prev = NULL;

        //free node

        return dl;
    }
    
    // if node is a middle element (implicit)
    n -> prev -> next = n -> next;
    n -> next -> prev = n -> prev;
    
    //free node
    
    return dl;
}

DList removeOldest(DList dl){
  
    //get oldest node
    DNode n = dl -> head;

    //remove node n 
    return  removeNode(dl,n);
}
