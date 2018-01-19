/*
WAP to take an input N and define 4 functions f1,f2,f3 and f4. 
Define an array of size N with elements 1,2,3...N
f1 - sum of all numbers in array
f2 - sum of all even indexed numbers in array
f3 - sum of square of all numbers in array
f4 - sum of square of all odd indexed numbers in array

******************************************************************
INTERFACE FILE
**********************************
void add();
void addOdd();
void addEven();
void square();
void createArray();
void initializeArray();
*********************************
IMPLEMENTATION FILE
*********************************
int add(int s, int a){
	s+=a;
	return s;
}
int addOdd(int i,int s, int a){
	if(i%2==0){
	return s;
	}
	if(i%2!=0){
	return add(s,a);
	}
}
int addEven(int i, int s, int a){
	if(i%2==0){
	return add(s,a);
	}
	if(i%2!=0){
	return s;
	}
}
int square(int a){
	return a*a;
}
int* createArray(int n){
	int* arr = (int *)malloc(sizeof(int)*n);
	return arr;
}
int* initializeArray(int arr[])	
