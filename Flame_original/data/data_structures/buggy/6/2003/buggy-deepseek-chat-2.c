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
    while (scanf("%d", &op) != -1) // @@ The condition should be != EOF, not != -1. The input ends with -1 as a value, not as an EOF indicator.
    {
        if (op == 1)
        {
            push(stack);
        }
        else // @@ This else branch will execute for op == 0 and also for op == -1, causing incorrect behavior. It should only handle op == 0.
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
    scanf("%d", &item); // @@ The item should be read only when op == 1, but here it is read inside push, which is called only when op == 1. However, the problem requires reading item after op in the main loop, not inside push.
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