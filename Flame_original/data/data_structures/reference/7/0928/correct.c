#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} * root;

struct node *insert(struct node *p, int item)
{
    if (p == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = item;
        p->lchild = NULL;
        p->rchild = NULL;
    }
    else if (item < p->data)
    {
        p->lchild = insert(p->lchild, item);
    }
    else if (item >= p->data)
    {
        p->rchild = insert(p->rchild, item);
    }
    return p;
}
void print(struct node *p, int depth)
{

    if (p == NULL)
        return;
    print(p->lchild, depth + 1);
    print(p->rchild, depth + 1);
    if (p->lchild == NULL && p->rchild == NULL)
        printf("%d %d\n", p->data, depth);
}
int main()
{
    int n, e;
    root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        root = insert(root, e);
    }
    print(root, 1);
    return 0;
}

