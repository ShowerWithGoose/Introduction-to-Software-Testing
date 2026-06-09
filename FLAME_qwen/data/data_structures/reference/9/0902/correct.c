#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct c
{
    int x1, y1;
    int x2, y2;
} IN;
IN in[MAX];
int n;
int used[MAX];
int cnt[MAX];
struct head
{
    IN co;
    struct head *link;
} h[MAX];
int cmp(const void *p, const void *q)
{
    return ((IN *)p)->x1 - ((IN *)q)->x1;
}
int main()
{
    struct head *p[MAX];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &in[i].x1, &in[i].y1, &in[i].x2, &in[i].y2);
    }
    qsort(in + 1, n, sizeof(in[1]), cmp);
    // for (int i = 1; i <= n; i++)
    // {
    //     printf("%d %d %d %d\n", in[i].x1, in[i].y1, in[i].x2, in[i].y2);
    // }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            h[i].co = in[i];
            p[i] = (struct head *)malloc(sizeof(struct head));
            p[i] = &h[i];
            cnt[i]++;
            used[i] = 1;
        }
        else
        {
            continue;
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (in[j].x1 == p[i]->co.x2 && in[j].y1 == p[i]->co.y2)
            {

                p[i] = p[i]->link;
                p[i] = (struct head *)malloc(sizeof(struct head));
                p[i]->co = in[j];
                cnt[i]++;
                used[j] = 1;
            }
        }
    }
    int maxCnt = cnt[0];
    int place = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > maxCnt)
        {
            maxCnt = cnt[i];
            place = i;
        }
    }
    printf("%d %d %d", maxCnt, in[place].x1, in[place].y1);
    return 0;
}

