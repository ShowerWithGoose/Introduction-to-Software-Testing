#include <stdio.h>
#include <stdlib.h>

typedef struct number
{
    int xs; // 系数0
    int zs; // 指数
    struct number *next;
} num;
int a[10000][4], b[10000][4];

int main()
{
    int n = 0, m = 0; // n个数据
    char ch;
    while (1)
    {
        scanf("%d%d", &a[n][0], &a[n][1]);
        n++;
        ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }

    while (scanf("%d%d", &b[m][0], &b[m][1]) != EOF)
    {
        m++;
    }
    /*while (1)
    {
        scanf("%d%d", &b[m][0], &b[m][1]);
        m++;
        ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }*/

    num *new = (num *)malloc(sizeof(num));
    new->zs = 0;
    new->xs = 0;
    new->next = NULL;
    num *head = new;
    num *p;

    int i, j, lqc; // lqc=计算所得指数
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            lqc = a[i][1] + b[j][1];
            for (p = head; p!= NULL||p==head; p = (p->next)) // @@ The loop condition `p!= NULL||p==head` is logically flawed. When `p` is `head` and `head` is not NULL, the condition is always true, but when `p` becomes NULL, the loop should stop. However, `p==head` is only true for the first iteration, so after that, the condition reduces to `p!=NULL`, which is correct. But the `||` causes an issue: when `p` becomes NULL, `p!=NULL` is false, but `p==head` is also false (since head is not NULL), so the loop exits. However, the real problem is that the loop does not handle the case where the new term should be inserted at the beginning correctly, and the logic for inserting in the middle or end is flawed because the loop traverses the list but the insertion logic assumes `p` is the node before the insertion point, which is not always the case. Additionally, the condition `p!= NULL||p==head` is redundant and confusing.
            {
                if (p->zs > lqc)
                {
                    if ((p->next) == NULL || (p->next)->zs < lqc)
                    {
                        num *new = (num *)malloc(sizeof(num));
                        new->zs = lqc;
                        new->xs = a[i][0] * b[j][0];
                        new->next = NULL;

                        new->next = p->next;
                        p->next = new;
                        break;
                    }
                }
                else if (p->zs == lqc)
                {
                    p->xs += a[i][0] * b[j][0];
                    break;
                }
                else
                {
                    num *new = (num *)malloc(sizeof(num));
                    new->zs = lqc;
                    new->xs = a[i][0] * b[j][0];
                    new->next = NULL;

                    new->next = p;
                    head = new;
                    break;
                }
            }
        }
    }

    for (p = head; p != NULL; p = p->next)
    {
        printf("%d %d ", p->xs, p->zs);
    }
}