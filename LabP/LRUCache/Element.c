#include"Element.h"
#include<stdlib.h>
//include mem and redefine allocs

//create element with supplied data

Element createElement(char* url, long long data){
    Element e = (Element)malloc(sizeof(struct _element));
    e -> url = url;
    e -> data = data;
    return e;
}

Key getElementKey(Element e){
    if(e != NULL)
        return e -> data;

    // if null element supplied
    return -1;
}

char* getElementUrl(Element e){
    if(e != NULL)
        return e -> url;
    
    // if null element supplied
    return (char*)NULL;
}
