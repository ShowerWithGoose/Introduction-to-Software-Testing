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
    while (scanf("%d", &op) != -1) // @@ [The loop condition should check for EOF or the termination value -1 as per problem description; however, the problem states that -1 ends operations, so reading should stop when op == -1, not continue. Also, scanf returns number of items read, not the value -1 on end-of-input. This causes infinite loop or incorrect behavior.]
    {
        if (op == 1)
        {
            push(stack);
        }
        else
        {
            pop(stack); // @@ [This executes for op == 0 AND op == -1. When op is -1 (end marker), it incorrectly calls pop(), which may print "error " or a value. The program should break on op == -1, not treat it as pop.]
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
        printf("Stack is full\n"); // @@ [Problem requires printing "error " (with space) for both underflow and overflow. This prints "Stack is full\n" instead of "error ", violating output format.]
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