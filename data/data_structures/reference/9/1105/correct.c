#include <stdio.h>
#include <stdlib.h>
struct point{
int x1;
int y1;
int x2;
int y2;
int count;
};
int main()
{
    int n,i,j,p,k;
    struct point po[105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        {po[i].count=1;}
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&po[i].x1,&po[i].y1,&po[i].x2,&po[i].y2);
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=0;j<n;j++)
        {
            if(po[k].x2==po[j].x1&&po[k].y2==po[j].y1)
            {
                k=j;
                j=-1;
                po[i].count++;
            }
        }
    }
    p=0;
     for(i=0;i<n;i++)
    {
        if(po[p].count<po[i].count)p=i;
    }
    printf("%d %d %d\n",po[p].count,po[p].x1,po[p].y1);
    return 0;
}

