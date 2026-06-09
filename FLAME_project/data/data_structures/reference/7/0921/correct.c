#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    int data;
    int depth;
    struct node *lchild, *rchild;
};
struct node *insert(struct node *p, int d);
int dp;
void preorder(struct node *p);
int main()
{
    int i, t, j;
    struct node *root = NULL;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d", &j);
        root = insert(root, j);
    }
    preorder(root);
    return 0;
}

struct node *insert(struct node *p, int d)
{
    if (p == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->lchild = NULL;
        p->rchild = NULL;
        p->data = d;
        p->depth = 1;
    }
    else
    {
        if (d >= p->data)
        {
            p->rchild = insert(p->rchild, d);
            p->rchild->depth = p->depth + 1;
        }
        else
        {
            p->lchild = insert(p->lchild, d);
            p->lchild->depth = p->depth + 1;
        }
    }
    return p;
}
void preorder(struct node *p)
{
    if (p != NULL)
    {
        if (p->lchild == NULL && p->rchild == NULL)
        {
            printf("%d %d\n", p->data, p->depth);
        }
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
