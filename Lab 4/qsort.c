#include"qsort.h"
void quicksort(Card array, int start, int end){
    int n = end-start+1;
    if(n<=1)
        return;
    if(n==2){
        if(array[start].card_number>array[end].card_number){
            struct card temp =array[start];
            array[start]= array[end];
            array[end] = temp;
            return;
        }
    }
    int p = (start+end)/2;
    Card pivot = &array[p];
    int i = start;
    int j = end;
    while(j-i>2){
        while(array[i].card_number<pivot->card_number && i<j)
            i++;
        while(array[j].card_number>pivot->card_number&&j>i)
            j--;
        if(j-i>2){
            struct card temp =array[i];
            array[i]= array[j];
            array[j] = temp;
        }
        if(j-i==2){
        if(array[i].card_number>array[j].card_number){
            struct card temp =array[i];
            array[i]= array[j];
            array[j] = temp;
        }

        }
        if(i==j){
            i = i-1;
            j = j+1;
    }

    }
    quicksort(array,start,i);
    quicksort(array,j,end);
    
}
