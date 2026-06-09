#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxint 2147483647
#define eps 1e-10
#define ll long long

int count = 1, max = 0;

struct Line
{
    int x1, y1, x2, y2;
} line[101];

int fuc(int i, int n)
{
    int j;
    for (j = 0; j < n; ++j)
    {
        if (line[i].x2 == line[j].x1 && line[i].y2 == line[j].y1)
        {
            count++;
            return fuc(j, n);
        }
    }
    return count;
}

int main()
{
    int x, y;
    int n, i;
    int tmp;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
    }

    for (i = 0; i < n; ++i)
    {
        tmp = fuc(i, n);
        if (max < tmp)
        {
            max = tmp;
            x = line[i].x1;
            y = line[i].y1;
        }
        count = 1;
    }

    printf("%d %d %d", max, x, y);
    return 0;
}

