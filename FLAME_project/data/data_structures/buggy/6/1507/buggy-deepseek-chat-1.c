#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack{
    int item[MAX_SIZE];
    int top;
};
typedef struct stack Stack;

void initStack(Stack* s){
    s->top=-1;
}

int isFull(Stack* s){
    return s->top==MAX_SIZE-1;
}

int isEmpty(Stack* s){
    return s->top==-1;
}

void push(Stack* s,int item){
    if(isFull(s))
    {
        printf("error ");
        return;
    }
    s->item[++s->top]=item;
}

void pop(Stack* s){
    if(isEmpty(s))
    {
        printf("error "); // @@ This line prints "error " but does not return, causing the function to continue and attempt to pop from an empty stack, leading to undefined behavior and incorrect output.

    }
    printf("%d ",s->item[s->top--]); // @@ This line is executed even when the stack is empty, printing garbage or causing an out-of-bounds access. It should only be executed when the stack is not empty.
}

int main()
{
    Stack s;
    initStack(&s);

    int operation;
    while(scanf("%d",&operation)==1)
    {
        switch(operation)
        {
            case 1: 
            {
                int data;
                scanf("%d",&data);
                push(&s,data);
                break;
            }
            case 0:
                pop(&s);
                break;
            case -1:
                goto out;
            default:
                printf("no such operation");
        }
    }
    out: return 0;

}