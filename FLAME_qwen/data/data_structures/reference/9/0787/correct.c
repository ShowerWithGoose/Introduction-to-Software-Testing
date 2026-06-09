#include <stdio.h>
#include <stdlib.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
}a[100];
int cmp(const void *a,const void *b)
{
    struct line *m=(struct line *)a;
    struct line *n=(struct line *)b;
    return m->x1-n->x1;
}
int main()
{
    int n,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    qsort(a, n, sizeof(struct line), cmp);
    struct line now;
    now=a[0];
    for(int i=0;i<n;i++)
    {
        int x=a[i].x2,y=a[i].y2;
        for(int j=i;j<n;j++)
        {
            if(x==a[j].x1&&y==a[j].y1)
            {
                a[i].count++;
                x=a[j].x2;
                y=a[j].y2;
            }
            else
                continue;
        }
        if(max<a[i].count)
        {
            max=a[i].count;
            now=a[i];
        }
        for(int k=i;k<n;k++)
            a[k].count=0;
            
    }
    printf("%d %d %d\n",now.count+1,now.x1,now.y1);
}


