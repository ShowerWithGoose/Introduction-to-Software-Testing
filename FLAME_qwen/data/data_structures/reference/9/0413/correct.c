#include <stdio.h>

struct lines
{
    int num;
    int sx;
    int sy;
    int ex;
    int ey;
} l[105];

int main()
{
    int n, i, j, sx, sy, ex, ey, cnt = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int flag = 1;
        scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
        for (j = 0; j < cnt; j++)
        {
            if (l[j].ex == sx && l[j].ey == sy)
            {
                l[j].ex = ex;
                l[j].ey = ey;
                l[j].num++;
                flag &= 0;
                break;
            }
            else if (l[j].sx == ex && l[j].sy == ey)
            {
                l[j].sx = sx;
                l[j].sy = sy;
                l[j].num++;
                flag &= 0;
                break;
            }
        }
        if (flag == 1)
        {
            l[cnt].num++;
            l[cnt].sx = sx;
            l[cnt].sy = sy;
            l[cnt].ex = ex;
            l[cnt].ey = ey;
            cnt++;
        }
    }
    for (i = 0; i < cnt; i++)
        for (j = 0; j < cnt; j++)
        {
            if (i == j)
                continue;
            else if (l[i].ex == l[j].sx && l[i].ey == l[j].sy)
            {
                l[j].sx = l[i].sx;
                l[j].sy = l[i].sy;
                l[j].num += l[i].num;
                l[i].num = -1;
                l[i].sx = -i;
                l[i].sy = -i;
                l[i].ex = -i;
                l[i].ey = -i;
            }
            else if (l[i].sx == l[j].ex && l[i].sy == l[j].ey)
            {
                l[i].sx = l[j].sx;
                l[i].sy = l[j].sy;
                l[i].num += l[j].num;
                l[j].num = -1;
                l[j].sx = -j;
                l[j].sy = -j;
                l[j].ex = -j;
                l[j].ey = -j;
            }
        }
    int max, maxlines = 0;
    for (i = 0; i < cnt; i++)
        if (l[i].num > maxlines)
        {
            max = i;
            maxlines = l[i].num;
        }
    printf("%d %d %d", l[max].num, l[max].sx, l[max].sy);
    return 0;
}


