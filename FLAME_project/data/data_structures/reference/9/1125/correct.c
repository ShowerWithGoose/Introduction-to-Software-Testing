#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int x1,x2,y1,y2;
}list;
list a[101];
int cmp(const void *a,const void *b)
{
    struct node *c=(struct node *)a;
    struct node *d=(struct node *)b;
    return c->x2-d->x2;
}
int b[1000][1000];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=n-1;i>=0;i--)
    {
        b[a[i].x1][a[i].x2]++;
        for(j=n-1;j>=0;j--)
        {
            if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
            {
                b[a[j].x1][a[j].x2]+=b[a[i].x1][a[i].x2];
            }
        }
    }
    int max=0,xx,yy;
    for(i=0;i<n;i++)
    {
        if(max<b[a[i].x1][a[i].x2])
        {
            max=b[a[i].x1][a[i].x2];
            xx=a[i].x1,yy=a[i].y1;
        }
    }
    printf("%d %d %d",max,xx,yy);
    return 0;
}
