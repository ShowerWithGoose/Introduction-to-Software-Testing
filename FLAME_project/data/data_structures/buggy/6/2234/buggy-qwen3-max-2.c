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
            printf("%d ", pop(stack)); // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value (since no return in the error case), which is then printed by this printf as garbage (e.g., 6). Also, loop condition should stop at op == -1, not EOF.]
        }
    }while(op != EOF); // @@ [The loop should terminate when op == -1, not when reaching EOF. This causes extra unintended behavior or infinite loop in some environments.]
    return 0;
}