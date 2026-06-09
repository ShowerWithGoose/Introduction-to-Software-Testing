#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
int isEmpty();
int isFull();
int top = -1, stack[MAX_SIZE], op, item;
void push(int stack[]);
void pop(int stack[]);

int main()
{
    while (scanf("%d", &op) != -1) // @@ The loop condition should be != EOF, not != -1. The input -1 is a valid operation that should end the loop, but using != -1 will cause the loop to continue reading after -1, leading to incorrect behavior.
    {
        if (op == 1)
        {
            push(stack);
        }
        else // @@ This else branch treats all non-1 operations (including 0 and -1) as pop operations. When op is -1 (end of operations), it incorrectly calls pop, which may cause an error or unexpected output.
        {
            pop(stack);
        }
    }
    return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (top == MAX_SIZE - 1)
        return 1;
    else
        return 0; // return 0 if not full
}
void push(int stack[])
{
    scanf("%d", &item);
    if (isFull())
    {
        printf("Stack is full\n"); // @@ The problem requires outputting "error " (with a space) when the stack is full, not "Stack is full\n". This incorrect message causes wrong output.
        return;
    }
    stack[++top] = item;
    return;
}

void pop(int stack[])
{
    if (isEmpty())
    {
        printf("error ");
        return;
    }
    printf("%d ", stack[top--]);
}