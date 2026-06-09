#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct points
{
  int x;
  int y;
}point;

typedef struct lines
{
  point p1;
  point p2;
  
}line;

line L[105];
int n;

point continuePoint[105][205];
int continueCount=0;
int pointP2Count[105];

int cmp(const void *a,const void *b)
{
  if((*(line*)a).p1.x>(*(line*)b).p1.x)
  {
    return 1;
  }
  else if((*(line*)a).p1.x<(*(line*)b).p1.x)
  {
    return -1;
  }
  else 
  {
    return 0;
  }
}
int searchCP(line l)
{
  for(int i=0;i<continueCount;i++)
  {
    if(l.p1.x==continuePoint[i][pointP2Count[i]-1].x&&l.p1.y==continuePoint[i][pointP2Count[i]-1].y)
    {
      return i;
    }
    
  }
  return -1;
}
int MaxCP(void)
{
  int ret=0;
  for(int i=0;i<continueCount;i++)
  {
    if(pointP2Count[i]>ret)
    {
      ret=pointP2Count[i];
    }
  }
  return ret;
}
int MaxCPIndex(void)
{
  int max=0;
  int ret=0;
  for(int i=0;i<continueCount;i++)
  {
    if(pointP2Count[i]>max)
    {
      max=pointP2Count[i];
      ret=i;
    }
  }
  return ret;
}
int main(void)
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d%d%d",&L[i].p1.x,&L[i].p1.y,&L[i].p2.x,&L[i].p2.y);

  }
  qsort(L,n,sizeof(L[0]),cmp);

  for(int i=0;i<n;i++)
  {
    int index=searchCP(L[i]);
    if(index!=-1)
    {
      continuePoint[index][pointP2Count[index]++]=L[i].p2;
      
    }
    else
    {
      continuePoint[continueCount][0]=L[i].p2;
      continuePoint[continueCount][204]=L[i].p1;
      pointP2Count[continueCount]++;
      continueCount++;
    }
  }
  printf("%d %d %d",MaxCP(),continuePoint[MaxCPIndex()][204].x,continuePoint[MaxCPIndex()][204].y);
  return 0;
}
