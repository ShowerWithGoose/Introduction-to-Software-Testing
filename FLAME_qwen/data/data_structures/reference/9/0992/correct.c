#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
typedef struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
} line;

void sort(line a[], int n)
{
    int i, j;
    line temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j].x1 > a[j + 1].x1)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    //freopen("data.in", "r", stdin);
    int n, cnt = 0, max = 0, x, y,x0,y0;
    scanf("%d", &n);
    line a[105];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    }
    sort(a, n);
    for (int i = 0; i < n - 1; i++)
    {
        x = a[i].x2;
        y = a[i].y2;
        cnt = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (x == a[j].x1 && y == a[j].y1)
            {
                cnt++;
                x = a[j].x2;
                y = a[j].y2;
            }
        }
        if (cnt >= max)
        {
            x0=a[i].x1;
            y0=a[i].y1;
            max = cnt;
        }
    }
    printf("%d %d %d",max,x0,y0);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n",a[i].x1);
    // }
    return 0;
}
