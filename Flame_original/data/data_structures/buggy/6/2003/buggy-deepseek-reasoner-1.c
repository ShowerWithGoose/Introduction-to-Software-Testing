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
    while (scanf("%d", &op) != -1) @@ [The loop does not stop when op is -1. It should stop when -1 is read (e.g., by breaking or using condition `op != -1`).]
    {
        if (op == 1)
        {
            push(stack);
        }
        else @@ [This else branch incorrectly treats op = -1 as a pop operation. It should only pop when op == 0 and stop when op == -1.]
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
        printf("Stack is full\n"); @@ [The output should be "error " (with a space) instead of "Stack is full\n".]
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