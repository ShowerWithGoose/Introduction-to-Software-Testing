#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXINT 2147483547
#define eps 1e-10
#define ll long long

typedef struct stack
{
    int *base;
    int *top;
    int sz;
} Stack;

void initStack(Stack *s)
{
    s->base = (int *)malloc(sizeof(int) * 100);
    if (!s->base)
        exit(0);
    s->top = s->base;
    s->sz = 100;
}

void Push(Stack *s, int val)
{

    if (s->top - s->base == s->sz)
    {
        printf("error ");
        return;
    }
    *(s->top) = val;
    (s->top)++;
}

void Pop(Stack *s, int *e)
{
    if (s->base == s->top)
    {
        printf("error ");
        return;
    }
    (s->top)--;
    *e = *(s->top);
    printf("%d ", *e);
}

int main()
{
    int op, in, out;

    Stack s;
    initStack(&s);

    do
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &in);
            Push(&s, in);
        }

        else if (op == 0)
        {
            Pop(&s, &out);
        }
    } while (op != -1);
    return 0;
}
