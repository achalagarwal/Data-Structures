#include"bsort.h"
#ifndef LIST
#include"list.h"
#endif
#include<stdlib.h>
BBucket createBBucket(){
	BBucket b = (BBucket)malloc(sizeof(struct bigBucket));
	b->buckets = createBucket();
	return b;
	}
	void addB(BBucket b,int a){
		int t = 10;
		int copy = a;
		while(a>=t){
			a/=10;
		}
		add(&b->buckets[a-1],copy);
	}
	Node remB(BBucket b){
		Node n;
		for(int i = 0;i<9;i++){
			n = rem(&b->buckets[i]);
			if(n!=NULL)
				return n;
			}
			return NULL;
		}
				
