#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ElemType int
ElemType STACK[MAXSIZE];
int Top;

void Error(char *s)
{
    printf("%s\n", s);
    exit(-1);
}

void initStack()
{
    Top = -1;
}

int isEmpty()
{
    return Top == -1;
}

int isFull()
{
    return Top == MAXSIZE - 1;
}

void push(ElemType *s, ElemType item) //这个不需要返回值，所以用void
{
    if (isFull())
        printf("error ");
    else
        s[++Top] = item;
}

ElemType pop(ElemType *s)
{
    if (isEmpty())
        printf("error ");
    else
        return s[Top--];
}

int main()
{
    int op, data;

    initStack();

    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break;
        else if (op == 0)
        {
            if (isEmpty())
                printf("error ");
            else
                printf("%d ", STACK[Top--]);
        }
        else if (op == 1)
        {
            scanf("%d", &data);
            if (isFull())
                printf("error ");
            else
                STACK[++Top] = data;
        }
    }

    return 0;
}
