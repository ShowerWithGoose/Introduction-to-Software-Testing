#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int n;
typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
} LINE;
int main()
{
    LINE a[100],b[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        a[i].count=1;
    }
    for (int i = 0;i<n;i++)
    {
        b[i]=a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else if((a[i].x2==b[j].x1)&&(a[i].y2==b[j].y1))
            {
                a[i].x2=b[j].x2;
                a[i].y2=b[j].y2;
                a[i].count++;
                j=-1;
            }
        }
    } 
    for (int i=1;i<n;i++)
    {
        if(a[i].count>a[0].count)
        {
            a[0]=a[i];
        }
    }
    printf("%d %d %d",a[0].count,a[0].x1,a[0].y1);
    return 0;
}
