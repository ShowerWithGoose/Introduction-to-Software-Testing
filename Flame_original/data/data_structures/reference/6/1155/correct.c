#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef int ElemType;
typedef struct Node
{
    ElemType num;
    struct Node *link;
}Node;
typedef struct Node *stackptr;

stackptr stackpush(stackptr S, int a)
{
    stackptr p;
    p = (stackptr)malloc(sizeof(Node));
    p->num = a;
    p->link = NULL;
    if (S == NULL)
    {
        S = p;
    }
    else
    {
        p->link = S;
        S = p;
    }
    return S;
}

stackptr stackpop(stackptr S)
{
    if (S == NULL)
        printf("error ");
    else
    {
        stackptr p;
        ElemType a;
        p = S;
        S = S->link;
        a = p->num;
        printf("%d ", a);
        free(p);
    }
    return S;
}

int main()
{
    int n;
    stackptr S = NULL;
    scanf("%d", &n);
    while (n != -1)
    {
        if (n == 1)
        {
            scanf("%d", &n);
            S = stackpush(S, n);
        }
        else if (n == 0)
        {
            S = stackpop(S);
        }
        scanf("%d", &n);
    }
    return 0;
}

