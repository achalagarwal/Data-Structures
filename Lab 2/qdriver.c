#include"queue.c"
int main(){
    Queue q = newQ();
    Element e1 = (Element)malloc(sizeof(struct element));
    e1->value =1;
    addQ(q,e1);
    Element e2 = (Element)malloc(sizeof(struct element));
    e2->value = 2;
    q = addQ(q,e2);
    Element a = front(q);
    q = delQ(q);
    Element b = front(q);
    q = delQ(q);
    printf("%ld",a->value);
    printf("%ld",b->value);
    Element c = front(q);
    if(c!=NULL)
        printf("%ld",c->value);
    else
        printf("NULL");
    return 0;

}

