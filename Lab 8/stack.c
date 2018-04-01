#include"stack.h"
#include"assert.h"
#include"stdlib.h"

Stack createStack(){
    Stack s = (Stack)malloc(sizeof(struct stack));
    s -> head = NULL;
    return s;
}

Stack_Element getTop(Stack s){
    if(s!=NULL&&s->head!=NULL)
        return s->head->e;
    else
        return NULL;
}

Stack addToStack(Stack s, Stack_Element e){
    //assert(e!=NULL);
    Node n = (Node)malloc(sizeof(struct node));
    n -> e = e;
    n -> next = s -> head;
    s -> head = n;
    return s;
}

Stack deleteFromStack(Stack s){
    if(s==NULL)
        return NULL;
    if(s->head == NULL)
        return s;
    else{
        Node t = s->head;
        s -> head = s -> head -> next;
        free(t);
    }
    return s;
}

Stack emptyStack(Stack s){
    while(s -> head !=NULL){
        deleteFromStack(s);
    }
    return s;
}
