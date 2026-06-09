#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
struct t
{
    int data;
    struct t *l, *r;
};
int n, i, temp, layer;
struct t *insertBST(struct t *p, int item)
{
    if (p == NULL)
    {
        p = (struct t *)malloc(sizeof(struct t));
        p->data = item;
        p->l = p->r = NULL;
    }
    else if (item < p->data)
    {
        p->l = insertBST(p->l, item);
    }
    else if (item >= p->data)
    {
        p->r = insertBST(p->r, item);
    }
    return p;
}
void visit(struct t *pp)
{
    if (pp->l == NULL && pp->r == NULL)
    {
        printf("%d %d\n", pp->data, layer);
    }
}
void inorder(struct t *p)
{
    if (p != NULL)
    {
        layer++;
        inorder(p->l);
        visit(p);
        inorder(p->r);
        layer--;
    }
}

int main()
{
    scanf("%d", &n);
    struct t *root = NULL;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        root = insertBST(root, temp);
    }
    inorder(root);
    return 0;
}

