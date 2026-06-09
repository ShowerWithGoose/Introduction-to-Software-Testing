#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct tre
{
    int depth, num;
    struct tre *l, *r;
} tree;

tree *cur = NULL;

void build_tree(tree *y, tree *cur)
{
    if (cur == NULL)
    {
        cur = cur;
        cur->depth = 1;
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
void printftree(tree *cur)
{
    if (cur->l != NULL)
        printftree(cur->l);
    if (cur->r != NULL)
        printftree(cur->r);
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
        int x;
        scanf("%d", &x);
        tree *p = malloc(sizeof (tree));
        p->num = x;
        p->l = NULL;
        p->r = NULL;
        build_tree(cur, p);
    }
    printftree(cur);
    return 0;
}
