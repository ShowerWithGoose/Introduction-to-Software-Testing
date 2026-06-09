#include<stdio.h>
#include<stdlib.h>
typedef struct segment
{
    int x1,y1,x2,y2,count;
}segment;
int main()
{
    int n,total=1,max=1,x=0,y=0;
    segment all[128];
    scanf("%d",&n);
    for(total=0;total<n;total++)
    {
        scanf("%d%d%d%d",&all[total].x1,&all[total].y1,&all[total].x2,&all[total].y2);
        all[total].count=1;
    }//Now total==n
    for(int i=0;i<total;i++)
        for(int j=0;j<total;j++)
        {
            if(i==j) continue;
            if(all[i].x2==all[j].x1&&all[i].y2==all[j].y1)
            {
                all[i].x2=all[j].x2;
                all[i].y2=all[j].y2;
                all[i].count+=all[j].count;
                all[j].count=0;
            }
            if(all[i].x1==all[j].x2&&all[i].y1==all[j].y2)
            {
                all[i].x1=all[j].x1;
                all[i].y1=all[j].y1;
                all[i].count+=all[j].count;
                all[j].count=0;
            }
        }
    for(int i=0;i<total;i++)
        if(all[i].count>=max)
        {
            max=all[i].count;
            x=all[i].x1;
            y=all[i].y1;
        }
    printf("%d %d %d",max,x,y);
    return 0;
}
