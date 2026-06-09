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
                a[i].count += a[j].count; // @@ [This incorrectly adds the entire count of segment j, which may already include multiple segments, leading to overcounting. It should only increment by 1 per connected segment.]
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
                n--; // @@ [Modifying the loop bound 'n' inside nested loops causes unpredictable iteration behavior and may skip segments or access invalid indices.]
                if(j<i)
                i--; // @@ [Decrementing loop variable 'i' inside the loop leads to reprocessing already processed segments and can cause infinite loops or incorrect counts.]
                j = 0; // @@ [Resetting 'j' to 0 inside the inner loop disrupts the iteration logic and may cause repeated processing of the same segments, leading to incorrect merging and counting.]
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