#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coe;
    int pow;
    struct node *next;
} * list, *ans;
int main()
{
    int a, b;
    char c;
    struct node *p, *q, *p0, *p1;
    ans = list = p = p0 = NULL;
    do
    {
        scanf("%d%d%c", &a, &b, &c);
        q = (struct node *)malloc(sizeof(struct node));
        q->coe = a;
        q->pow = b;
        q->next = NULL;
        if (list == NULL)
        {
            list = p = q;
        }
        else
        {
            p->next = q;
            p = p->next;
        }
    } while (c != '\n');
    ans = (struct node *)malloc(sizeof(struct node));
    ans->coe = 0;
    ans->pow = 0;
    ans->next = NULL;
    do
    {
        scanf("%d%d%c", &a, &b, &c);
        for (p1 = list; p1 != NULL; p1 = p1->next)
        {
            q = (struct node *)malloc(sizeof(struct node));
            q->coe = a * p1->coe;
            q->pow = b + p1->pow;
            q->next = NULL;
            for (p = ans; p != NULL; p0 = p, p = p->next)
            {
                if (q->pow > p->pow)
                {
                    if (p == ans)
                    {
                        q->next = ans;
                        ans = q;
                        break;
                    }
                    else
                    {
                        q->next = p;
                        p0->next = q;
                        break;
                    }
                }
                else if (q->pow == p->pow)
                {
                    p->coe += q->coe;
                    free(q);
                    break;
                }
            }
            if (p == NULL)
            {
                p0->next = q;
            }
        }
    } while (c != '\n');
    for (p = ans; p != NULL; p = p->next)
    {
        if (p->coe != 0)
        {
            printf("%d %d ", p->coe, p->pow);
        }
    }
    return 0;
}
