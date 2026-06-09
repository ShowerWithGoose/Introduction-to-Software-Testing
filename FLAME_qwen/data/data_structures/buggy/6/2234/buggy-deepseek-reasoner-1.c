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

int pop(int s[]) // @@ [Function returns int but no return statement in the if(isempty()) branch. This leads to undefined behavior.]
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
            printf("%d ", pop(stack)); // @@ [This line always prints an integer after calling pop, but if the stack is empty, pop prints "error " and does not return a value, leading to undefined behavior and unwanted output.]
        }
    }while(op != EOF); // @@ [The loop should stop when op == -1, not when op == EOF. Using do-while with this condition may cause infinite loop if scanf fails to read EOF.]
    return 0;
}