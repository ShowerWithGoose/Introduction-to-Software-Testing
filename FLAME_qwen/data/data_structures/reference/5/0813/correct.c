#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct poly
{
    int coe;
    int exp;
    struct poly *next;
};
typedef struct poly Poly;
typedef struct poly *Polyptr;
int main()
{
    Polyptr list1 = NULL, p1 = NULL, r1 = NULL;
    Polyptr list2 = NULL, p2 = NULL, r2 = NULL;
    Polyptr out = NULL, po = NULL, ro = NULL, be = NULL;
    int n1 = 0, n2 = 0, i, j, flag = 0;
    char stop;
    while (1 == 1)
    {
        if (list1 == NULL)
        {
            list1 = (Polyptr)malloc(sizeof(Poly));
            scanf("%d", &list1->coe);
            scanf("%d", &list1->exp);
            p1 = list1;
            p1->next = NULL;
            stop = getchar();
        }
        else
        {
            r1 = (Polyptr)malloc(sizeof(Poly));
            scanf("%d", &r1->coe);
            scanf("%d", &r1->exp);
            p1->next = r1;
            p1 = p1->next;
            p1->next = NULL;
            stop = getchar();
        }
        n1++;
        if (stop == '\n')
        {
            break;
        }
    }
    while (1 == 1)
    {
        if (list2 == NULL)
        {
            list2 = (Polyptr)malloc(sizeof(Poly));
            scanf("%d", &list2->coe);
            scanf("%d", &list2->exp);
            p2 = list2;
            p2->next = NULL;
            stop = getchar();
        }
        else
        {
            r2 = (Polyptr)malloc(sizeof(Poly));
            scanf("%d", &r2->coe);
            scanf("%d", &r2->exp);
            p2->next = r2;
            p2 = p2->next;
            p2->next = NULL;
            stop = getchar();
        }
        n2++;
        if (stop == '\n')
        {
            break;
        }
    }
    for (p1 = list1, i = 1; i <= n1; i++, p1 = p1->next)
    {
        for (p2 = list2, j = 1; j <= n2; j++, p2 = p2->next)
        {
            be = (Polyptr)malloc(sizeof(Poly));
            be->coe = p1->coe * p2->coe;
            be->exp = p1->exp + p2->exp;
            be->next = NULL;
            if (i == 1 && j == 1)
            {
                out = (Polyptr)malloc(sizeof(Poly));
                out->coe = be->coe;
                out->exp = be->exp;
                out->next = NULL;
            }
            else
            {
                for (ro = out, po = out; po != NULL; ro = po, po = po->next)
                {
                    if (be->exp == po->exp)
                    {
                        flag = 1;
                        po->coe = po->coe + be->coe;
                        break;
                    }
                    if (be->exp < ro->exp && be->exp > po->exp)
                    {
                        be->next = ro->next;
                        ro->next = be;
                        break;
                    }
                }
                if (flag == 0 && po == NULL)
                {
                    ro->next = be;
                }
                flag = 0;
            }
        }
    }
    for (po = out; po != NULL; po = po->next)
    {
        printf("%d %d ", po->coe, po->exp);
    }
    return 0;
}
