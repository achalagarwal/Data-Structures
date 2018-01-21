#include<stdio.h>
#include<stdlib.h>
#include"queue.c"

int main()
{
    Queue q=newQ();
    Element *e1=(Element*)malloc(sizeof(Element));
    e1->value=1;
    Element* e2=(Element*)malloc(sizeof(Element));
    e2->value = 2;
    q=addQ(q,*e1);
    q=addQ(q,*e2);
    q=addQ(q,*e2);
    printf("%d",lengthQ(q));

return 0;
}


