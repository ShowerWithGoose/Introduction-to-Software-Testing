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
    while (scanf("%d", &op) != -1) // @@ [The loop condition should check for EOF, not -1. scanf returns EOF on end-of-file or error, not -1 for the operation -1. This causes the loop to continue even after reading -1, leading to incorrect behavior.]
    {
        if (op == 1)
        {
            push(stack);
        }
        else
        {
            pop(stack); // @@ [This else block executes for both op == 0 and op == -1. When op is -1 (end of operations), it incorrectly calls pop(), which may print "error " or a value. The program should stop when op == -1.]
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
        printf("Stack is full\n"); // @@ [The problem requires printing "error " (with a space) for any error, but this prints "Stack is full\n", which does not match the expected output format.]
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