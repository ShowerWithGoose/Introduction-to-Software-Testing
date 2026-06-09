#include <stdio.h>
#include <stdlib.h>

struct node{
    int x1;
    int x2;
    int y1;
    int y2;
} p[110];
int vis[110];
int cmp(const void *p1, const void *p2)
{
    return (((struct node*)p1)->x1) - (((struct node*)p2)->x1);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
        //printf("%d %d %d %d\n", p[i].x1, p[i].y1, p[i].x2, p[i].y2);
    }
    qsort(p, n, sizeof(struct node), cmp);
    //for (int i = 0; i < n; i++)
    //{
        //printf("%d %d %d %d\n", p[i].x1, p[i].y1, p[i].x2, p[i].y2);
    //}
    int cnt = 0, maxcnt = 0, maxpoint;
    for (int i = 0; i < n; i++)
    {
        struct node now = p[i];
        cnt = 1;
        if (vis[i]) continue;
        vis[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if(vis[j]) continue;
            if (p[j].x1 == now.x2 && p[j].y1 == now.y2)
            {
                vis[j] = 1;
                now = p[j];
                cnt++;
            }
        }
        if (cnt > maxcnt)
        {
            maxcnt = cnt;
            maxpoint = i;
        }
    }
    printf("%d %d %d\n", maxcnt, p[maxpoint].x1, p[maxpoint].y1);
    return 0;
}
