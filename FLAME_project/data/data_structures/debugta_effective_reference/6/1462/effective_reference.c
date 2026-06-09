#include <stdio.h>
#define MAX 100
struct stack
{
    int data[105];
    int top;
} s;

typedef struct stack stack;

int Push(stack *s, int a)
{
    if (s->top == MAX - 1)
        return 0;
    s->data[++s->top] = a;
    return 1;
}

int Pop(stack *s)
{
    if (s->top == -1)
    {
        printf("error ");
        return 0;
    }
    printf("%d ", s->data[s->top--]);
    return 1;
}

void initstack(stack *s)
{
    s->top = -1;
}

int main()
{
    initstack(&s);
    int a, op;
    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break;
        else if (op == 1)
        {
            scanf("%d", &a);
            Push(&s, a);
        }
        else if (op == 0)
            Pop(&s);
    }
    return 0;
}
