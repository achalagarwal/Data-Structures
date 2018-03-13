#include<stdio.h>
#include<math.h>

int main(){
    double cons =1.0*2.0*3.0*4.0/5.0/5.0/5.0/5.0;
    FILE * f = fopen("expect","w");
    double sum = 0.0;
    for(int x = 0; x<100; x++){
        for(int i = 0;i<=x;i++){
            for(int j = 0;j<=x-i;j++){
                for(int k = 0;k<=x-i-j;k++){
                    for(int l = 0;l<=x-i-j-k;l++){
                        fprintf(f,"%d,%d,%d,%d\n",i,j,k,l);
 //                       printf("%lf,%lf,%lf,%lf",pow(1.0/5.0,(double)i),pow(2.0/5.0,(double)j),pow(3.0/5.0,(double)k),pow(4.0/5/0,(double)l));
                        double res = pow(1.0/5.0,(double)i)*pow(2.0/5.0,(double)j)*pow(3.0/5.0,(double)k)*pow(4.0/5.0,(double)l);
                        sum += (5.0+x)*res*cons;
                        fprintf(f,"%lf\n",res*cons);
                    }
                }
            }
        }
    }
    printf("%lf",sum);
}
