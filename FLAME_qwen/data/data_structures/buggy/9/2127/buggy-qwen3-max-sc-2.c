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
            if(x[j].x1==a2&&x[j].y1==b2)
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
            if(x[j].flag==1&&x[k].x1==x[j].x2&&x[k].y1==x[j].y2) // @@ [Incorrect condition: used x[j].y1 instead of x[k].y1 in the second part of the endpoint match check]
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