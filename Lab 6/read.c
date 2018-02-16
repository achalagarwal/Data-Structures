#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"qsort.h"
#define emp
#include"insort.h"
struct qair{
Employee emps;
int count;
};
struct p{
	double a;
	double  b;
};
struct qair read(){
	FILE* f;
	f = fopen("/Users/achal/Documents/Acads/3/3-2/DSA/Lab/Lab 7/haha.txt","r");
	char* name= (char*)malloc(sizeof(char)*10);
	long long id;
	int a = fscanf(f,"%10s %lld",name,&id);
	Employee emps = (Employee)malloc(10*sizeof(struct employee));
	int count = 0;
	int size = 10;
	while(a!=EOF){
		if(count+1==size){
			emps = (Employee)realloc(emps,sizeof(struct employee)*2*size);
			size = size*2;
		}
		emps[count].empID = id;
		//int l = strlen(name);
		emps[count].name = (char*)malloc(sizeof(char)*10);
		strcpy(emps[count].name,name);
		count++;
		a = fscanf(f,"%10s %lld",name,&id);
	}
	struct qair ab;
	ab.emps = emps;
	ab.count = count;
	fclose(f);
	return ab;
}
struct p testRun(Employee emps,int size){
	struct timeval t1,t2,t3,t4;
	double lsTime;
	double qsTime;
	struct p a;
	Employee temp = emps;
	gettimeofday(&t1,NULL);
	temp = insertionSort(temp,size-1);
	gettimeofday(&t2,NULL);
	lsTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	lsTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	gettimeofday(&t3,NULL);
	emps = quickSort(emps,0,size-1,0);
	gettimeofday(&t4,NULL);
	qsTime = (t4.tv_sec - t3.tv_sec) * 1000.0;
	qsTime += (t4.tv_usec - t3.tv_usec) / 1000.0;
//	printf("Total time is" + elapsedTime + "ms.\n";
	a.a = lsTime;
	a.b = qsTime;
	return a;
}
int returnBest(Employee emps,int size){
//	int min = 5;
//	int max = size-1;
//	struct p minT = testRun(emps,min);
//	struct p maxT = testRun(emps,max);
//	int lastValue=0;
	int newValue = size-1;
	while(newValue>0){
	struct p times = testRun(emps,newValue);
	if(times.a>times.b){
		newValue = newValue/2;
	}
	else{
		break;
	}
	}
	while(newValue<size){
	struct p times = testRun(emps,newValue);
	if(times.a>times.b){
		newValue = newValue-1;
		break;
	}
	else{
		newValue++;
	}
}
	return newValue;
}
int main(){
	Employee emps;
	struct qair q  = read();
	//int size = sizeof(emps)/sizeof(struct employee);
	//int a = returnBest(q.emps,q.count-1);
//	printf("%d",a);	
	Employee tmp = q.emps;
	emps = quickSort(q.emps,0,q.count-1,200);
	emps = insertionSort(tmp,q.count-1);

	FILE *f = fopen("/Users/achal/Documents/Acads/3/3-2/DSA/Lab/Lab 7/NewData.txt","w");
	for(int i = 0;i<q.count-1;i++){
	fprintf(f,"%s %lld\n",q.emps[i].name,q.emps[i].empID);
	}
	fclose(f);
	

}
