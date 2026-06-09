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
                if(a[p].k!=a[j].k)  // @@ [This condition is incorrect: continuous segments should connect regardless of slope; the problem does not require same slope, only shared endpoints. Also, comparing floating-point values with != can be unreliable.]
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
        x=a[i].x1;  // @@ [Should use a[p].x1 or the starting point of the current chain, not a[i].x1 which refers to the outer loop variable i that may have changed. This leads to incorrect starting point.]
        y=a[i].y1;  // @@ [Same issue as above: uses outer loop index i instead of the actual start of the current path.]
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
        a[i].k=(y2-y1)/(x2-x1);  // @@ [Potential division by zero if x2 == x1, but problem states x1 < x2 so safe. However, storing slope as double and comparing with != is error-prone due to floating-point precision.]
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