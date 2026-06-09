#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    struct stack *under;
    int numm;
} stack;

stack *ruzhan(stack *t)
{
    stack *h = (stack *)malloc(sizeof(stack));
    h->under = t;
    scanf("%d", &(h->numm));
    return h;
}

stack *chuzhan(stack *t)
{
    printf("%d ", t->numm);
    return t->under;
}

int stackdep(stack *h)
{
    int deps = 0;
    while (h != NULL)
    {
        deps++;
        h = h->under;
    }
    return deps;
}
int main()
{
    int op;
    stack *h = NULL;
    do
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (stackdep(h) >= 100)
            {
                printf("error ");
            }
            else
            {
                h = ruzhan(h);
            }
            break;
        case 0:
            if (stackdep(h) <= 0)
            {
                printf("error ");
            }
            else
            {
                h = chuzhan(h);
            }
        default:
            break;
        }
    } while (op != -1);
}
