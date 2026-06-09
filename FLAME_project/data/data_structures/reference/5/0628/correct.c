#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct mul
{
    int co, in;
    struct mul *next;
} a1, a2, ans;

int read(int *x)
{
    *x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        *x = (*x) * 10 + ch - '0';
        ch = getchar();
    }
    return ch == '\n' ? -1 : 0;
}

int main()
{
    struct mul *p = NULL, *q = NULL, *pAns = NULL, *pTmp = NULL;
    ans.co = ans.in = 2147483647, ans.next = NULL;
    p = &a1;
    while (~read(&(p->co)) && ~read(&(p->in)))
    {
        p->next = malloc(sizeof(struct mul));
        p = p->next;
    }
    p->next = NULL;
    q = &a2;
    while (~read(&(q->co)) && ~read(&(q->in)))
    {
        q->next = malloc(sizeof(struct mul));
        q = q->next;
    }
    q->next = NULL;
    int tco, tin;
    for (p = &a1; p != NULL; p = p->next)
        for (q = &a2; q != NULL; q = q->next)
        {
            tco = p->co * q->co, tin = p->in + q->in;
            for (pAns = &ans; pAns != NULL; pAns = pAns->next)
            {
                if (pAns->in == tin)
                {
                    pAns->co += tco;
                    break;
                }
                else if (pAns->in > tin && (pAns->next == NULL || pAns->next->in < tin))
                {
                    pTmp = malloc(sizeof(struct mul));
                    pTmp->co = tco, pTmp->in = tin, pTmp->next = pAns->next;
                    pAns->next = pTmp;
                    break;
                }
            }
        }
    for (pAns = ans.next; pAns != NULL; pAns = pAns->next)
        printf("%d %d ", pAns->co, pAns->in);
    putchar('\n');
    return 0;
}
