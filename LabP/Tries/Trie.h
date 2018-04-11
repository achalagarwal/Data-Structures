#ifndef ALPHABET_H
#define ALPHABET_H
struct alphabet;
typedef struct alphabet* Alphabet;
struct alphabet{
    char* chars;
    int size;
};
#endif

struct bucket;
typedef struct bucket* Bucket;
struct bucket{
    //Alphabet alpha;
    Bucket* buckets;
    int stop:1;
    char* prefix;
};

struct trie{
    Bucket root;
    Alphabet alpha;
    int words;
};
typedef struct trie* Trie;

struct array{
    char** arr;
    int size;
};

#define LIST_ELEMENT_H
typedef Bucket LElement;
#include"list.h"

Trie createTrie(Alphabet a );
Trie insertInTrie(Trie t, char* w);

