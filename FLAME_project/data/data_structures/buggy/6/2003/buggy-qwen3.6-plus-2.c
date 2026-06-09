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
    while (scanf("%d", &op) != -1) // @@ The loop condition should check for EOF or specifically handle the termination signal '-1'. Using != -1 causes the loop to continue even when op is -1, leading to an extra pop operation. It should be `!= EOF` and include a break for op == -1, or check `scanf(...) == 1 && op != -1`.
    {
        if (op == 1)
        {
            push(stack);
        }
        else // @@ This else block executes for any op that is not 1, including 0 (pop) and -1 (terminate). When op is -1, it incorrectly calls pop(). It should explicitly check `if (op == 0)` for pop and `if (op == -1)` to break.
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
        printf("Stack is full\n"); // @@ The problem requires outputting "error " (with a space) for errors, not "Stack is full\n".
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