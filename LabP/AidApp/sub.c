#include<stdio.h>
#include<stdlib.h>

int max =0;
int product = 1;
int sum = 0;
int count = 0;
int atMost(int arr[], int n){
    int lower =0;
    int upper = 0;
    while(upper<n){
        if(arr[upper]+sum<2000 && arr[upper]*product<1000000){
        //    upper++;
            if(max<upper-lower){
            max = upper-lower;
            count =1 ;
            }
            else if(max == upper-lower){
                count++;
            }

            product = arr[upper-1]*product;
            sum = arr[upper-1]+sum;
            upper++;
        }
        else{
            sum-=arr[lower];
            product /=arr[lower];
            lower++;
        }
    }
     return 1;   
}

int main(){
    FILE* f = fopen("data.txt","r");
    int n;
    int a = fscanf(f,"%d",&n);
    int size = n;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<size;i++){
        a = fscanf(f,"%d",&n);
        arr[i] = n;
        //printf("%d,",arr[i]);
    }
    atMost(arr,size);
    printf("\nAns -> %d occured %d",max,count);
}
