//
//  hash.c
//
//
//  Created by Achal Agarwal on 16/04/18.
//

#include"hash.h"
#include<stdlib.h>
#include<stdio.h>

HT createHT(int size, int (*f)(void*,int),int (*g)(void*,void*)){
    HT h = (HT)malloc(sizeof(struct hashtable));
    h -> table = (void**)malloc(sizeof(void*)*size);
    h->hash = f;
    h->isEqual = g;
    h->size = size;
    h->load = 0;
    h->marker = (int*)malloc(sizeof(int)*size);
    for(int i = 0;i<size;i++)
        h->marker[i] = 0;
    return h;
}
/*
   MARKER
   0 - Empty and Vacant
   1 - Filled
   2 - Empty and Deleted
*/


int probe(int hash,int c){
    return hash*31 + c*c*37;
}

int helperAddToHT(HT h, void* e, int hash){
    if(h->load >= 0.5)
        printf("Avoid Inserting Elements. Load Factor = %f\n",h->load);
    if(h->marker[hash]==0){
        h->table[hash] = e;
        h->load += 1.0/h->size;
        h->marker[hash] = 1;
        return 1;
    }
    //else
    if(h->marker[hash]==2){
        h->table[hash] = e;
        h->load += 1.0/h->size;
        h->marker[hash] = 1;
        return 1;
    }
    if(h->marker[hash]==1){
        int attempts = h->size/20;
        while(attempts-- > 0){
            hash = probe(hash,(h->size/20) - attempts)%(h->size);
            if(h->marker[hash]==0){
                h->table[hash] = e;
                h->load += 1.0/h->size;
                h->marker[hash] = 1;
                return 1;
            }
            //else
            if(h->marker[hash]==2){
                h->table[hash] = e;
                h->load += 1.0/h->size;
                h->marker[hash] = 1;
                return 1;
            }
        }
        return 0;
    }
    //no case left
    return 0;
}

int helperLookup(HT h, void* e,int hash){ 
    if(h->marker[hash] == 0)
        return -1;
    if(h->marker[hash] == 1)
        if(h->isEqual(h->table[hash],e)==1)
            return hash;
    //else probe
    int attempts = h->size/20;
    while(attempts-->0){
        hash = probe(hash,(h->size/20) - attempts)%(h->size);
        if(h->marker[hash] == 0)
            return -1;
        if(h->marker[hash] == 1)
            if(h->isEqual(h->table[hash],e)==1)
                return hash;
    }
    return -1;
}

int addToHT(HT h,void* e){
    int hash = h->hash(e,h->size);
    if(helperLookup(h,e,hash)==-1)
        return helperAddToHT(h, e, hash);
    else
        return -1;
}

int helperDeleteFromHT(HT h,void* e, int hash){
    if(h->marker[hash] == 0)
        return 0;
    if(h->marker[hash] == 1){
        if(h->isEqual(h->table[hash],e)==1){
            h->table[hash] = NULL;
            h->marker[hash] = 2;
            h->load -= 1.0/h->size;
            return 1;
        }
    }
    //else probe
    int attempts = h->size/20;
    while(attempts-->0){
        hash = probe(hash,(h->size/20) - attempts)%(h->size);
        if(h->marker[hash] == 0)
            return 0;
        if(h->marker[hash] == 1){
            if(h->isEqual(h->table[hash],e)==1){
                h->table[hash] = NULL;
                h->marker[hash] = 2;
                h->load -= 1.0/h->size;
                return 1;
            }
        }
    }
    return 0;
}

int deleteFromHT(HT h, void* e){
    int hash = h->hash(e,h->size);
    return helperDeleteFromHT(h,e,hash);
}


void* getHTElement(HT ht, int index){
    if(ht==NULL)
        return NULL;
    if(index<0)
        return NULL;
    if(index>ht->size)
        return NULL;
    else
        return ht->table[index];
}

//returns index as looking up the table
int lookup(HT h, void* e){
    int hash = h->hash(e,h->size);
    return helperLookup(h,e,hash);
}

