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
        printf("error "); // @@ The function is declared to return int, but when the stack is empty, it prints "error " and does not return a value, leading to undefined behavior.
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
            printf("%d ", pop(stack)); // @@ When pop() returns without a value (empty stack case), this printf will print an undefined/garbage value.
        }
    }while(op != EOF); // @@ The loop condition checks for EOF, but scanf returns EOF, not op. The correct check should be while(scanf(...) != EOF) or check for -1 as per problem description.
    return 0;
}