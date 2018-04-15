#include"poly.h"
#include<stdlib.h>
#include<stdio.h>

Poly createP(){
    Poly p = (Poly)malloc(sizeof(struct polynomial));
    p->root = NULL;
    return p;
}

PNode createX(int exp, int val){
    PNode p = (PNode)malloc(sizeof(struct pnode));
    p->exp = exp;
    p->val = val;
    p->next = NULL;
    return p;
}

Poly addX(Poly p, int exp , int val){
    if(val == 0)
        return p;
    if(p == NULL){
        p = createP();
        return addX(p,exp,val);
    }
    PNode c = p->root;
    if(p->root == NULL){
        p->root = createX(exp,val);
        return p;
    }

    if(c->exp>exp){
        PNode n = createX(exp,val);
        n->next = c;
        p->root = n;
        return p;
    }

    if(c->exp == exp){
        c->val += val;
        if(c->val == 0){
            p->root = c->next;
            free(c);
         }
        return p;
    }
    PNode prev = c;
    c = c->next;
    while(c!=NULL){
        if(c->exp == exp){
            c->val += val;
            if(c->val == 0){
                prev->next = c->next;
                free(c);
            }
            return p;
        }
        if(c->exp>exp){
            PNode n = createX(exp,val);
            prev->next = n;
            n->next = c;
            return p;
        }
        prev = c;
        c = c->next;
    }
    if(c==NULL){
        prev->next = createX(exp,val);
        return p;
    }

    //should never reach
    return p;
}

PNode duplicate(PNode p){
    PNode n = (PNode)malloc(sizeof(struct pnode));
    n->exp = p->exp;
    n->val = p->val;
    n->next = NULL;
    return n;
}
PNode addHelper(PNode a,PNode b){
    PNode c1 = a;
    PNode c2 = b;
    PNode n;
    if(c1!=NULL&&c2!=NULL){
        if(c1->exp<c2->exp){
            n = duplicate(c1);
            c1 = c1->next;
        }
        else{
            n = duplicate(c2);
            c2 = c2->next;
        }
    }
    else if(c1!=NULL){
        n = duplicate(c1);
        c1 = c1->next;
    }
    else if(c2!=NULL){
        n = duplicate(c2);
        c2 = c2->next;
    }

    while(c1!=NULL && c2!=NULL){
        if(c1->exp<c2->exp){
            PNode b = duplicate(c1);
            b->next = n;
            n = b;
            c1 = c1->next;
        }
        else{
            PNode b = duplicate(c2);
            b->next = n;
            n = b;  
            c2 = c2->next;
        }
    }
    while(c1!=NULL){   
        PNode b = duplicate(c1);
        b->next = n;
        n = b;
        c1 = c1->next;
    }
    while(c2!=NULL){
        PNode b = duplicate(c2);
        b->next = n;
        n = b;
        c2 = c2->next; 
    }
    return n;
}




void destroyX(PNode c){
    while(c!=NULL){
        PNode t = c->next;
        free(c);
        c = t;
    }
}


Poly addPolyFast(Poly a, Poly b){
    Poly p = createP();
    PNode n = addHelper(a->root,b->root);
    PNode c = p->root;
    while(n!=NULL){
        p = addX(p,n->exp,n->val);
        n = n->next;
    }
    destroyX(n);
    return p;
}
Poly addPoly(Poly a, Poly b){
    Poly p = createP();
    PNode c = a->root;
    while(c!=NULL){
        p = addX(p,c->exp,c->val);
        c = c->next;
    }
    c = b->root;
    while(c!=NULL){
        p = addX(p,c->exp,c->val);
        c=c->next;
    }
    return p;
}

void printP(Poly p){
    if(p==NULL)
        return;
    PNode c = p->root;
    while(c!=NULL){
        printf("%d*(x^%d)\t",c->val,c->exp);
        c = c->next;
    }
    printf("\n");
}
