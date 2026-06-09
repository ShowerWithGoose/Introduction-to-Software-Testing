#include <stdio.h>
struct xd{
    int x1;
    int y1;
    int x2;
    int y2;
    int l;
};
int isinline(int j,int t,struct xd line[])
{
    int i;
    for(i=0;i<j;i++)
    {
        if(line[t].x1==line[i].x2&&line[t].y1==line[i].y2)
        {
            line[t].x1=line[i].x1;
            line[t].y1=line[i].y1;
            return 1;
        }
        if(line[t].x2==line[i].x1&&line[t].y2==line[i].y1)
        {
            line[t].x2=line[i].x2;
            line[t].y2=line[i].y2;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n,m=0,x=0;
    scanf("%d",&n);
    struct xd line[100]={};
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    for(i=0;i<n;i++)
    {
        while(isinline(n,i,line))
        {
            line[i].l++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(m<line[i].l+1)
        {
            m=line[i].l+1;
            x=i;
        }
    }
    printf("%d %d %d",m,line[x].x1,line[x].y1);
    return 0;
}
