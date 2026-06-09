#include <stdio.h>
typedef int Datatype;
int i;
typedef struct node
{
    struct node *l, *r;
    Datatype data;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr root = NULL;
BTNodeptr insertBST(BTNodeptr p, Datatype item)
{
    if(p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->l = p->r = NULL;
    }
    else if(item < p->data)
        p->l = insertBST(p->l, item);
    else if(item >= p->data)
        p->r = insertBST(p->r, item);
    return p;
}
int getNodeLevel(BTNodeptr bt, BTNodeptr p)
{
    if (bt == NULL)
        return 0;
    else
    {
        if (bt == p)
            return 1;
        int L = getNodeLevel(bt->l, p);
        int R = getNodeLevel(bt->r, p);
        if (L || R)
            return 1 + (L > R ? L : R);
        else
            return 0;
    }
}

void pre_order(BTNodeptr t)
{
    if(t != NULL)
    {
        if(isLeaf(t))
            printf("%d %d\n", t->data, getNodeLevel(root, t));
        pre_order(t->l);
        pre_order(t->r);
    }
}
int isLeaf(BTNodeptr q)
{
    if(q->l == NULL && q->r == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    int n, item;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = insertBST(root, item);
    }

    pre_order(root);
    return 0;
}

