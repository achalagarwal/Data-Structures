#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName){
	FILE* f = fopen(fileName,"r");
	//initial size of array = 10
	int * arr = malloc(sizeof(int)*10);
	int cSize = 10;
	int count = 0;
	int temp;
	int n=-1;
	int a = fscanf(f,"%d",&n);
	a = fscanf(f,"%*s %d",&temp);
	while(n-->0&&a!=EOF){
		//if array is not big enough to store data, increase size
		if(count==cSize){
			cSize = cSize*2;
			arr = (int*)realloc(arr,sizeof(int)*cSize);
		}
		arr[count++] = temp;
		a = fscanf(f,"%*s %d",&temp);
	}
	size = count;
	return arr;
}
		

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey){
	int cSize = hiKey - loKey +1;
	int count = 0;
	int *arr = (int*)malloc(sizeof(int)*cSize);
	//initialize range array
	for(int i = 0;i<cSize;i++)
		arr[i] = 0;
	//mark range array whenever applicable
	for(int i = 0;i<lsSize;i++)
		if(Ls[i]<=hiKey && Ls[i]>=loKey)
		arr[Ls[i]-loKey] = 1;
	//count marked elements
	for(int i = 0;i<cSize;i++)
		if(arr[i]==1)
			count++;
	//create keys array
	int *keys = (int*)malloc(sizeof(int)*count);
	int j = 0;
	//add key to array if marked in range
	for(int i = 0;i<cSize;i++)
		if(arr[i]==1)
			keys[j++] = i+loKey;
	KeyStruct ks = (KeyStruct)malloc(sizeof(struct keyStruct));
	ks->Keys = keys;
	ks->keysSize = count;
	return ks;
}

int part2Loc(int* Ls, int lo, int hi, int piv){
	//returns index of pivot
	//assumes only one pivot in range	
	int wall = lo;
	int temp;
	//moves pivot to last index --not needed	
	for(int i = lo;i<=hi;i++){
		if(Ls[i]==piv){
		temp = Ls[hi];
		Ls[hi] = piv;
		Ls[i] = temp;
		break;
		}
	}
	
	for(int i = lo;i<hi;i++){
		if(Ls[i]<=piv){
			temp = Ls[i];
			Ls[i] = Ls[wall];
			Ls[wall] = temp;
			wall++;
		}
	}
	//insert piv into wall index
	temp = Ls[wall];
	Ls[wall] = piv;
	Ls[hi] = temp;
	return wall;
}	

void quickSortKnownKeyRange(int * Ls, int size, int loKey, int hiKey){
	
		KeyStruct ks = extractKeys(Ls,size,loKey,hiKey);
		int* Keys = ks->Keys;
		int ksize = ks->keysSize;
		int p;		
		int lo = 0;
		int hi = size -1;
		//partition for each key
		for(int i = 0;i<ksize;i++){
			p = part2Loc(Ls,lo,hi,Keys[i]);
			lo = p+1;
		}
}	




