#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *l, *r;
} *head = NULL, *r = NULL;
void insertbst(int item)
{
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->l = NULL;
    p->r = NULL;
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        q = head;
        while (1)
        {
            if (q->data > item)
            {
                if (q->l == NULL)
                {
                    q->l = p;
                    break;
                }
                else
                {
                    q = q->l;
                    continue;
                }
            }
            else if (q->data <= item)
            {
                if (q->r == NULL)
                {
                    q->r = p;
                    break;
                }
                else
                {
                    q = q->r;
                    continue;
                }
            }
        }
    }
}
void perorder(struct node *t, int num)
{
    if (t->l == NULL && t->r == NULL)
    {
        printf("%d %d\n", t->data, num);
        return;
    }
    if (t != NULL)
    {
        if (t->l != NULL)
            perorder(t->l, num + 1);
        if (t->r != NULL)
            perorder(t->r, num + 1);
    }
    return;
}
int main()
{
    int i, n, tmp = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        insertbst(tmp);
    }
    r = head;
    perorder(r, 1);
    return 0;
}
