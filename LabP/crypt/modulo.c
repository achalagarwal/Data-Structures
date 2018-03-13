#include<stdio.h>
#include<stdlib.h>
int main(){
    unsigned long long int q = 13710221545914561761;
    unsigned long long int p = 11066328760152681859;
//    printf("%d",sizeof(unsigned long long int));
 //   int q = 5;

    for(unsigned long long int i = 11066328760152681859;i<=18446744073709551615;i++){
        if(((i-1)%p==0 && (i+1)%q==0) ||( (i+1)%p==0 &&(i-1)%q==0) )
            printf("%lld\n",i);
    }
}

