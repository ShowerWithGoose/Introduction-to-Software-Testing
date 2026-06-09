#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct location{   //线段结构体
 int a1;
 int b1;
 int a2;
 int b2;
 int number;       //线段的长度
};
typedef struct location Loc;
Loc l[2000];
int cmp(const void*p1,const void*p2);
int cmp2(const void*p1,const void*p2);
int main()
{
 int n,a,b,c,d;
 int i,j,k=0,flag=0;
 scanf("%d",&n);
 for(i=0;i<n;i++) l[i].number=1;  //初始化，线段的长度都为1
 for(i=0;i<n;i++)
 {
  scanf("%d %d %d %d",&l[i].a1,&l[i].b1,&l[i].a2,&l[i].b2);
 }
 qsort(l,n,sizeof(Loc),cmp2);//结构体二级排序（先排横坐标，如果横坐标相同，排纵坐标）
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if(j==i)
   {
    continue; //同一点，跳过
   }
   else
   {
    if(l[j].a1 == l[i].a2 && l[j].b1 == l[i].b2) //如果可以相连
    {
     l[i].a2 = l[j].a2;  //合并
     l[i].b2 = l[j].b2;     //合并
     l[i].number+= l[j].number;  //线段条数增加
     l[j].a1=0,l[j].b1=0,l[j].a2=0,l[j].b2=0,l[j].number=0;//合并的线段清零
    }
   }
   
  }
 }
 qsort(l,n,sizeof(Loc),cmp);//根据长度排序
 printf("%d %d %d\n",l[n-1].number,l[n-1].a1,l[n-1].b1);
 return 0;
}
int cmp(const void*p1,const void*p2)
{
 struct location *a=(struct location*)p1;
 struct location *b=(struct location*)p2;
 return a->number-b->number;
}
int cmp2(const void*p1,const void*p2)
{
 struct location *a=(struct location*)p1;
 struct location *b=(struct location*)p2;
 if(a->a1 != b->a1) return a->a1-b->a1;
 else return a->b1-b->b2;
}
;/*
  【问题描述】
  平面上两个点（一个点由(x,y)坐标组成）可构成一个线段，两个线段如果有一个端点相同，则可构成一个连续线段。假设构成线段的两个端点为v1(x1,y1)和v2(x2,y2)，在此满足x1<x2，其中v1称为线段的起点，v2为线段的终点。同样，对于连续线段来说，在此满足xi<xi+1（i=1...n-1，n为连续线段中的端点数，xi为相应端点的X轴坐标）。输入一组线段（用两个端点的x、y坐标表示线段，线段个数大于等于2，小于等于100），编程计算出连续线段中包含最多线段数的线段，输出相应的线段数和起点位置（注意，不是最长的连续线段，是包含最多线段的连续线段）。
  注意：
  1）不考虑线段中间相交的情况；
  2）不会有三条或三条以上的线段共一个端点；
  3）只会出现一条包含最多线段的连续线段；

  【输入形式】
  先从控制台输入线段数，然后从下一行开始分行输入各线段两个端点的x、y坐标，其中第一个端点的X轴坐标小于第二个端点的X轴坐标，即x1<x2，x、y坐标都用整数表示，不会超过int的表示范围。各整数坐标值间以一个空格分隔。
  【输出形式】
  先在控制台输出包含最多线段数的连续线段的线段数，然后输出连续线段的起点的x、y坐标，输出数据都以一个空格分隔。  */

