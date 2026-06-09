#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct tre
{
    int depth, num;
    struct tre *l, *r;
} tree;

tree *root = NULL;

void build_tree(tree *y, tree *cur)
{
    if (root == NULL)
    {
        root = cur;
        root->depth = 1;
        return ;
    }
    else if (cur->num < y->num)
    {
        if (y->l != NULL)
            build_tree(y->l, cur);
        else
        {
            y->l = cur;
            cur->depth = y->depth + 1;
        }
    }
    else if (cur->num >= y->num)
    {
        if (y->r != NULL)
            build_tree(y->r, cur);
        else 
        {
            y->r = cur;
            cur->depth = y->depth + 1;
        }
    }
}
void out_tree(tree *cur)
{
    if (cur->l != NULL)
        out_tree(cur->l);
    if (cur->r != NULL)
        out_tree(cur->r);
    if (cur->l == NULL && cur->r == NULL)
    {
        printf("%d %d\n", cur->num, cur->depth);
        return ;
    }
}

int main()
{
    scanf("%d", &n);
    while (n -- )
    {
        int num1;
        scanf("%d", &num1);
        tree *p = malloc(sizeof (tree));
        p->num = num1;
        p->l = NULL;
        p->r = NULL;
        build_tree(root, p);
    }
    out_tree(root);
    return 0;
}
