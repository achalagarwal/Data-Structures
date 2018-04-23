#include<stdio.h>
#include<stdlib.h>

int count = 0;

int generate(int bound){
    if(count==100){
        srand(rand());
    }
    return rand()%bound+1;
}

int main(){
 FILE* f = fopen("data.txt","w");
 int n = 1000000;
 fprintf(f,"%d",n);
 for(int i =0;i<n;i++){
    fprintf(f,"\n%d",generate(9));
 }


}
