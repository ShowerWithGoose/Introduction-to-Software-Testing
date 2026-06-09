#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct st{
    int x1;
    int x2;
    int y1;
    int y2;
}line[102];

int cmp(const void*s1,const void*s2)
{
    struct st*a=(struct st*)s1;
    struct st*b=(struct st*)s2;
    return a->x1-b->x1;
}
int main()
{
   int n,cnt[102]={0},max_num=0,max_l;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
   }
   qsort(line,n,sizeof(line[0]),cmp);
   for(int i=0;i<n-1;i++)
   {
      cnt[i]=1;
      int r=line[i].x2;
      int t=line[i].y2;
      int j=i+1;
      while(j<n)
      {
        if(line[j].x1==r&&line[j].y1==t)
        {
          cnt[i]++;
          r=line[j].x2;
          t=line[j].y2;
        }
        j++;
      }
      if(cnt[i]>=max_num)
      {
          max_num=cnt[i];
          max_l=i;
      }
   }
   printf("%d %d %d\n",max_num,line[max_l].x1,line[max_l].y1);
   return 0;
}
