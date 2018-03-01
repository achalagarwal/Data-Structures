#define ELEMENT

struct _element;
typedef struct _element* Element;

//definition of element
struct _element {
    
    //url must end with \0
    char* url;
    long long data;
};

typedef long long Key;

//methods for element

Element createElement(char* url, long long data);
Key getElementKey(Element e);
char* getElementUrl(Element e);


