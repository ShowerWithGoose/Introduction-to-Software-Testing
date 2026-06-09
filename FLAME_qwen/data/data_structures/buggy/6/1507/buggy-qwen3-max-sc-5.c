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
        printf("error ");
    }
    printf("%d ",s->item[s->top--]); // @@ [When the stack is empty, this line still executes and tries to access s->item[s->top--], which leads to undefined behavior. The function should return after printing "error ".]
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
                printf("no such operation"); // @@ [The problem description does not mention handling of invalid operations; however, the reference program doesn't handle defaults either. But more critically, this may output unexpected text not matching expected output format. However, the primary error is in the pop function.]
        }
    }
    out: return 0;

}