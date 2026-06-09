#include<stdio.h>
struct line{
  int bx;
  int by;
  int ex;
  int ey;
};
struct line l[120];
int cmp(const void *p,const void *q);
int main()
{
  int i,j,t;
  int n,count=0,max=0;//n是总的线段数,count记录一段连续的线段能有几个小线段
  int fx=0,fy=0;//记录最后要输出的起点x,y
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d%d",&l[i].bx,&l[i].by);
    scanf("%d%d",&l[i].ex,&l[i].ey);
  }
  qsort(l,n,sizeof(struct line),cmp);

  for(i=0;i<n;i++)
  {
    count=1;
    for(j=i,t=i;j<n&&t<n;t++)
    {
      if(l[j].ex==l[t+1].bx&&l[j].ey==l[t+1].by)//第一个没找到就变成了以j开始找了
      {
        count++;
        j=t+1;
      }
    }
      if(count>max)
      {
        max=count;
        fx=l[i].bx;
        fy=l[i].by;
      }
    
  }

  printf("%d %d %d",max,fx,fy);

  return 0;
}
int cmp(const void *p,const void *q) //按照线段起点升序排
{
  struct line *a=(struct line *)p;
  struct line *b=(struct line *)q;
  if(a->bx<=b->bx)
  return -1;
  else
  return 1;
}

