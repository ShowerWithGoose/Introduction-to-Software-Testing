#include <stdio.h>
#include <stdlib.h>

struct stackRecord
{
    int capacity;
    int topOfStack;
    int *array;
};
typedef struct stackRecord *ptrStack;

ptrStack createStack(int maxELem, ptrStack S);
void makeEmpty(ptrStack S);
void push(int x, ptrStack S);
void pop(ptrStack S);

int main()
{
    ptrStack S;
    int op, num;
    S = createStack(100, S);
    while (1)
    {
        scanf("%d", &op);
        switch (op)
        {
        case -1:
        {
            return 0;
        }
        case 0:
        {
            pop(S);
            break;
        }
        case 1:
        {
            scanf("%d", &num);
            push(num, S);
            break;
        }
        }
    }
    return 0;
}

ptrStack createStack(int maxElem, ptrStack S)
{
    S = malloc(sizeof(struct stackRecord));
    S->array = malloc(sizeof(int) * maxElem);
    S->capacity = maxElem;
    makeEmpty(S);
    return S;
}

void makeEmpty(ptrStack S)
{
    S->topOfStack = -1;
}

void push(int x, ptrStack S)
{
    if (S == NULL)
    {
        printf("error ");
        return;
    }
    S->array[++S->topOfStack] = x;
}

void pop(ptrStack S)
{
    if (S->topOfStack == -1)
    {
        printf("error ");
        return;
    }
    printf("%d ", S->array[S->topOfStack]);
    S->topOfStack--;
}
