#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
struct Line {
    int x1;
    int y1;
    int x2;
    int y2;
}line[100];
int cmp(const void *a,const void *b)
{
    struct Line*m=(struct Line*)a;
    struct Line*n=(struct Line*)b;
    return m->x1-n->x1;
}
int main()
{
  struct Line line[110];
  int i=0,n,j,x=0,y=0,num=1,max=0,xm,ym,x0,y0;
  scanf("%d",&n);
  while(i<n)
  {
      scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
      i++;
  }
  qsort(line,n,sizeof(struct Line),cmp);
  for(i=0;i<n;i++)
  {
    num=1;xm=line[i].x2;ym=line[i].y2;
    for(j=i+1;j<n;j++)
    {
      if(xm==line[j].x1&&ym==line[j].y1)
      {
        xm=line[j].x2;ym=line[j].y2;
        num++;
      }
    }
    if(num>max)
    {
      max=num;
      x=line[i].x1;
      y=line[i].y1;
    }
  }
  printf("%d %d %d",max,x,y);
return 0;
}
