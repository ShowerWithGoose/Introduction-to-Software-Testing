#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int n, ans = 0;

struct line
{
    int from_x, from_y;
    int to_x, to_y;
    struct line *link_l, *link_r;
} a[105];

struct line *p;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        a[i].link_l = a[i].link_r = NULL;
        scanf("%d%d%d%d", &a[i].from_x, &a[i].from_y, &a[i].to_x, &a[i].to_y);
        for (int j = 1; j < i; j ++ )
        {
            if (a[j].to_x == a[i].from_x && a[j].to_y == a[i].from_y)
            {
                a[i].link_l = a + j;
                a[j].link_r = a + i;
            }
            if (a[j].from_x == a[i].to_x && a[j].from_y == a[i].to_y)
            {
                a[j].link_l = a + i;
                a[i].link_r = a + j;
            }
        }
    }
    for (int i = 1; i <= n; i ++ )
    {
        int cnt = 1;
        struct line *tmp;
        if (a[i].link_r == NULL)
        {
            tmp = a + i;
            while (tmp->link_l != NULL)
            {
                tmp = tmp->link_l;
                cnt ++;
            }
            if (cnt > ans)
            {
                ans = cnt;
                p = tmp;
            }
        }
    }
    printf("%d %d %d", ans, p->from_x, p->from_y);
    return 0;
}
