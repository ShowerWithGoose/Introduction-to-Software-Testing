#include <stdio.h>
#include <stdlib.h>

struct node
{
    long long coe;
    long long exp;
    struct node *link;
};
typedef struct node Node;
typedef struct node *Nodeptr;
long long a[105][2];

int main()
{
    Nodeptr head, p, q;
    int i, n = 0;
    long long coe, exp;
    char ch;
    head = p = NULL;
    do //读入第一个多项式
    {
        scanf("%lld%lld%c", &a[n][0], &a[n][1], &ch);
        n++;
    } while (ch != '\n');
    do //读入第二个多项式
    {
        scanf("%lld%lld", &coe, &exp);
        ch=getchar();
        for (i = 0; i < n; i++)
        {
            q = (Nodeptr)malloc(sizeof(Node));
            q->coe = coe * a[i][0];
            q->exp = exp + a[i][1];
            q->link = NULL;
            if (head == NULL)
                head = p = q;
            else
            {
                Nodeptr pl = head, pr = head;
                while (pr->exp > q->exp)
                {
                    pl = pr;
                    pr = pr->link;
                    if (pr == NULL)
                        break;
                }
                if (pr != NULL)
                {
                    if (pr->exp == q->exp)
                    {
                        pr->coe += q->coe;
                        free(q);
                    }
                    else
                    {
                        q->link = pr;
                        pl->link = q;
                    }
                }
                else
                    pl->link=q;
            }
        }
    } while (ch != '\n');
    q = head;
    while (q != NULL)
    {
        printf("%d %d ", q->coe, q->exp);
        q=q->link;
    }
    return 0;
}
