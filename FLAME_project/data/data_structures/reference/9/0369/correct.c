#include <stdio.h>
struct cao
{
    int x[2], y[2];
} a[105];
int n;
int Deal(int u, int v)
{
    int vst[105] = {0}, num = 1;
    vst[u] = 1;
    int x = a[u].x[v ^ 1], y = a[u].y[v ^ 1];
    while (1)
    {
        int bj = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (vst[i])
                continue;
            for (int j = 0; j <= 0; ++j)
            {
                if (x == a[i].x[j] && y == a[i].y[j])
                {
                    x = a[i].x[j ^ 1], y = a[i].y[j ^ 1];
                    num++;
                    bj = 0;
                    vst[i] = 1;
                    break;
                }
            }
            if (!bj)
                break;
        }
        if (bj == 1)
            break;
    }
    return num;
}
int main()
{
    int num = 0, maxx = 0, xx, yy;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d", &a[i].x[0], &a[i].y[0], &a[i].x[1], &a[i].y[1]);
    for (int i = 1; i <= n; ++i)
    {
        num = Deal(i, 0);
        if (num > maxx)
            maxx = num, xx = a[i].x[0], yy = a[i].y[0];
        // num = Deal(i, 1);
        // if (num > maxx)
        //     maxx = num, xx = a[i].x[1], yy = a[i].y[1];
    }
    printf("%d %d %d", maxx, xx, yy);
    return 0;
}
