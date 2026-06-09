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
    while (scanf("%d", &op) != -1) // @@ The loop condition should be != EOF, not != -1. The input ends with -1, but scanf returns EOF on end of file, not -1. This causes the loop to not terminate correctly.
    {
        if (op == 1)
        {
            push(stack);
        }
        else // @@ This else branch incorrectly handles op == 0 and op == -1. When op == -1 (end of operations), it should not call pop. It should only call pop when op == 0.
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
        printf("Stack is full\n"); // @@ Should print "error " instead of "Stack is full\n" to match the required output format.
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