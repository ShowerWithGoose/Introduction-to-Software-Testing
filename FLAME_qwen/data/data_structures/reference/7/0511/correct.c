#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    int height;
    struct Node *lchild, *rchild;
} BTNode, *BTREE;

BTREE STACK[1000];

BTREE INSERTBST(BTREE T, int v);

int main()
{
    int n, i;
    int data;
    BTREE T = NULL;
    scanf("%d", &n);
    if (n > 0)
        for (i = 0; i < n; i++)
        {
            scanf("%d", &data);
            T = INSERTBST(T, data);
        }
    int top = 0;
    BTREE p = T;
    if (T != NULL)
        while (!(p == NULL && top == 0))
        {
            while (p != NULL)
            {
                STACK[++top] = p;
                p = p->lchild;
            }
            p = STACK[top--];
            if (p->lchild == NULL && p->rchild == NULL)
                printf("%d %d\n", p->value, p->height);
            p = p->rchild;
        }
    return 0;
}

BTREE INSERTBST(BTREE T, int v)
{
    BTREE p, q;
    int depth;
    p = (BTREE)malloc(sizeof(BTNode));
    p->value = v;
    p->lchild = NULL;
    p->rchild = NULL;

    if (T == NULL)
    {
        p->height = 1;
        T = p;
    }
    else
    {
        q = T;
        depth = 1;
        while (1)
        {
            if (v < q->value)
            {
                if (q->lchild != NULL)
                {
                    q = q->lchild;
                    depth++;
                }
                else
                {
                    q->lchild = p;
                    depth++;
                    p->height = depth;
                    break;
                }
            }
            else
            {
                if (q->rchild != NULL)
                {
                    q = q->rchild;
                    depth++;
                }
                else
                {
                    q->rchild = p;
                    depth++;
                    p->height = depth;
                    break;
                }
            }
        }
    }
    return T;
}
