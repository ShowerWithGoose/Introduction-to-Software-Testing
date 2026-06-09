#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct dot
{
    int x1;
    int y1;
    int x2;
    int y2;
    int n;
} line[200], line1[200], max, tmp;

void sort(struct dot line[], int n)
{
    int m = n - 1;
    int r = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < m; j++)
        {
            if (line[j].x1 > line[j + 1].x1)
            {
                flag = 0;
                tmp = line[j + 1];
                line[j + 1] = line[j];
                line[j] = tmp;
                r = j;
            }
        }
        m = r;
        if (flag)
            break;
    }
}

signed main()
{
    int num = 0, i = 0, j = 0, k = 0;
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d %d %d %d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
        line[i].n = 1;
    }
    sort(line, i);
    for (i = 0; i < num; i++)
    {
        line1[k] = line[i];
        for (j = 0; j < k; j++)
        {
            if (line1[j].x2 == line1[k].x1 && line1[j].y2 == line1[k].y1)
            {
                line1[j].x2 = line1[k].x2;
                line1[j].y2 = line1[k].y2;
                line1[j].n++;
                k--;
            }
        }
        k++;
    }
    max = line1[0];
    for (i = 0; i < k; i++)
    {
        if (line1[i].n >= max.n)
        {
            max = line1[i];
        }
    }
    printf("%d %d %d", max.n, max.x1, max.y1);
}


