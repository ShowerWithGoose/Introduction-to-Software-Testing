#include <stdio.h>
#define MAX 102

struct opstack
{
    int data[MAX];
    int top;
} s;

int a, i;
typedef struct opstack stack;

void instack(stack *s) { s->top = -1; }

int empty_stack(stack *s) { return s->top == -1; }

int full_stack(stack *s) { return s->top == MAX - 1; }

int push_stack(stack *s, int a)
{
    if (full_stack(s) != 0)
    {
        printf("error ");
        return 0;
    }
    s->data[++s->top] = a;
    return 1;
}

int pop_stack(stack *s, int a)
{
    if (s->top == -1)
    {
        printf("error ");
        return 0;
    }
    a = s->data[s->top--];
    printf("%d ", a);
    return 1;
}

int main(void)
{
    instack(&s);
    int type = -1;
    while (1)
    {
        scanf("%d", &type);
        if (type == -1)
            break;
        else if (type == 0)
            pop_stack(&s, a);
        else if (type == 1)
        {
            scanf("%d", &i);
            push_stack(&s, i);
        }
    }
}



