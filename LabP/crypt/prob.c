#include<stdio.h>

int main(){
    int count = 5;
    float prev = 1.0*2.0*3.0*4.0/5.0/5.0/5.0/5.0;
    printf("%f",prev);
    float sum = 0;
    for(int i = count;i<1000;i++){
        sum+= prev*count;
        double t = prev;
        prev = 0.0;
        for(int j = 1;j<5;j++)
            prev += t*j/5.0;
            
        }
    printf("%f",sum);
    }
