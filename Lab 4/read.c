#include<stdio.h>
#include"qsort.h"
#include<stdlib.h>
#include"memory.h"
void insertInOrder(Card c, Card array,int n){
        if(n==0)
                array[n] = *c;
        else if(array[n-1].card_number<=c->card_number)
                array[n] = *c;
        else if(array[n-1].card_number>c->card_number){
                array[n] = array[n-1];
                insertInOrder(c,array,n-1);
}
}



Card read(){
	FILE* file;
	file  = fopen("100000","r");
	char bank_code[5];
	char first_name[5];
	char last_name[5];
	char expir[7];
	long long account=0;
	int month;
	int year;
	int a=1;
	Card cards = (Card)myalloc(5*sizeof(struct card));
	char input[45]="a";
	int counter = 0;
	int size = 5;
	while(a!=EOF){
	account = 0;
	month = 0;
	year = 0;

	Card c  =  (Card)myalloc(sizeof(struct card));

	//fscanf(file,"\"%16[,],%5[,]%7[,]%5[,]%5[,]\"",&account[0],&bank_code[0],&expir[0],&first_name[0],&last_name[0]);
	a =fscanf(file,"%s",&input[0]);
	counter++;
	if(counter>size){
		cards = myrealloc(cards,size*2*sizeof(struct card));
		size = size*2;	
}
	if(a!=EOF){
	char hi[43];
	for(int i= 0;i<42;i++)
		hi[i]= input[i+1];
//	fclose(file);
	for(int i = 0;i<16;i++)
		account = account*10 + (int)(hi[i]-48);
	for(int i = 17;i<22;i++)
		c->bank_code[i-17]= hi[i];
	month = 0;
	for(int i = 23;i<25;i++)
		month=month*10 + (int)(hi[i]-48);
	year = 0;
	for(int i = 26;i<30;i++)
		year = year*10 + (int)(hi[i]-48);
	char ch2 = hi[31];
	int  i = 0;
	while(ch2!=','){
		c->first_name[i++] =(char) ch2;
		ch2 = hi[31+i];
	}
	i++;
int	j = 0;
	ch2 = hi[31+i];
	while(ch2!='\"'){
		c->last_name[j++] = ch2;
		ch2 = hi[31+i+j];

}
//	system("clear");
	printf("%d\n",counter);
//	Card c = (Card)malloc(sizeof(struct card));
	c->card_number = account;
//	c->first_name = first_name;
//	c->last->name = last_name;
	c->expiry_month = month;
	c->expiry_year = year;
//	c->bank_code = bank_code;
//	insertInOrder(c,cards,counter-1);
	cards[counter-1]=*c;
	myfree(c);

}
}

fclose(file);
    quicksort(cards,0,counter-2);
//return cards;
	Card end = (Card)myalloc(sizeof(struct card));
	end->card_number = -1;
	cards[counter] = *end;
	return cards;
}

int main(){
	Card all = read();
	FILE* f;
	f = fopen("newFile.txt","w");
	Card c = &all[0];
	int i = 0;
	while(c->card_number!=-1){
		fprintf(f,"Card Number %lld\n",c->card_number);
		c = &all[++i];
}	
	fclose(f);
}
