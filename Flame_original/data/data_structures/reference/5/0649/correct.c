#include<stdio.h>
#include<stdlib.h>

typedef struct s
{
  int coefficient;
  int index;
}Nape;
Nape first[105];
int firstCnt=0;

Nape second[105];
int secondCnt=0;

Nape result[10005];
int resCnt=0;
Nape ride(Nape a,Nape b)
{
  Nape ret;
  ret.coefficient=a.coefficient*b.coefficient;
  ret.index=a.index+b.index;
  return ret;
}
int cmp(const void *a,const void *b)
{
  if((*(Nape*)a).index<(*(Nape*)b).index)
  {
    return 1;
  }
  else if((*(Nape*)a).index==(*(Nape*)b).index)
  {
    return 0;
  }
  else
  {
    return -1;
  }
  
}
void *mysearch(Nape nape,Nape *res,int count)
{
  for(int i=0;i<count;i++)
  {
    if(res[i].index==nape.index)
    {
      return &(res[i]);
    }
  }
  return NULL;
}
int main(void)
{
  while(1)
  {
    scanf("%d%d",&first[firstCnt].coefficient,&first[firstCnt].index);
    firstCnt++;
    char ch=getchar();
    if(ch=='\n')
    {
      break;

    }

  }
  while(~scanf("%d%d",&second[secondCnt].coefficient,&second[secondCnt].index))
  {
    secondCnt++;
  }
  for(int i=0;i<firstCnt;i++)
  {
    for(int j=0;j<secondCnt;j++)
    {
      Nape napeRide=ride(first[i],second[j]);
      Nape *Np;
      Np=(Nape*)mysearch(napeRide,result,resCnt);
      if(Np==NULL)
      {
        result[resCnt++]=napeRide;
      }
      else
      {
        Np->coefficient+=napeRide.coefficient;
      }
    }
  }
  qsort(result,resCnt,sizeof(result[0]),cmp);
  for(int i=0;i<resCnt;i++)
  {
    if(result[i].coefficient!=0)
    printf("%d %d ",result[i].coefficient,result[i].index);
    
  }
  return 0;
}
