#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} line;

int bcheck(line a[], int x, int y,int n)
{
    int sm = 0, bg = n-1, mid;
    mid == sm + bg / 2;
    while (sm <= bg)
    {
        mid = (sm + bg) / 2;
        if (x > a[mid].x1)
            sm = mid + 1;
        else if (x < a[mid].x1)
            bg = mid - 1;
        else if (x == a[mid].x1 )
        {
            if(y==a[mid].y1)return (mid);
            else if(x == a[mid-1].x1&&y==a[mid-1].y1)return (mid-1);
            else if(x == a[mid+1].x1&&y==a[mid+1].y1)return (mid+1);
            else return -1;
        }
    }
    return -1;
}

int sort(line a[], int n)
{
    line tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j].x1 > a[j + 1].x1)
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    line a[105];
    int n, flag[105], ans[105], max=0,answer ;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    }
    sort(a, n);
    for (int i = 0; i < n; i++)
    {
        flag[i] = bcheck(a, a[i].x2, a[i].y2,n);
    }
    for (int i = 0; i < n; i++)
    {
        int k = 1, j = i;
        while (flag[j] != -1)
        {
            j = flag[j];
            k++;
        }
        ans[i] = k;
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] > max)
        {
            answer = i;
            max=ans[i];
        }
    }
    printf("%d %d %d", max, a[answer].x1, a[answer].y1);
    return 0;
}

