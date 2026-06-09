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

    while (scanf("%d%d", &b[m][0], &b[m][1]) != EOF) // @@ 读取第二个多项式应使用与第一多项式相同的循环方式（读取直到换行），EOF方式无法在交互式输入中正确结束，会导致后续处理错误
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

    num *new = (num *)malloc(sizeof(num)); // @@ 创建了系数为0、指数为0的哑元节点，会导致最终结果中输出多余的(0,0)项
    new->zs = 0; // @@ 同上
    new->xs = 0; // @@ 同上
    new->next = NULL; // @@ 同上
    num *head = new; // @@ 同上
    num *p;

    int i, j, lqc; // lqc=计算所得指数
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            lqc = a[i][1] + b[j][1];
            for (p = head; p!= NULL||p==head; p = (p->next))
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

                    new->next = p; // @@ 当需要将新节点插入到当前节点p之前时，只更新了head而没有更新p的前驱节点的next指针，导致链表断裂，p之前的节点丢失
                    head = new; // @@ 同上，此操作只对插入到链表头部有效，若p不是头节点则导致链表结构错误
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