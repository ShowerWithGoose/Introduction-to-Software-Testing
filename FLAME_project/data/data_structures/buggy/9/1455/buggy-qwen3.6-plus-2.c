#include<stdio.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    double k;
};
int b[110]={0};
int i,n;
int num=1;
int max=1;
int x,y;
void f(struct line a[],int b[],int p)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(b[j]==0)
        {
            if(a[p].x2==a[j].x1&&a[p].y2==a[j].y1)
            {
                if(a[p].k!=a[j].k) // @@ The condition checking if slopes are different is incorrect. The problem asks for the number of segments in a continuous line, regardless of whether the slope changes. Two segments form a continuous line if they share an endpoint. The slope check incorrectly prevents counting segments that are collinear or have the same slope as part of the chain if the logic was intended to count "straight" lines, but here we just need connectivity. More importantly, even if slopes are equal, they should be counted. The constraint "No two line segments intersect in the middle" and the definition of continuous line segment implies simple connectivity by endpoints. Removing this condition allows all connected segments to be counted.
                {
                    num++;
                }
                b[j]=1;
                f(a,b,j);
                b[j]=0;
            }
        }
    }
    if(num>max)
    {
        max=num;
        x=a[i].x1;
        y=a[i].y1;
    }
}
int main()
{
    scanf("%d",&n);
    struct line a[110];
    for(i=0;i<n;i++)
    {    
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        double x1=a[i].x1;
        double x2=a[i].x2;
        double y1=a[i].y1;
        double y2=a[i].y2;
        a[i].k=(y2-y1)/(x2-x1);
    }
    for(i=0;i<n;i++)
    {
        b[i]=1;
        f(a,b,i);
        b[i]=0;
        num=1;
    }
    printf("%d %d %d",max,x,y);
    return 0; 
}