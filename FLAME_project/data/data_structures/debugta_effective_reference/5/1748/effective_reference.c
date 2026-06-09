#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    int n;
} Node;
int cmp(const void *a, const void *b);
Node node1[1000], node2[1000], number[10000000];
int main()
{
    int i;
    int cnt1, cnt2;
    for (i = 0;; i++)
    {
        scanf("%d%d", &node1[i].num, &node1[i].n);
        cnt1 = i + 1;
        if (getchar() == '\n')
            break;
    }
    for (i = 0;; i++)
    {
        scanf("%d%d", &node2[i].num, &node2[i].n);
        cnt2 = i + 1;
        if (getchar() == '\n')
            break;
    }
    int k = 0, j;
    for (i = 0; i < cnt1; i++)
    {
        for (j = 0; j < cnt2; j++)
        {
            number[k].num = node1[i].num * node2[j].num;
            number[k].n = node1[i].n + node2[j].n;
            k++;
        }
    }
    qsort(number, k, sizeof(Node), cmp);
    for (i = 0; i < k; i++)
    {
        for (j = i + 1; j < k; j++)
        {
            if (number[i].n == number[j].n)
            {
                number[i].num += number[j].num;
                number[j].n = -1;
                number[j].num = 0;
            }
        }
    }
    for (i = 0; i < k; i++)
    {
        if (number[i].num == 0&&number[i].n==-1)
            continue;
        printf("%d %d ", number[i].num, number[i].n);
    }
    return 0;
}
int cmp(const void *a, const void *b)
{
    Node *s1 = (Node *)a;
    Node *s2 = (Node *)b;
    if (s1->n > s2->n)
        return -1;
    else if (s1->n == s2->n)
        return 0;
    else if (s1->n < s2->n)
        return 1;
}

