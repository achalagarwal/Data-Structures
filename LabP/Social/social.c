#include<stdio.h>
#include<stdlib.h>



int isthere(int* arr, int e, int size){
    for(int i = 0;i<size;i++)
        if(arr[i] == e)
            return 1;
    return 0;
}

int noIssues(int** donts, int ele, int* arr){
    for(int i = 0;i<13;i++){
        if(arr[i] >0){
        for(int j = 0;j<13;j++){
            if(donts[i][j]==-1)
                    break;
            if(donts[i][j] == ele)
                return 0;
        }
    }
    }
    for(int i = 0;i<13;i++){
        if(donts[ele][i]==-1)
            break;
        if(arr[donts[ele][i]]>0)
            return 0;

    }
    return 1;
}

int subtract(int* arr, int** wants,int ele){
    for(int i = 0;i<13;i++){
        if(wants[ele][i] == -1)
        break;
        arr[wants[ele][i]]--;
    }
    return 1;
}

int add(int* arr, int** wants, int ele, int** donts){ 
    arr[ele]++;
    for(int i = 0;i<13;i++){
        if(wants[ele][i] == -1)
        break;
        if(arr[wants[ele][i]]>0)
            continue;
        if(arr[wants[ele][i]]==-1)
            return 0;
        if(noIssues(donts,wants[ele][i],arr)==1){
            
            return add(arr,wants,wants[ele][i],donts);
        }
        else{
            /*
            for(int j = 0;j<i;j++)
                arr[wants[ele][j]]--;
            */
                return 0;
        }
    }
    return 1;
}

int addH(int* arr, int** wants,int ele, int** donts){
    int* copy = (int*)malloc(sizeof(int)*13);
    for(int i = 0;i<13;i++)
        copy[i] = arr[i];
    

    int flag =add(arr,wants,ele,donts);
    if(flag == 1)
        return 1;
    else {
    for(int i = 0;i<13;i++)
        arr[i] = copy[i];
    }
    
    return 0;
}

void printList(int* arr){
    char** names = malloc(sizeof(char*)*13);
    for(int i =0;i<13;i++){
        names[i] = malloc(sizeof(char)*15);
    }

       names[0]="Vaibhav";
       names[1]="Achal";
       names[2]="Vibhas";
       names[3]="JSM";
       names[4]="Kulku";
       names[5]="Aman";
       names[6]="Abhi A";
       names[7]="Abhi G";
       names[8]="Ashwar";
       names[9]="Taranjot";
       names[10]="Nalin";
       names[11]="Abbas";
       names[12]="XYZ";
       
       int count = 0;
       for(int i = 0;i<13;i++){
        if(arr[i]>0)
            count++;
        }
       if( count > 11){
       for(int i =0;i<13;i++)
           if(arr[i]>0)
               printf("%s,",names[i]);
       printf("\n*************\n");
       }
      /*  names Achal
        2. Vibhas
        3. JSM
        4. Kulkarni
        5. Aman
        6. Abhishek A
        7. Abhishek G
        8. Ashwar
        9. Taranjot
        10. Nalin
        11. Abbas
        12. XYZ
        */
}

void compute(int** wants, int** donts, int* arr){
  /*  int* copy = (int*)malloc(sizeof(int)*13);
    for(int i = 0;i<13;i++)
        copy[i] = arr[i];
    */
        for(int i = 0;i<13;i++){
        if(arr[i] == 0){
          int* copy = (int*)malloc(sizeof(int)*13);
          for(int i = 0;i<13;i++)
            copy[i] = arr[i];
        
            int flag = 0;
        //i not there
            if(noIssues(donts,i,arr)==1){
                if(addH(arr,wants,i,donts)==1){
               //         arr[i]++;
                        compute(wants,donts,arr);
                        flag = 1;
                    }
            }
    for(int j = 0;j<13;j++)
        arr[j] = copy[j];
    arr[i] = -1;
    compute(wants, donts,arr);


          //  if(flag == 1)
          //      arr[i]--;
        }
    }
    printList(arr);
   /* for(int i = 0;i<13;i++)
        arr[i] = copy[i];
      */  
    return;
}





int main(){
    /*
        0. Vaibhav
        1. Achal
        2. Vibhas
        3. JSM
        4. Kulkarni
        5. Aman
        6. Abhishek A
        7. Abhishek G
        8. Ashwar
        9. Taranjot
        10. Nalin
        11. Abbas
        12. XYZ

    */

    int* arr = malloc(sizeof(int)*13);
    for(int i = 0;i<13;i++)
        arr[i] = 0;
    int **wants = (int**)malloc(sizeof(int*)*13);
    for(int i = 0;i<13;i++)
        wants[i] = (int*)malloc(sizeof(int)*13);
    for(int i = 0;i<13;i++)
        for(int j = 0;j<13;j++)
            wants[i][j] = -1;
    int **donts = (int**)malloc(sizeof(int*)*13);
    for(int i = 0;i<13;i++)
        donts[i] = (int*)malloc(sizeof(int)*13);
    for(int i = 0;i<13;i++)
        for(int j = 0;j<13;j++)
            donts[i][j] = -1;
    wants[0][0] = 1;
    wants[1][0] = 0;
    wants[2][0] = 4;
    wants[2][1] = 5;
    wants[2][2] = 11;
    wants[3][0] = 10;
    wants[3][1] = 9;
    wants[3][2] = 6;
    donts[3][0] = 7;
 //   donts[0][0] = 1;
    int* current = malloc(sizeof(int)*15);
    int size = 0;
    compute(wants,donts,arr);

    
    
}
