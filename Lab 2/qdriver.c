#include<stdio.h>
#include<stdlib.h>
#include"Q_header.h"

int main()
{
    Queue q=newQ();
        Element e1=(Element)malloc(sizeof(Ele));
            e1->data=1;
                e1->next=NULL;
                    Element e2=(Element)malloc(sizeof(Ele));
                        e2->data=2;
                            e2->next=NULL;
                                q=addQ(q,e1);
                                    q=addQ(q,e2);
                                        printf("%d",lengthQ(q));
                                        
                                        return 0;
                                        }
                                        
                                        
