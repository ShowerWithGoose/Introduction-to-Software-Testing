#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct xian4duan4
{
    int for_x;
    int for_y;
    int lat_x;
    int lat_y;
    struct xian4duan4 *next;
}*line;
line head[150],tail[150];
int num[150],ptr,max=1;//num[150]用来储存每个线条有多少线段,max用来存储目前线条的最长的长度，ptr用来存储第几条线段最长
int main()
{
    line p;
    int n,index=0,head_x,head_y,tail_x,tail_y;//index用来存储总共有多少条线段
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&head_x,&head_y,&tail_x,&tail_y);
        p=(line)malloc(sizeof(struct xian4duan4));
        p->for_x=head_x;
        p->for_y=head_y;
        p->lat_x=tail_x;
        p->lat_y=tail_y;
        p->next=NULL;
        head[index]=p;
        tail[index]=p;
        num[index]++;
        index++;
        /*for(int j=0;j<index;j++)//讨论不需要开新的线的情况
        {
            if((head[j]->for_x==tail_x)&&(head[j]->for_y==tail_y))//将新读入数据插在前面
            {
                p->next=head[j];
                head[j]=p;
                flag++;
                num[j]++;
                break;
            }
            else if((tail[j]->lat_x==head_x)&&(tail[j]->lat_y==head_y))//将新读入数据插在后面
            {
                tail[j]->next=p;
                tail[j]=p;
                flag++;
                num[j]++;
                break;
            }
        }
        if(flag==0)
        {
        head[index]=p;
        tail[index]=p;
        num[index]++;
        index++;
        }
        flag=0;
    */
   }
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<index;j++)
        {
            if((i!=j)&&(num[j]!=0)&&(num[i]!=0))
            {
                if((tail[j]->lat_x==head[i]->for_x)&&(tail[j]->lat_y==head[i]->for_y))
                {
                tail[j]->next=head[i];
                num[i]+=num[j];
                num[j]=0;
                head[i]=head[j];
                i=0;
                j=0;
                }//把线段j接到线段i的前面
                else if((tail[i]->lat_x==head[j]->lat_x)&&(tail[i]->lat_y==head[j]->for_y))
                {
                tail[i]->next=head[j];
                num[i]+=num[j];
                num[j]=0;
                tail[i]=tail[j];
                i=0;
                j=0;   
                }//把线段j接到线段i后面
            }
        }
    }
    for(int i=0;i<index;i++)
    {
        if(max<num[i])
        {
            max=num[i];
            ptr=i;
        }
    }
    printf("%d %d %d",max,head[ptr]->for_x,head[ptr]->for_y);
    return 0;
}
