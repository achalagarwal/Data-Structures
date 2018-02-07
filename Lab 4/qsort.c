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
        
        }
        return;
    }
    int p = (start+end)/2;
    Card pivot = &array[p];
   int i = start;
   // int j = end;
   // while(j-i>2){
   //     while(array[i].card_number<=pivot->card_number && i<j)
   //         i++;
   //     while(array[j].card_number>pivot->card_number&&j>i)
   //         j--;
   //     if(j-i>2){
   //         struct card temp =array[i];
   //         array[i]= array[j];
   //         array[j] = temp;
   //     }
   //     if(j-i==2){i
   //     if(array[i].card_number>array[j].card_number){
   //         struct card temp = array[i];
   //         array[i]= array[j];
   //         array[j] = temp;
   //     }
   //     if(i>j){

   //     }
   //     if(i==j){
   //         i = i-1;
   //         j = j+1;
   // }
   struct card temp = array[p];
   array[p]= array[end];
   array[end] = temp;
   int flag = 0;
   int wall = start-1;
    while(i<end){
        if(array[i].card_number<array[end].card_number){
            wall++;
           struct card temp = array[i];
           array[i]= array[wall];
           array[wall] = temp;
        
        }
        i++;
    }
    wall++;
   temp =  array[wall];
   array[wall]= array[end];
   array[end] = temp;
   if(wall>start)
    quicksort(array,start,wall-1);
    if(wall<end)
    quicksort(array,wall+1,end);
    
}
