
#include"mergesort.h"
#include<stdlib.h>
#include<stdio.h>
Element mergesort(Element ls, int size){
	if(size<=1)
		return ls;
	else{
		int a = size/2;
		int b = size - a;
		Element ls1 = (Element)malloc(a*sizeof(struct element));
		Element ls2 = (Element)malloc(b*sizeof(struct element));
		int n = 0;
		for(int i = 0; i<a;i++){
			ls1[i] = ls[n++];
		}
		for(int j = 0;j<b;j++){
			ls2[j]= ls[n++];
		}
		ls1 = mergesort(ls1,a);
		ls2 = mergesort(ls2,b);
		merge(ls1,a,ls2,b,ls);
		return ls;
	}
}
