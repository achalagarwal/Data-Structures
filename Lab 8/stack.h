#define STACK_H
#ifdef BST_H
typedef Bst Stack_Element;
#endif
#ifndef BST_H
struct stack_element;
typedef struct stack_element* Stack_Element;
struct stack_element{
    int val;
};
#endif
struct node;
struct stack;
typedef struct node* Node;
typedef struct stack* Stack;
struct node{
    Node next;
    Stack_Element e;
};
struct stack{
    Node head;
};

Stack_Element getTop(Stack s);
Stack createStack();
Stack addToStack(Stack s, Stack_Element e);
Stack deleteFromStack(Stack s);

