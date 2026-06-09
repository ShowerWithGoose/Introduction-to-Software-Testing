#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *l, *r;
} tn, *tnp;

tnp creat(int n)
{
    tnp p = NULL;
    p = (tnp)malloc(sizeof(tnp));
    p->l = p->r = NULL;
    p->num = n;
    return p;
}
tnp insert(tnp tmp, int n)
{
    if (tmp == NULL)
        tmp = creat(n);
    else
    {
        if (n < tmp->num)
            tmp->l = insert(tmp->l, n);
        else
            tmp->r = insert(tmp->r, n);
    }
    return tmp;
}

void in(tnp tmp, int deep)
{
    if (tmp != NULL)
    {
        if (tmp->l==NULL&&tmp->r==NULL)
            printf("%d %d\n\n",tmp->num,deep);
        else
        {
            in(tmp->l,deep+1);
            in(tmp->r,deep+1);
        }
    }
}

tnp root = NULL;

int main()
{
    int a, m;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &m);
        root = insert(root, m);
    }
    in(root, 1);
    return 0;
}



