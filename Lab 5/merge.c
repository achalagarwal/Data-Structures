#include"merge.h"
void merge(Element ls1,int s1,Element ls2,int s2,Element ls){
	int n1=0;
	int n2 =0;
	int n = 0;
	while(n1<s1&&n2<s2){
		 if(ls1[n1].key<ls2[n2].key){
                	ls[n++] = ls1[n1++];
		}
		else{ //if(ls1[n1].key<ls2[n2].key){
         		ls[n++] = ls2[n2++];
		}
	}
	if(n1<s1){
		while(n1<s1){
			ls[n++] = ls1[n1++];
		//	n = n->next;
		//	n1= n1->next;
		}
	}
	else if(n2<s2){
		while(n2<s2){
			ls[n++] = ls2[n2++];
		//	n = n->next;
		//	n2 = n2->next;
		}
	}

}
