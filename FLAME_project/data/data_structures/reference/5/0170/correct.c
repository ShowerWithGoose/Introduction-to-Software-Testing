#include <stdio.h>
#include <stdlib.h>
struct formula
{
    int num;
    int power;
    struct formula *next;
};
struct formula *scanform(struct formula *);
struct formula *bubbleLink(struct formula *);
int main()
{
    struct formula *x1 = NULL, *x2 = NULL, *xfin = NULL, *current, *prev = NULL, *p, *q;
    x1 = scanform(x1);
    x2 = scanform(x2);
    /*
        current=x2;
        while (current != NULL)
        {
            printf("%d ", current->num);
            current = current->next;
        }
    */
    for (p = x1; p != NULL; p = p->next)
    {
        for (q = x2; q != NULL; q = q->next)
        {
            current = (struct formula *)malloc(sizeof(struct formula));
            if (xfin == NULL)
                xfin = current;
            else
                prev->next = current;
            current->next = NULL;
            current->num = (p->num) * (q->num);
            current->power = (p->power) + (q->power);
            prev = current;
        }
    }
    // goog before
    xfin = bubbleLink(xfin);
    current = xfin;
    while (current != NULL)
    {
        printf("%d ", current->num);
        printf("%d ", current->power);
        current = current->next;
    }
    current = xfin;
    while (xfin != NULL)
    {
        current = xfin;
        xfin = current->next;
        free(current);
    }

    return 0;
}
struct formula *scanform(struct formula *x)
{
    int xnum, xpower;
    struct formula *current, *prev;
    char tmpc = 0;
    x = prev = NULL;
    do
    {
        scanf("%d%d%c", &xnum, &xpower, &tmpc);
        current = (struct formula *)malloc(sizeof(struct formula));
        if (x == NULL)
            x = current;
        else
            prev->next = current;
        current->next = NULL;
        current->num = xnum;
        current->power = xpower;
        prev = current;
    } while (tmpc != '\n');

    return x;
}
struct formula *bubbleLink(struct formula *x) // congdadaoxiao
{
    int i, linknum = 0, j;
    struct formula *p, *q;
    /*
        for (p = xconst; p != NULL; p = p->next)
        {
            flg = 0;
            qmin = x;
            printf("1");
            for (q = xconst; q != NULL; q = q->next)
            {
                printf("1");
                if (q->next != NULL && q->power < q->next->power)
                {
                    if (q == x)
                    {
                        tmpp = q;
                        x = q->next;
                        tmpp->next = q->next->next;
                        x->next = tmpp;
                    }
                    else
                    {
                        qmin->next = q->next;
                        qmin->next->next = q;
                        q->next = q->next->next;
                        qmin = qmin->next;
                    }
                    flg = 1;
                }
                else if (q->next != NULL && q->power == q->next->power)
                {
                    q->num += q->next->num;
                    q->next = q->next->next;
                    flg = 1;
                }
            }
    */
    for (q = x; q != NULL; q = q->next)
        linknum++;
    for (i = 0; i < linknum - 1; i++)
    {
        p = q = x;
        j = linknum - i - 1;
        while (p->next != NULL && j != 0)
        {
            j--;
            if (p->power < p->next->power)
            {
                if (p == x)
                    x = p->next;
                else
                    q->next = p->next;
                q->next = p->next;
                q = q->next;
                p->next = q->next;
                q->next = p;
                p = q;
            }
            else if (p->power == p->next->power)
            {
                p->num += p->next->num;
                p->next = p->next->next;
            }
            q = p;
            p = p->next;
        }
    }

    return x;
}
