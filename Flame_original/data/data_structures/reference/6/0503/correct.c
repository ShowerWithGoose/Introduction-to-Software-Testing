#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ElementType int
#define ERROR -1

typedef struct Node *stack;

struct Node
{
    ElementType Data[MAXSIZE];
    int Top;
};

int IsFull(stack Sptr)
{
    return Sptr->Top == MAXSIZE-1;
}

int IsEmpty(stack Sptr)
{
    return Sptr->Top == -1;
}

void Push(stack Sptr, ElementType item)
{
    Sptr->Data[++(Sptr->Top)] = item;
}

ElementType Pop(stack Sptr)
{
    return Sptr->Data[(Sptr->Top)--];
}

int main()
{
    int tempCell, op, ans[100], i = 0;
    struct Node S;
    stack Sptr = &S;
    Sptr->Top = -1;

    while (1)
    {
        scanf("%d", &op);
        if (-1 == op)
            break;
        else if (1 == op)
        {
            scanf("%d", &tempCell);
            if (IsFull(Sptr))
                ans[i++] = 0;
            else
                Push(Sptr, tempCell);
        }
        else if (0 == op)
        {
            if (IsEmpty(Sptr))
                ans[i++] = 0;
            else
                ans[i++] = Pop(Sptr);
        }
    }

    for (int j = 0;j < i;j ++)
    {
        if (ans[j])
            printf("%d ", ans[j]);
        else
            printf("error ");
    }

    return 0;
}

