
struct array{
    char** arr;
   int size;
};
typedef struct array* Array;

int hash(char* str, int base, int size);

int insertInOrder(int *arr, int size, int n);

int collisionCount(char** strarr, int arrsize, int base, int size);

char* clean(char* word);

Array parser(char* fileName);
