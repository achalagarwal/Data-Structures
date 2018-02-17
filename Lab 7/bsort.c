#include"bsort.h"
#ifndef LIST
#include"list.h"
#endif
#include<stdlib.h>
Bucket createBucket(){
	Bucket b = (Bucket)malloc(9*sizeof(struct bucket));
//	b->lists = (List)malloc(sizeof(struct list)*9);
	for(int i =0;i<9;i++)
	b[i].lists = createList();
	return b;
	}
void add(Bucket b, int a){
	int t = 100;
	int copy = a;
	while(a>=t){
		a/=10;
	}
	//get the second digit
	a = a%10;
	push(&b->lists[a],copy);
	}
	Node rem(Bucket b){
		for(int i = 0;i<10;i++){
			if(b->lists[i].head!=NULL)
				return pop(&b->lists[i]);
			}
			return NULL;
			}
			
