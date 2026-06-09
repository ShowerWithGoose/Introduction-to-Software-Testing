#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top;

void initstack()
{
    top = -1;
}

int isempty()
{
    return top == -1;
}

int isfull()
{
    return top == MAXSIZE-1;
}

void push(int s[ ], int item)
{
    if(isfull())
        printf("error ");
    else
        s[++top] = item;
}

int pop(int s[])
{
    if(isempty())
        printf("error ");
    else
        return s[top--];
}

int main()
{
    int op, item;
    initstack();
    do{
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &item);
            push(stack, item);
        }
        else if(op == 0){
            if (isempty()) { // @@ The original code calls pop(stack) which prints "error " but also returns an undefined/garbage value because the function doesn't return anything in the error branch. This garbage value is then printed by printf("%d ", ...). We need to handle the empty stack case here before calling pop or printing.
                printf("error ");
            } else {
                printf("%d ", pop(stack));
            }
        }
    }while(op != -1); // @@ The loop condition should check for op != -1 as per the problem description ("-1 represents the end of operations"). The original code checks for EOF, which is incorrect for this input format.
    return 0;
}