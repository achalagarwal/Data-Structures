#include"Trie.h"
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>

Bucket createBucket(int size){
    Bucket b = (Bucket)malloc(sizeof(struct bucket));
    b -> buckets = (Bucket*)malloc(sizeof(Bucket)*size);
    b->stop = 0;
    for(int i = 0;i<size;i++)
        b->buckets[i] = NULL;
    return b;
}

Trie createTrie(Alphabet a){
    Trie t = (Trie)malloc(sizeof(struct trie));
    t -> alpha = a;
    t -> root = createBucket(a->size);
    t->words = 0;
    return t;
}



int getCharacterIndex(Alphabet a, char c){
    // for completion, scan entire array in a for the character c
    // temp: assumed that character index can be obtained by char - 65
    if(isalpha(c))
        return (int)c - 65;
    else
        return -1;

}
//  \0 terminating string required
Trie insertInTrie(Trie t, char* word){
    int index = 0;
    char c = word[index++];
    Bucket b = t->root;
    int cIndex;
    while(c!='\0'){
        cIndex = getCharacterIndex(t->alpha,c);
        if(cIndex >=0){
        if(b->buckets[cIndex]==NULL)
            b->buckets[cIndex] = createBucket(t->alpha->size);
        b = b->buckets[cIndex];
        }
        c = word[index++];
    }
    b->stop = 1;
    return t;
}

//in place
void wordToUpper(char* word){
    int index = 0;
    char c = word[index];
    while(c!='\0'){
        word[index++] = toupper(c);
        c = word[index];
    }
}


int fillTrie(Trie t, FILE* f){
    if(t == NULL || f == NULL)
        return 0;
    char* word = (char*)malloc(sizeof(char)*50);
    int a = fscanf(f,"%s",word);
    while(a!=EOF){
        wordToUpper(word);
        insertInTrie(t,word);
        a = fscanf(f,"%s",word);
    }
    return 1;

}

int main(){
    Alphabet a = (Alphabet)malloc(sizeof(struct alphabet));
    a->size = 26;
    a->chars = (char*)malloc(sizeof(char)*26);
    for(int i = 0;i<26;i++){
        a->chars[i] =(char) (i+65);
    }
    Trie t = createTrie(a);

   // insertInTrie(t,"ACHAL\0");

    FILE* f = fopen("words.txt","r");
    fillTrie(t,f);
}

