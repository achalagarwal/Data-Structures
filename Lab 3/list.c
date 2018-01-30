#include"list.h"
#include"memory.h"
#include<stdlib.h>
List createList(int N){
    List ls = (List)myalloc(sizeof(struct list));
    ls->head = NULL;
//    N = 5;
    for(int i = 0;i<N;i++){
        int r = rand();
        Node n = (Node)myalloc(sizeof(struct node));
        n->next = NULL;
        n->value = r;
        if(ls->head==NULL)
            ls->head = n;
        else{
            Node c = ls->head;
            while(c->next!=NULL){
                c = c->next;
            }
            c->next = n;
        }
    }
    return ls;
}
List createCycle(List ls){
    int r = rand();
    if(r%10<5)
      return ls;
    else {
        Node c = ls->head;
        int flag = 0;
         r = rand();
        
       // int r = ls->head->next->next->value;
        Node pointer;
        while(c->next!=NULL){
            if(flag==0&&c->value == r){
                flag = 1;
                pointer =  c;
            }
            c = c->next; //c stores the last node now
        }
        if(flag == 0)
            return ls;
        else
            c->next = pointer;
        return ls;
    }
    return ls;
}

        

