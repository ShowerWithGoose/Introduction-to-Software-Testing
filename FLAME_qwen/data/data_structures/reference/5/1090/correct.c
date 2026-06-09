//难点：读入；合并同类项
#include<stdio.h>
/*不要这么写，不然qsort排序不好排
排序的话，一下就变一行
struct expresstion{
  int a[10000];
  int x[10000];
};要是这样该怎么写呢？？
*/
struct expresstion{
  int a;
  int x;
};
struct expresstion ex1[1000],ex2[1000],ans[1000];
int cmp(const void *p,const void *q);
int main()
{
  char ch;
  int i=0,j=0,t=0;
  int n1,n2,count;//count记录合并同类项时，消去了几个
  while(1)
  {
    scanf("%d%d%c",&ex1[i].a,&ex1[i].x,&ch);
    i++;
    if(ch=='\n')
    break;
  }
  n1=i;//共有n1项，不过存在0~n1-1中

  i=0;
  while(1)
  {
    scanf("%d%d%c",&ex2[i].a,&ex2[i].x,&ch);
    i++;
    if(ch=='\n')
    break;
  }
  n2=i;

  qsort(ex1,n1,sizeof(struct expresstion),cmp);
  qsort(ex2,n2,sizeof(struct expresstion),cmp);

  t=0;
  for(i=0;i<n1;i++)
  {
    for(j=0;j<n2;j++)
    {
        ans[t].x=ex1[i].x+ex2[j].x; //指数相加
        ans[t].a=ex1[i].a*ex2[j].a; //系数相乘
        t++;
    }
  }
  qsort(ans,n1*n2,sizeof(struct expresstion),cmp);//此时t=n1*n2
  //  for(i=0;i<t+5;i++)
  // {
  //   if(ans[i].a!=0)
  //   printf("%d %d ",ans[i].a,ans[i].x);
  // }
  // printf("\n%d\n********\n",t);

  count=n1*n2;
  for(i=0;i<t-1;i++)//共有t个，在下标为0～t-1中
  {
    if(ans[i].x==ans[i+1].x)//不然可能会有指数为0，与未赋值处相等的情况
    {
      ans[t].x=ans[i].x;
      for(j=i;ans[j].x==ans[j+1].x;j++);
      //共有j-i+1个相同次数的项
      count=count-(j-i+1)+1;
      for(;i<=j;i++)//i变了
      {
        ans[t].a=ans[t].a+ans[i].a;
        ans[i].a=0;
      }
      i--;
      t++;
    }
  }
  //printf("\n%d\n********\n",t);
  qsort(ans,t,sizeof(struct expresstion),cmp);
  //printf("\n%d\n********\n",t);
  for(i=0;i<t;i++)
  {
    if(ans[i].a!=0)
    printf("%d %d ",ans[i].a,ans[i].x);
  }
  return 0;
}
int cmp(const void *p1,const void *p2)//从大到小，按降序排
{
  struct expresstion *p=(struct expresstion *)p1;
  struct expresstion *q=(struct expresstion *)p2;
  if(p->x>=q->x)
  return -1;
  else
  return 1;
}

/*
30 86000 50 80020 80 80010 60 80000 6 12000 21 6300 10 6020 
31 6010 66 6000 35 320 56 310 
42 300 25 30 130 20 174 10 108 0

注意
1*2
（2x+3）*1

*/

