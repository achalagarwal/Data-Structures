struct array{
     void** arr; 
     int size;
};
typedef struct array* Array;

struct element{
int value;
int fileIndex;
};

typedef struct element* Element;

int batch();
