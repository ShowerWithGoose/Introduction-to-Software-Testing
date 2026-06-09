#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
struct pos {
    int a[2];
    int b[2];
}temp;
int main()
{
    struct pos point[100];
    int n,flag;
    scanf("%d", &n);
    int i,j,pre,l,max=-1,maxx,maxy;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &point[i].a[0], &point[i].a[1], &point[i].b[0], &point[i].b[1]);
    }
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for(j=i+1;j<n;j++)
        {
            if (point[i].a[0] > point[j].a[0]) // @@ [flag should be set to 1 here to indicate a swap occurred, otherwise the outer loop breaks prematurely leaving the array unsorted]
            {
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
            }
        }
        if (flag == 0)
            break;
    }
    for (i = 0; i < n; i++)
    {
        l = 1;
        pre = i;
        for (j =i+1; j < n; j++)
        {
            if (point[j].a[0] == point[pre].b[0] && point[j].a[1] == point[pre].b[1])
            {
                pre = j;
                l++;
            }
        }
        if (l > max)
        {
            max = l;
            maxx = point[i].a[0];
            maxy = point[i].a[1];
        }
    }
    printf("%d %d %d", max, maxx, maxy);
}