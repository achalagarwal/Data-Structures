#include"Trie.h"
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
Bucket createBucket(int size){
    Bucket b = (Bucket)malloc(sizeof(struct bucket));
    b -> buckets = (Bucket*)malloc(sizeof(Bucket)*size);
    b->stop = 0;
//    b->prefix = (char*)malloc(sizeof(char)*50);
    b->prefix = NULL;
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
    b->prefix=(char*)malloc(sizeof(char)*50);
    strcpy(b->prefix,word);
    t->words++;
    return t;
}

Trie prefixInsert(Trie t, char* word){
    int size = 0;
    char c = word[size++];
    while(c!='\0')
        c = word[size++];
    for(int i = 0;i<size;i++){
        t = insertInTrie(t,word+i);
    }
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
        prefixInsert(t,word);
        a = fscanf(f,"%s",word);
    }
    return 1;

}

int exactSearch(Trie t, char* word){
    int index =0;
    wordToUpper(word);
    char c = word[index++];
    Bucket b = t->root;
    while(c!='\0'){
        int cIndex = getCharacterIndex(t->alpha,c);
        if(cIndex>=0){
            b = b->buckets[cIndex];
            if(b == NULL)
                return 0;
        }
        c = word[index++];
    }
    if(b->stop==0)
        return 0;
    return 1;
}

struct array autocomplete(Trie t, char* prefix){
    struct array bag;
    bag.size = 0;
    bag.arr = NULL;
    int index =0;
    wordToUpper(prefix);
    char c = prefix[index++];
    Bucket b = t->root;
    while(c!='\0'){
        int cIndex = getCharacterIndex(t->alpha,c);
        if(cIndex>=0){
            b = b->buckets[cIndex];
            if(b == NULL)
                return bag;
        }
        c = prefix[index++];
    }
    char** words = (char**)malloc(sizeof(char*)*50);
    for(int i = 0;i<50;i++)
        words[i] = (char*)malloc(sizeof(char)*50);
    int size = 50;
    int count = 0;
    if(b->stop != 0)
        strcpy(words[count++],prefix);  
    List l = createList();
    for(int i = 0;i<t->alpha->size;i++){
        if(b->buckets[i]!=NULL)
            addElementToBack(l,b->buckets[i]);
    }
    
    while(isEmpty(l) == 0){
        b = (Bucket)getElementFront(l);
        for(int i = 0;i<t->alpha->size;i++){
            if(b->buckets[i]!=NULL)
                addElementToBack(l,b->buckets[i]);
        }
        if(b->stop!=0){
            if(count==size){
                size = size*2;
                words = realloc(words,sizeof(char*)*size);
                for(int i = count;i<size;i++)
                    words[i] = (char*)malloc(sizeof(char)*50);
            }
            strcpy(words[count++],b->prefix);
        }
        l = removeElementFromFront(l);
    }
//    struct array bag;
    bag.arr = words;
    bag.size = count;
    return bag;
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
    char* search  = (char*)malloc(sizeof(char)*50);
    while(1){
    scanf("%s",search);
    struct array a = autocomplete(t,search);
    for(int i  = 0;i<a.size;i++)
        printf("%s,", a.arr[i]);
    //printf("%d",exactSearch(t,search));
    }


}

