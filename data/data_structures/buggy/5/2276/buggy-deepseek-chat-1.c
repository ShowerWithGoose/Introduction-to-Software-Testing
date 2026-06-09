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

    while (scanf("%d%d", &b[m][0], &b[m][1]) != EOF) // @@ [Error: This loop reads until EOF, but the input format specifies that the second polynomial ends with a newline, not EOF. This will cause incorrect reading or infinite waiting if input is from console.]
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
            for (p = head; p!= NULL||p==head; p = (p->next)) // @@ [Error: The loop condition `p!= NULL||p==head` is always true when p is not NULL, and when p is NULL, p==head is false (unless head is NULL, but head is not NULL), so this becomes an infinite loop when p becomes NULL. The correct condition should be `p != NULL`.]
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