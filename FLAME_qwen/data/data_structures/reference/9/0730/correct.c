#include <stdio.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct line *p;
}
a[105],*q;
int n,i,j,ans,x,y;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        a[i].p=NULL;
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if((i!=j)&&(a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1))
    {
        a[i].p=&a[j];
        break;
    }
    for(i=0;i<n;i++)
    {
        j=1;
        q=&a[i];
        while(q->p!=NULL)
        {
            j++;
            q=q->p;
        }
        if(ans<j)
        {
            ans=j;
            x=a[i].x1;
            y=a[i].y1;
        }
    }
    printf("%d %d %d",ans,x,y);
    return 0;
}

