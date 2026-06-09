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
    while (scanf("%d", &op) != -1) // @@ [The loop condition should check for EOF or the termination value -1 as per problem description. However, the problem states that -1 represents end of operations, so the loop should break when op == -1, not rely solely on scanf result. Also, scanf returns number of items read, so comparing to -1 is incorrect; it should be compared to EOF or checked if op == -1 inside the loop.]
    {
        if (op == 1)
        {
            push(stack);
        }
        else
        {
            pop(stack); // @@ [This else block executes for both op == 0 and op == -1. When op == -1 (end of operations), it incorrectly calls pop(), which will print "error " if stack is empty or pop an element, violating the requirement that -1 only terminates input.]
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
        printf("Stack is full\n"); // @@ [The problem requires printing "error " (with a space) for any error (including full stack), but this prints "Stack is full\n", which does not match expected output format.]
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