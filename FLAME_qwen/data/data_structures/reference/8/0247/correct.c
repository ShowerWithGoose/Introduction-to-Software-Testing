#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100;
int n,m;
int flag=0;
int visit1[100]={0},visit2[100]={0};
int edge[100][100]={0};
void ling(int visit[])
{
  for(int i=0;i<n;i++)
  {
    visit[i]=0;
  }
  flag=0;
}
void DFS(int v)
{
  if(flag==0)
  {
    printf("%d ",v);
    flag=1;
  }
  else {
    printf("%d ",v);
  }
  visit1[v]=1;
  for(int i=1;i<=n;i++)
  {
    if(edge[v][i]==1&&visit1[i]==0)
    DFS(i);
  }
}
void BFS(v)
{
  int pp;
  visit2[1]=v;
  int top=1,end=1;
  while(top<=end)
  {
    pp=visit2[top];
    top++;
    if(visit1[pp]==1)
    {
      continue;
    }
    if(flag==0)
    {
      printf("%d ",pp);
      flag=1;
    }
    else{
      printf("%d ",pp);
    }
    visit1[pp]=1;
    for(int i=1;i<n;i++)
    {
      if(edge[pp][i]==1&&visit1[i]==0)
      {
        end++;
        visit2[end]=i;
      }
    }
  }
}
int main()
{
  int x,y;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
  {
    scanf("%d%d",&x,&y);
    edge[x][y]=1;
    edge[y][x]=1;
  }
  DFS(0);
  printf("\n");
 ling(visit1);
  BFS(0);
  printf("\n");
 ling(visit1);
  int del;
  scanf("%d",&del);
  visit1[del]=1;
  DFS(0);
  printf("\n");
 ling(visit1);
  visit1[del]=1;
  BFS(0);
  return 0;
}
