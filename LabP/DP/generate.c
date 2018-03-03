#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE* f = fopen("data.txt","w");
    int count = 10000;
    for(int i = 0; i< count;i++){
        int r = rand();
        int a = rand();
         if(a%2 == 0)
            r = r*-1;
        fprintf(f,"%d\n",r);
        if(i%1000 == 0)
            srand(rand());
    }
    fclose(f);
}

    
