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
} // @@ The function is declared to return an int, but in the case where the stack is empty, it prints "error " and then reaches the end of the function without a return statement, causing undefined behavior and a compilation error.
  

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
            printf("%d ", pop(stack));
        }
    }while(op != EOF);
    return 0;
}