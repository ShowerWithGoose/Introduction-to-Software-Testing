#include <stdio.h>
struct point
{
    int a[2];
    int b[2];
}point[200],temp;
int main()
{
    int n,i,j,l,pre,max=0,maxx,maxy,flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d%d%d%d",&point[i].a[0],&point[i].a[1],&point[i].b[0],&point[i].b[1]);
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=i+1;j<n;j++)
        {
            if(point[j].a[0]<point[i].a[0])
            {
                temp=point[j];
                point[j]=point[i];
                point[i]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    for(i=0;i<n;i++)
    {
        l=1;
        pre=i;
        for(j=i+1;j<n;j++)
        {
            if(point[j].a[0]==point[pre].b[0]&&point[j].a[1]==point[pre].b[1])
            {
                l++;
                pre=j;
            }
        }
        if(l>max)
        {
            max=l;
            maxx=point[i].a[0];
            maxy=point[i].a[1];
        }
    }
    printf("%d %d %d",max,maxx,maxy);
}

