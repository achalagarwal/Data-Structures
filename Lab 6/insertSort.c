#include"insort.h"
Employee insertionSort(Employee emps,int size){
	int j = size;
	while(j>0){
		int i = j-1;
		struct employee current = emps[i];
		//left = elements remaining

		while(--i>=0){
			if(current.empID<emps[i].empID){
				emps[i+1] = emps[i];
			}
			else{
				emps[i+1] = current;
				break;
			}
		}
		if(i<0)
			emps[0]=current;
					
		j--;
		}
		return emps;
}
