#include<stdio.h>
#include<stdlib.h>
struct line 
{
    int x1;
    int x2;
    int y1;
    int y2;
}book[102];//结构体控制每组线段参数
int n;//输入组数
int sign[102]={0};//连接成功数；
int tailx=0,taily=0;
int headx=0,heady=0;
void attach();
int s=1;
int main()
{
    int i,j,k;
    scanf("%d",&n);//读入组数
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&book[i].x1,&book[i].y1,&book[i].x2,&book[i].y2);
    }
    attach();
    return 0;
}
void attach()
{
    int i,j;
    tailx=book[0].x2;
    taily=book[0].y2;
    headx=book[0].x1;
    heady=book[0].y1;
    for (i=0;i<n;i++)
    {
      for (j=0;j<n;j++)
      {
          if(i==j)
          continue;
        else 
        {
                if(tailx==book[j].x1&&taily==book[j].y1)
            {
                sign[i]++;//次数加一
                tailx=book[j].x2;taily=book[j].y2;//将尾数据传给tail
                s++;
            }
                else if(headx==book[j].x2&&heady==book[j].y2)
                {
                    sign[i]++;
                    headx=book[j].x1;heady=book[j].y1;//将首数据传给head
                    s++;
                }
        }
      }
      if (s==1)
            {
                tailx=book[i+1].x2;taily=book[i+1].y2;
				headx=book[i+1].x1;heady=book[i+1].y1;//没有匹配，将尾数据传到下一位
            }
    }
    //for(i=0;i<n;i++)
    //s+=sign[i];
    printf("%d %d %d\n",s,headx,heady);
}

