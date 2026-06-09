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
        printf("error "); // @@ The function is declared to return int, but when the stack is empty, it prints "error " and does not return a value, causing undefined behavior.
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
            printf("%d ", pop(stack)); // @@ When pop returns without a value (empty stack case), this prints an undefined integer value.
        }
    }while(op != EOF); // @@ The loop condition checks for EOF, but scanf returns EOF, not op. This will cause an infinite loop or incorrect termination. The correct condition should check scanf's return value or compare op to -1 as per the problem description.
    return 0;
}