#include <stdio.h>
#define Maxsize 100
struct node
{
    int data[Maxsize];
    int top;
} Stack;
void push(struct node *, int);
void pop(struct node *);
int main()
{
    Stack.top = -1;
    int op, n;
    do
    {
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            pop(&Stack);
            break;
        case 1:
            scanf("%d", &n);
            push(&Stack, n);
        }
    } while (op != -1);

    return 0;
}
void push(struct node *stack, int value)
{
    if (stack->top == Maxsize - 1)
        printf("error ");
    else
    {
        stack->top++;
        stack->data[stack->top] = value;
    }
}
void pop(struct node *stack)
{
    if (stack->top == -1)
        printf("error ");
    else
    {
        printf("%d ", stack->data[stack->top]);
        // stack->data[stack->top] = 0;
        stack->top--;
    }
}
