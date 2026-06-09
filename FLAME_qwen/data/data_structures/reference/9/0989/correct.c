#include <stdio.h>
#include <ctype.h>  //字符类型判断
#include <string.h> //字符串处理
#include <stdlib.h> //qsort,rand,bsearch
int main()
{
    struct
    {
        int x1;
        int y1;
        int x2;
        int y2;
    } line[105], oo = {0, 0, 0, 0};
    int n, x, y, xx, yy, max = 0, len = 0, jx, jy;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
    }
    for (int i = 0; i < n; i++)
    {
        if (line[i].x1 < line[i].x2)
        {
            x = line[i].x1;
            y = line[i].y1;
            xx = line[i].x2;
            yy = line[i].y2;
            len = 1;
            for (int j = 0; j < n; j++)
            {
                if (j == i || line[j].x1 == line[j].x2)
                {
                    continue;
                }
                if (x == line[j].x2 && y == line[j].y2)
                {
                    len++;
                    x = line[j].x1;
                    y = line[j].y1;
                    line[j] = oo;
                    j = 0;
                }
                else if (xx == line[j].x1 && yy == line[j].y1)
                {
                    len++;
                    xx = line[j].x2;
                    yy = line[j].y2;
                    line[j] = oo;
                    j = 0;
                }
            }
            if (len > max)
            {
                max = len;
                jx = x;
                jy = y;
            }
        }
        else
        {
            continue;
        }
    }
    printf("%d %d %d", max, jx, jy);
    return 0;
}
// 80 75 125 75
// 60 40 80 55
// 80 55 90 20
// 140 120 195 205
// 10 111 70 165
// 22 35 43 43
// 22 175 80 205
// 43 43 60 40
// 90 20 125 60
// 70 165 140 120
