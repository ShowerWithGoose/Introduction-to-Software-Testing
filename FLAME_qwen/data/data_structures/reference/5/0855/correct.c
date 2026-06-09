#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    int pow;
} Node;
int cmp(const void *a, const void *b);
Node node1[1000], node2[1000], ans[10000000];
int main()
{
    int i;
    int cnt1, cnt2;
    for (i = 0;; i++)
    {
        scanf("%d%d", &node1[i].num, &node1[i].pow);
        cnt1 = i + 1;
        if (getchar() == '\n')
            break;
    }
    for (i = 0;; i++)
    {
        scanf("%d%d", &node2[i].num, &node2[i].pow);
        cnt2 = i + 1;
        if (getchar() == '\n')
            break;
    }
    int k = 0, j;
    for (i = 0; i < cnt1; i++)
    {
        for (j = 0; j < cnt2; j++)
        {
            ans[k].num = node1[i].num * node2[j].num;
            ans[k].pow = node1[i].pow + node2[j].pow;
            k++;
        }
    }
    qsort(ans, k, sizeof(Node), cmp);
    for (i = 0; i < k; i++)
    {
        for (j = i + 1; j < k; j++)
        {
            if (ans[i].pow == ans[j].pow)
            {
                ans[i].num += ans[j].num;
                ans[j].pow = -1;
                ans[j].num = 0;
            }
        }
    }
    for (i = 0; i < k; i++)
    {
        if (ans[i].num == 0&&ans[i].pow==-1)
            continue;
        printf("%d %d ", ans[i].num, ans[i].pow);
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    Node *s1 = (Node *)a;
    Node *s2 = (Node *)b;
    if (s1->pow > s2->pow)
        return -1;
    else if (s1->pow == s2->pow)
        return 0;
    else if (s1->pow < s2->pow)
        return 1;
}

