#include<stdio.h>
struct line
{
    int x1;
    int x2;
    int y1;
    int y2;
    struct line *next;
};
int f(struct line);
int main()
{
    struct line a[100]={{0,0,0,0,NULL}};
    int n=0;
    while(scanf("%d%d%d%d",&a[n++].x1,&a[n++].x2,&a[n++].y1,&a[n++].y2)!=EOF); // @@ [Incorrect input reading: ignores first line (number of segments) and increments n four times per segment, causing index mismatch and out-of-bounds access.]
    struct line *b[100];
    for(int i=0;i<n;i++) // @@ [Loop bound n is incorrect because n was incremented four times per segment, leading to out-of-bounds array access.]
    {
        b[i]=&a[i];
        for(int j=0;j<n;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1) // @@ [Missing reverse condition: should also check if a[i].x1 equals a[j].x2 and a[i].y1 equals a[j].y2 to link segments in both directions.]
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