#include"cycle.h"
#include<stdlib.h>
#include<stdio.h>
int HareTort(List ls){
    if(ls->head == NULL)
        return 0;
    if(ls->head->next==ls->head)
        return 1;
    else if(ls->head->next->next == ls->head)
        return 1;
    else{
        Node c = ls->head;
        Node f = ls->head->next;
        while(1){
            if(f->next == NULL || f->next->next == NULL)
                return 0;
            else if(f->next == c || f->next->next == c)
                return 1;
            if(c==NULL)
                return 0;
            c = c->next;
            f = f->next->next;
        }
    }
}
int LinkReversal(List ls){
    Node p = ls->head;
    if(p==NULL)
        return 0;
    Node c = ls->head->next;
    Node temp;
    while(1){
        temp = c;
        if(c==NULL)
            return 0;
        else if(c == ls->head)
            return 1;
        c = c->next;
        temp->next = p;
        p = temp;
    }
}



        

