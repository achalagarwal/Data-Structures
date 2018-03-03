#include<stdio.h>
#include<stdlib.h>

long long getMax(int* arr,int size,int index,long long sum){
    if(index==size)
        return sum;
    if(sum + arr[index]> 0)
        sum += arr[index];
    return getMax(arr,size,index+1,sum);
}

int main(){

    FILE * f = fopen("data.txt","r");
    int r;
    int a = fscanf(f,"%d",&r);
    int *arr = (int*)malloc(sizeof(int)*10);
    int size = 10;
    int count = 0;
    while(a!=EOF){
      if(count==size){
          arr = realloc(arr,sizeof(int)*size*2);
          size *=2;
      }
      arr[count] = r;
        count++;
      a = fscanf(f,"%d",&r);
    }
    int* arr2 = malloc(sizeof(
    printf("%lld", getMax(arr, 100,0,0));
}


