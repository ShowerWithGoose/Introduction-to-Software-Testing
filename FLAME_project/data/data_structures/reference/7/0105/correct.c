#include <stdio.h>
#include <stdlib.h>
typedef struct Tree
{
    struct Tree *left, *right;
    int date;
} BiTNode, *BiTree;

int depth = 0;

void add(BiTree T, BiTree C)
{
    if (T->date >= C->date)
    {
        if (C->right == NULL)
        {
            C->right = T;
        }
        else
        {
            add(T, C->right);
        }
    }
    else
    {
        if (C->left == NULL)
        {
            C->left = T;
        }
        else
        {
            add(T, C->left);
        }
    }
}

void visit(BiTree t)
{
    if (t->left == NULL && t->right == NULL)
    {
        printf("%d %d\n", t->date, depth);
    }
}

void FDR(BiTree t)
{
    depth++;
    if (t != NULL)
    {
        visit(t);
        FDR(t->left);
        FDR(t->right);
    }
    depth--;
}

int main()
{
    int m;
    scanf("%d", &m);
    BiTree ro = (BiTree)malloc(sizeof(BiTNode));
    ro->left = NULL;
    ro->right = NULL;
    scanf("%d", &ro->date);
    for (int i = 0; i < m - 1; i++)
    {
        BiTree T = (BiTree)malloc(sizeof(BiTNode));
        scanf("%d", &T->date);
        T->left = NULL;
        T->right = NULL;
        add(T, ro);
    }
    FDR(ro);
}
