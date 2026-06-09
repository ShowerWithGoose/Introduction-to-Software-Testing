/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
    int flag;
}Node;
int main()
{
    int i = 0,j,k,a1,b1,a2,b2,n1;
    Node x[105];
    scanf("%d",&n1);
    scanf("%d%d%d%d",&x[i].x1,&x[i].y1,&x[i].x2,&x[i].y2);
    x[i].count = 1;
    x[i].flag = 1;
    i++;
    for(k = 1;k<n1;k++)
    {
        scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
        for(j = 0;j<i;j++)
        {
            if(x[j].x1==a2&&x[j].y1==b2) // @@ The condition checks if the new segment's end (a2,b2) matches an existing segment's start (x1,y1). This implies merging backwards, but the assignment x[j].x1 = a1 updates the start to the new segment's start. This logic is flawed because it assumes the new segment is always "before" the existing one in terms of connection, but doesn't handle the case where the new segment connects to the end correctly or vice-versa in a unified way. More critically, it fails to check if the new segment connects to the END of an existing segment (x2,y2) properly in this first pass if the orientation is reversed. However, the bigger issue is below.
            {
                x[j].x1 = a1;
                x[j].y1 = b1;
                x[j].count += 1;
                break;
            }
            else if(x[j].x2==a1&&x[j].y2==b1)
            {
                x[j].x2 = a2;
                x[j].y2 = b2;
                x[j].count += 1;
                break;
            }
        }
        if(j == i)
        {
            x[j].x1 = a1;
            x[j].y1 = b1;
            x[j].x2 = a2;
            x[j].y2 = b2;
            x[j].count = 1;
            x[j].flag = 1;
            i++;
        }

    }
    for(k = 0;k<i;k++)
    {
        for(j = 0;j<i;j++)
        {
            if(x[j].flag==1&&x[k].x1==x[j].x2&&x[j].y1==x[j].y2) // @@ Logical Error: The condition `x[j].y1==x[j].y2` checks if segment j is horizontal? No, it checks if y1 equals y2 of the SAME segment j. It should be comparing coordinates of k and j. Specifically, it should check if k's start (x1,y1) matches j's end (x2,y2). The condition `x[k].x1==x[j].x2` is correct for x, but `x[j].y1==x[j].y2` is completely wrong. It should be `x[k].y1==x[j].y2`. This prevents valid merges from being detected.
            {
                x[k].x1 = x[j].x1;
                x[k].y1 = x[j].y1;
                x[k].count += x[j].count;
                x[j].flag = 0;
            }
            else if(x[j].flag==1&&x[k].x2==x[j].x1&&x[k].y2==x[j].y1)
            {
                x[k].x2 = x[j].x2;
                x[k].y2 = x[j].y2;
                x[k].count += x[j].count;
                x[j].flag = 0;
            }
        }
    }
    int max=0,num=0; 
    for(j = 0;j<i;j++)
    {
        if(x[j].flag==1&&x[j].count>max)
        {
            num = j;
            max = x[j].count;
        }
    }
    printf("%d %d %d",max,x[num].x1,x[num].y1);
    return 0;
 }