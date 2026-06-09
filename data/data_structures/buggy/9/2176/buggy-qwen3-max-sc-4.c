#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
}line;
line a[20];

int main()
{
    int n,i,j,k;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&a[i-1].x1,&a[i-1].y1,&a[i-1].x2,&a[i-1].y2);
        a[i-1].count = 1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            continue;
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].count += a[j].count; // @@ [Incorrectly accumulates count from a[j], which may already include multiple segments, leading to overcounting]
                a[i].x2 = a[j].x2;
                a[i].y2 = a[j].y2;
                for(k=j;k<n-1;k++)
                {
                    a[k].x1 = a[k+1].x1;
                    a[k].x2 = a[k+1].x2;
                    a[k].y1 = a[k+1].y1;
                    a[k].y2 = a[k+1].y2;
                    a[k].count = a[k+1].count;
                }
                n--; // @@ [Modifying loop bound 'n' inside nested loops causes unpredictable iteration behavior and skips segments]
                if(j<i)
                i--; // @@ [Adjusting outer loop index 'i' inside inner loop leads to undefined or incorrect traversal]
                j = 0; // @@ [Resetting inner loop index 'j' to 0 after removal causes reprocessing of already processed segments and potential infinite loops]
            }
        }
    }
    int max=0,x=a[0].x1,y=a[0].y1;
    for(i=0;i<n;i++)
    {
        if(a[i].count>max)
        {
            max = a[i].count;
            x = a[i].x1;
            y = a[i].y1;
        }
    }
    printf("%d %d %d\n",max,x,y);
    return 0;
}