#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int n,cnt;
int edge[105][105];
int a,b,c;
int visit[105];


void DF(int k)
{
    int i=k;
    printf("%d ",i);
    visit[i]=1;
    for (int j = 0; j < n; j++)
    {
        if (edge[i][j]==1&&visit[j]==0)
        {
            DF(j);
        }
        
    }
}

void BF(int k)
{
  int queue[105];
  int front=0;
  int rear=-1;
  queue[++rear]=k;
  int i;
  while (rear>=front)
  {
    i=queue[front++];
    if (visit[i]==0)
    {
      visit[i]=1;
      printf("%d ",i);
      for (int j = 0; j < n; j++)
      {
        if (edge[i][j]==1)
        {
            queue[++rear]=j;
        }
      } 
    }
  }
}

int main()
{
  scanf("%d%d",&n,&cnt);
  for (int i = 0; i < cnt; i++)
  {
    scanf("%d%d",&a,&b);
    edge[a][b]=1;edge[b][a]=1;
  }
  scanf("%d",&c);
  DF(0);printf("\n");
  for (int i = 0; i < n; i++)
  {
      visit[i]=0;
  }
  BF(0);printf("\n");
  for (int i = 0; i < n; i++)
  {
      visit[i]=0;
  }
  for (int i = 0; i < n; i++)
  {
      edge[i][c]=0;
      edge[c][i]=0;
  }
  DF(0);printf("\n");
  for (int i = 0; i < n; i++)
  {
      visit[i]=0;
  }
  BF(0);printf("\n");



    return 0;
}
