#include"poly.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int randomG(int bound){
    return rand()%bound;
}

Poly fillP(Poly p,int maxE, int maxC){
    int n = 2;
    while(n-->0){
        int e = randomG(maxE);
        int c = randomG(maxC);
        p = addX(p,e,c);
    }
    return p;
}


int main(){
    Poly p1 = createP();
    p1 = fillP(p1,10000000,100);
    printf("Polynomial 1\n");
 //   printP(p1);
    fflush(NULL);
    Poly p2 = createP();
    p2 = fillP(p2,10,100);
    printf("+\nPolynomial 2\n");
  //  printP(p2);
    fflush(NULL);
    printf("=\n");
    clock_t start,end;
    start = clock();
    Poly p3 = addPoly(p1,p2);
    end = clock();
  //  printP(p3);
    printf("Added Once in %lf seconds\n",(double)(end - start) / CLOCKS_PER_SEC);
    fflush(NULL);
    printf("Now  Using Fast Poly Add\n");
    start = clock();
    Poly p4= addPolyFast(p1,p2);
    end = clock();
    printf("Added Once in %lf seconds\n",(double)(end - start) / CLOCKS_PER_SEC);
    //printP(p4);
}
