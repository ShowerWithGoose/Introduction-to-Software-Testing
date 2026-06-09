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
                if(a[p].k!=a[j].k)  // @@ [This condition is incorrect: continuous segments must be connected end-to-start, but they do not need to have different slopes. In fact, the problem does not require checking slope at all. This check prevents valid chains from being counted.]
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
        x=a[i].x1;  // @@ [Incorrect indexing: 'i' is the loop variable from main and is not updated during recursion. It should be the starting index of the current chain, which is lost in recursive calls. Should use the original starting segment's coordinates, not 'a[i]'.]
        y=a[i].y1;  // @@ [Same issue as above: using global 'i' instead of tracking the start of the current path.]
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
        a[i].k=(y2-y1)/(x2-x1);  // @@ [Potential division by zero is avoided by problem constraints (x1 < x2), so this is safe, but storing slope as double may cause precision issues when comparing with '!='. However, the bigger issue is that slope comparison is unnecessary per problem statement.]
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