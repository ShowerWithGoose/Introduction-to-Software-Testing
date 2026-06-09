#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct muti
{
    int num;
    int exp;
    struct muti *link;
};
typedef struct muti *Nodeptr;
typedef struct muti Node;
Nodeptr p1, p2, p = NULL, list1 = NULL, list2 = NULL, list = NULL;

signed main()
{
    Nodeptr r1, r2, q, s;
    char c;
    while (1)
    {
        r1 = (Nodeptr)malloc(sizeof(Node));
        scanf("%d %d%c", &r1->num, &r1->exp, &c);
        r1->link = NULL;
        if (list1 == NULL)
            list1 = p1 = r1;
        else
        {
            p1->link = r1;
            p1 = p1->link;
        }
        if (c == '\n')
            break;
    }
    while (1)
    {
        r2 = (Nodeptr)malloc(sizeof(Node));
        scanf("%d %d%c", &r2->num, &r2->exp, &c);
        r2->link = NULL;
        if (list2 == NULL)
            list2 = p2 = r2;
        else
        {
            p2->link = r2;
            p2 = p2->link;
        }
        if (c == '\n')
            break;
    }
    for (p1 = list1; p1 != NULL; p1 = p1->link)
        for (p2 = list2; p2 != NULL; p2 = p2->link)
        {
            q = (Nodeptr)malloc(sizeof(Node));
            if (list == NULL)
            {
                list = p = q;
                list->num = (p1->num) * (p2->num);
                list->exp = (p1->exp) + (p2->exp);
            }
            else
            {
                q->num = (p1->num) * (p2->num);
                q->exp = (p1->exp) + (p2->exp);
                q->link = NULL;
                if ((q->exp) < (p->exp))
                {
                    p->link = q;
                    p = p->link;
                }
                else if ((q->exp) == (p->exp))
                {
                    p->num = (p->num) + (q->num);
                }
                else
                {
                    if (q->exp > list->exp)
                    {
                        q->link = list;
                        list = q;
                    }
                    else
                    {
                        s = (Nodeptr)malloc(sizeof(Node));
                        s = list;
                        while (1)
                        {
                            if (s->exp == q->exp)
                            {
                                s->num = (s->num) + (q->num);
                                break;
                            }
                            if (s->exp > q->exp && s->link->exp < q->exp)
                            {
                                q->link = s->link;
                                s->link = q;
                                break;
                            }
                            s = s->link;
                        }
                    }
                }
            }
        }
    for (p = list; p != NULL; p = p->link)
        if (p->num != 0)
            printf("%d %d ", p->num, p->exp);
    return 0;
}


