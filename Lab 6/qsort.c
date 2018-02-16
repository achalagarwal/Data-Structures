#include<stdio.h>
#include<stdlib.h>
#include"qsort.h"
/*Employee quickSort(Employee emps,int start, int end,int min){
	Stack s = (Stack)malloc(sizeof(struct stack));
	push(s,start,end);
	return quickSortInternal(emps,s,min);
}*/
Employee quickSortInternal(Employee emps,Stack s, int min){
	//partition
	//create a wall
	//before wall < pivot elements 
	//after wall  > pivot elements
	//quicksort before wall if size>1
	//quicksort after wall if size>1
	//inclusive of end and start so elements = end -start + 1
	while(s->head!=NULL){
	Pair p = pop(s);
	int end = p->end;
	int start = p->start;
    while(end - start>min){
	int  mid = start+(end-start)/2;
    int pos;
	long long id1 = emps[start].empID;
	long long id2 = emps[mid].empID;
	long long id3 = emps[end].empID;
	if(id1>=id2){
		if(id1>=id3){
			if(id2>=id3){
				pos = mid;
			}
			else{
				pos = end;
			}
		}
		else{
			pos = start;
		}
	}
	else{
		if(id2>=id3){
			if(id1>=id3){
				pos = start;
			}
			else{
				pos = end;
			}
		}
		else{
			pos = mid;
		}
	}
    struct employee temp;
	int i = start;
	temp = emps[pos];
	emps[pos]=emps[start];
	emps[start] = temp;
	i++;
	int wall = start+1;
	Employee pivot = &emps[start];
	//wall is on top of the first element>pivot
	while(i<=end){
		if(emps[i].empID<pivot->empID){
			temp = emps[i];
			emps[i] = emps[wall];
			emps[wall]=temp;
			wall++;
		}
		i++;
	}
	//swap pivot back with ele at wall-1
	temp = emps[start];
	emps[start] = emps[wall-1];
	emps[wall-1] = temp;
	if(wall-start>2){
		s = push(s,start,wall-2);
        //printf("%d %d\n",start,wall-2);   
    }
	if(end-wall>0){
        start = wall;
        end = end;
	//	s=push(s,wall,end);
    }
    else
        end = start;
	}
}
}
Employee quickSort(Employee emps,int start, int end,int min){
        Stack s = createStack();
	push(s,start,end);
	quickSortInternal(emps,s,min);
	return emps;
}

