#include<stdio.h>
#include<stdlib.h>
int max = 0;
long product = 1;
long sum = 0;
int count = 0;
int pos = -1;
int atMost(int* arr, int n){
    int temp =0;
    for(int i =0;i<n;i++){
        temp = 0;
        for(int j = i;j<n;j++){
           if(sum+arr[j]<2000 && arr[j]*product<1000000){
            sum+=arr[j];
            product*=arr[j];
            temp++;
           }
           else{
                if(temp>max){
                    max = temp;
                    count = 1;
                    pos = i;
                }
                else if(temp == max){
                    count++;
                }
                break;
           }
        }
    }
}

int main(){
    FILE* f = fopen("data.txt","r");
    int n;
    int a = fscanf(f,"%d",&n);
    printf("%d\n",n);
    int size = n;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<size;i++){
        a = fscanf(f,"%d",&n);
        arr[i] = n;
    }
    atMost(arr,size);
    printf("%d, %d,%d",max,count,pos);
}
