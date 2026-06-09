#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define true 1
struct xian
{
    int x1;
    int y1;
    int x2;
    int y2;
}a[100];
int main()
{
    int i,j,k=0,n,flag=0,max=0;
    struct xian p={0},max_a={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    for(i=0;i<n;i++)
    {
        p=a[i];
        k=1;
        do
        {
            flag=0;
            for(j=0;j<n;j++)
            {
                if(p.x2==a[j].x1&&p.y2==a[j].y1)
                {
                    p=a[j];
                    k++;
                    flag=1;
                    break;
                }
            }
        }while(flag==1);
        if(k>=max)
        {
            max=k;
            max_a=a[i];
        }
    }
    printf("%d %d %d\n",max,max_a.x1,max_a.y1);
    return 0;
}
