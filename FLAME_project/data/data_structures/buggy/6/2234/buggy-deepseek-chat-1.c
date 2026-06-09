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
        printf("error "); // @@ The function does not return a value after printing "error", leading to undefined behavior. It should return a dummy value or handle the error differently.
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
            printf("%d ", pop(stack)); // @@ When pop() prints "error" due to empty stack, it does not return a value, so this printf prints an undefined integer (e.g., 6 in the buggy output). The expected behavior is to only print "error " without an extra number.
        }
    }while(op != EOF); // @@ The loop condition should check for -1 (end of operations), not EOF. This causes the program to read beyond the intended input, leading to incorrect behavior.
    return 0;
}