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
    printf("%d ",s->item[s->top--]); // @@ [When the stack is empty, "error " is printed but the function continues to execute and tries to access s->item[s->top--], which leads to undefined behavior. The function should return immediately after printing "error ".]
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
                printf("no such operation"); // @@ [The problem description does not mention handling of invalid operations (other than 1, 0, -1). However, the reference program doesn't handle this either. But more critically, this line prints without a space suffix like other outputs, and may cause format mismatch. However, the primary error is in the pop function. This line may not be strictly wrong per problem, but since test cases likely don't include invalid ops, the real bug is above.]
        }
    }
    out: return 0;

}