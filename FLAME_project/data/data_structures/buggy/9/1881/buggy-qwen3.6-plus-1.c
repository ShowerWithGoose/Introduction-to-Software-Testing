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
        flag = 0; // @@ The variable 'flag' is initialized to 0 but never updated to 1 inside the inner loop when a swap occurs. This causes the outer sorting loop to break after the first iteration regardless of whether swaps happened, resulting in an incomplete sort.
        for(j=i+1;j<n;j++)
        {
            if (point[i].a[0] > point[j].a[0])
            {
                temp = point[j];
                point[j] = point[i];
                point[i] = temp;
                flag = 1; // @@ Missing update to 'flag'. Without setting flag=1 here, the sorting algorithm terminates prematurely.
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