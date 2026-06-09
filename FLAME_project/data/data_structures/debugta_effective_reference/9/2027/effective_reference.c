#include <stdio.h>

struct lines
{
    int num;
    int x1;
    int y1;
    int x2;
    int y2;
} l[105];

int main()
{
    int n, i, j, x1, y1, x2, y2, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int flag = 1;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (j = 0; j < c; j++)
        {
            if (l[j].x2 == x1 && l[j].y2 == y1)
            {
                l[j].x2 = x2;
                l[j].y2 = y2;
                l[j].num++;
                flag &= 0;
                break;
            }
            else if (l[j].x1 == x2 && l[j].y1 == y2)
            {
                l[j].x1 = x1;
                l[j].y1 = y1;
                l[j].num++;
                flag &= 0;
                break;
            }
        }
        if (flag == 1)
        {
            l[c].num++;
            l[c].x1 = x1;
            l[c].y1 = y1;
            l[c].x2 = x2;
            l[c].y2 = y2;
            c++;
        }
    }
    for (i = 0; i < c; i++)
        for (j = 0; j < c; j++)
        {
            if (i == j)
                continue;
            else if (l[i].x2 == l[j].x1 && l[i].y2 == l[j].y1)
            {
                l[j].x1 = l[i].x1;
                l[j].y1 = l[i].y1;
                l[j].num += l[i].num;
                l[i].num = -1;
                l[i].x1 = -i;
                l[i].y1 = -i;
                l[i].x2 = -i;
                l[i].y2 = -i;
            }
            else if (l[i].x1 == l[j].x2 && l[i].y1 == l[j].y2)
            {
                l[i].x1 = l[j].x1;
                l[i].y1 = l[j].y1;
                l[i].num += l[j].num;
                l[j].num = -1;
                l[j].x1 = -j;
                l[j].y1 = -j;
                l[j].x2 = -j;
                l[j].y2 = -j;
            }
        }
    int max, maxlines = 0;
    for (i = 0; i < c; i++)
        if (l[i].num > maxlines)
        {
            max = i;
            maxlines = l[i].num;
        }
    printf("%d %d %d", l[max].num, l[max].x1, l[max].y1);
    return 0;
}


