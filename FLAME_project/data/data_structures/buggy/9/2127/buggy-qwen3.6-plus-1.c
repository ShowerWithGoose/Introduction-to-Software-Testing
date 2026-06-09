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
            if(x[j].x1==a2&&x[j].y1==b2) // @@ The condition checks if the new segment's end (a2, b2) matches an existing segment's start. However, the problem states segments are defined with x1 < x2. If we are building a chain, we should check if the new segment connects to the END of an existing chain (x2, y2) or the START of an existing chain (x1, y1). More critically, this logic attempts to merge segments greedily as they are read. The condition `x[j].x1==a2` implies the new segment is BEFORE the existing one. The update `x[j].x1 = a1` correctly extends the start.
            {
                x[j].x1 = a1;
                x[j].y1 = b1;
                x[j].count += 1;
                break;
            }
            else if(x[j].x2==a1&&x[j].y2==b1) // @@ This condition checks if the new segment's start (a1, b1) matches an existing segment's end. This implies the new segment is AFTER the existing one. The update `x[j].x2 = a2` correctly extends the end.
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
            if(x[j].flag==1&&x[k].x1==x[j].x2&&x[j].y1==x[j].y2) // @@ Logical Error 1: The condition `x[j].y1==x[j].y2` checks if segment j is horizontal, which is irrelevant for connectivity. It should check if the y-coordinate of the connection point matches, i.e., `x[k].y1 == x[j].y2`. Logical Error 2: The merge direction is wrong. If `x[k].x1 == x[j].x2`, segment k starts where segment j ends. So k should be appended to j. The code updates k's start to j's start (`x[k].x1 = x[j].x1`), effectively merging j into k's left side. However, it adds `x[j].count` to `x[k].count`. This part is conceptually okay for merging j into k, but the y-coordinate check is wrong. Also, since we iterate k then j, we might miss merges or double count if not careful with flags. The primary bug here is the y-coordinate comparison `x[j].y1==x[j].y2` instead of `x[k].y1==x[j].y2`.
            {
                x[k].x1 = x[j].x1;
                x[k].y1 = x[j].y1;
                x[k].count += x[j].count;
                x[j].flag = 0;
            }
            else if(x[j].flag==1&&x[k].x2==x[j].x1&&x[k].y2==x[j].y1) // @@ Similar logical error potential. Here it checks if k's end matches j's start. The y-check `x[k].y2==x[j].y1` is correct for connectivity. It merges j into k's right side. This logic is flawed because the first pass already merged some segments. The second pass is intended to merge remaining disjoint chains that were formed in the first pass but not connected because one part wasn't read yet? No, the first pass processes segments sequentially. If segment A connects to B, and B connects to C, but C is read before A is fully merged with B? No, the first loop processes input one by one. If the input order is such that connections are not immediate neighbors in the input array, the first loop fails to connect them. For example, if we have segments S1, S2, S3. Input: S1, S3, S2. S1 is stored. S3 is stored. S2 comes: it connects to S1 (end of S1 == start of S2). So S1 becomes S1-S2. S3 is separate. Now we have [S1-S2] and [S3]. If S3 connected to S2, it would have been caught when S3 was read IF S2 was already there. But S2 wasn't. So S3 is separate. Then S2 is read. It connects to S1. S3 is never connected to S1-S2 because S3 was processed before S2 existed. Thus, the second pass is needed to connect these "gaps". However, the condition in the first `if` of the second pass is definitely wrong due to `x[j].y1==x[j].y2`.
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