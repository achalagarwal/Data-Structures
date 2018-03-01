#include"Element.h"
#include"HashTable.h"
#include<stdio.h>
#include<stdlib.h>

int main(){

/*
    //List definition
    DList dl = createDList();
    
    //Element definitions
    Element e1 = createElement("www.google.com\0" , 1886481349);
    Element e2 = createElement("www.facebook.com\0", 123313413);
    Element e3 = createElement("www.verge.com\0", 13741734);
    
    //operations
    dl = insert(dl, e1);
    dl = insert(dl, e2);
    dl = insert(dl, e3);

    //clean list
    dl = removeOldest(dl);
    dl = removeOldest(dl);
//    dl = removeOldest(dl);

    printf("Size of List is %d", sizeDList(dl));
*/

    //create hash table
    HTable ht = createHTable(10);
    
    //Element definitions
    Element e1 = createElement("www.google.com\0" , 1886481349);
    Element e2 = createElement("www.facebook.com\0", 123313413);
    Element e3 = createElement("www.verge.com\0", 13741734);
    
    //operations
    ht = insertElementHT(ht, e1);
    ht = insertElementHT(ht, e2);
    ht = insertElementHT(ht, e3);


}
