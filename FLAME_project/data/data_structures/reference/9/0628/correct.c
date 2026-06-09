#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;

struct line
{
    int x1, y1, x2, y2, id;
    struct line *next;
} a[110];
int n, flag[100], ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        a[i].next = NULL, a[i].id = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i].x1 == a[j].x2 && a[i].y1 == a[j].y2)
                a[j].next = &a[i];
        }
    }
    struct line *p, *ans_p;
    int tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!flag[i])
        {
            tmp = 0;
            for (p = a + i; p != NULL; p = p->next)
            {
                flag[p->id] = 1;
                ++tmp;
            }
            if (tmp > ans)
            {
                ans = tmp;
                ans_p = a + i;
            }
        }
    }
    printf("%d %d %d\n", ans, ans_p->x1, ans_p->y1);
    return 0;
}
