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
            printf("%d ", pop(stack)); // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value (since no return statement is executed in the error case), which is then printed by this printf as garbage (e.g., 6). This causes incorrect output like "error 6". The function should not print inside pop() and should instead let main handle the error printing after checking emptiness. Also, the loop condition should stop on op == -1, not EOF.]
        }
    }while(op != EOF); // @@ [The loop should terminate when op == -1, not when reaching EOF. The problem specifies that -1 marks the end of operations, so this condition causes the program to read beyond -1 or behave incorrectly on input termination.]
    return 0;
}