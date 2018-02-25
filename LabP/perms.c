#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* sort(char* str,int len){
    for(int i = 1;i<len;i++){
        char ch= str[i];
        int j;
        for( j = i-1;j>=0;j--){
            if(ch<str[j]){
                str[j+1]=str[j];
            }
            else{
                str[j+1] = ch;
                break;
            }
        }
        if(j==-1)
            str[0] = ch;
    }
    return str;
}
void permut(char* string,int l,int r){
        if(l == r)
            printf("%s\n",string);
        else{
            for(int i = l;i<=r;i++){
                char temp = string[i];
                string[i] = string[l];
                string[l] = temp;
                permut(string,l+1,r);
                 temp = string[i];
                string[i] = string[l];
                string[l] = temp;
            }
        }
}
int main(int cargs, char* args[]){
    int i =0;
    char ch = args[1][i];
    while(ch!='\0'){
        i++;
        ch = args[1][i];
    }
    permut(sort(args[1],i),0,i-1);
//    permut(args[1],0,i-1);

}
