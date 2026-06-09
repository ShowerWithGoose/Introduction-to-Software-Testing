#include<stdio.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct line *next;
};
int f(struct line);
int main()
{
    struct line a[100]={{0,0,0,0,NULL}};
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].next=&a[j];
                break;
            }
        }
    }
    struct line max1=a[0];
    int max=f(a[0]);
    for(int i=0;i<n;i++)
    {
        if(max<f(a[i]))
        {
            max=f(a[i]);
            max1=a[i];
        }
    }
    printf("%d %d %d",max,max1.x1,max1.y1);
    return 0;
}
int f(struct line a)
{
    struct line *b=&a;
    int n=0;
    while(b->next!=NULL)
    {
        b=b->next;
        n++;
    }
    return n+1;
}
