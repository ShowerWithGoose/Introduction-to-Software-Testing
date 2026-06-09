#include <stdio.h>
struct node {
int x1,x2,y1,y2;
}a[105],temp;
int main()
{
    int n,i,j,b[105]={0},m,k,max,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j].x1>a[j+1].x1)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j].x1==a[i].x2&&a[j].y1==a[i].y2)
            {
                b[i]++;
                k=j;
                m=j+1;
                while(m<n)
                {
                    if(a[m].x1==a[k].x2&&a[m].y1==a[k].y2)
                    {
                        k=m;
                        b[i]++;
                    }
                    m++;
                }
            }
        }
    }
    max=b[0];
    for(i=0;i<n;i++)
    {
        if(max<b[i])
        {
            max=b[i];
            t=i;
        }
    }
    printf("%d %d %d",max+1,a[t].x1,a[t].y1);

    return 0;
}

