#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct Node
{
    int num;
    struct Node *lchild, *rchild;
}Node;
typedef struct Node *treeptr;

treeptr TreeInsert(treeptr T, int m)
{
    if (T == NULL)
    {
        treeptr p;
        p = (treeptr)malloc(sizeof(Node));
        p->num = m;
        p->lchild = p->rchild = NULL;
        T = p;
    }
    else if (m < T->num)
        T->lchild = TreeInsert(T->lchild, m);
    else if (m >= T->num)
        T->rchild = TreeInsert(T->rchild, m);
    return T;
}

void OutTree(treeptr t, int dt)
{
    if (t->lchild == NULL && t->rchild == NULL)
    {
        printf("%d %d\n", t->num, dt);
    }
    if (t->lchild != NULL)
        OutTree(t->lchild, dt + 1);
    if (t->rchild != NULL)
        OutTree(t->rchild, dt + 1);
    return;
}

int main()
{
    treeptr T = NULL;
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", &m);
        T = TreeInsert(T, m);
    }
    OutTree(T, 1);
    return 0;
}

