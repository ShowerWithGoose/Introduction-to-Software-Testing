#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 105

int weight[maxsize][maxsize];
int vn;
int state[maxsize];

int creatlist();
void start();
void DFS(int );
void BFS(int );
void restate();
void deletev(int );

int main()
{
  int dev;
  dev=creatlist();
  DFS(0);
  printf("\n");
  restate();
  BFS(0);
  printf("\n");
  deletev(dev);
  restate();
  DFS(0);
  printf("\n");
  restate();
  BFS(0);
  printf("\n");
  return 0;
}



void deletev(int a)
{
    for(int i=0;i<vn;i++)
    {
        weight[a][i]=0;
        weight[i][a]=0;
    }
}

void restate()
{
    for(int i=0;i<vn;i++)
        state[i]=0;
}

void DFS(int a)
{
    state[a]=1;
    printf("%d ",a);
    for(int j=0;j<vn;j++)
    {
        if(weight[a][j]==1&&state[j]==0)
            DFS(j);
    }
}

void BFS(int a)
{
    int stack[vn];
    int top=-1,head=0,k;
    stack[++top]=a;
    state[a]=1;
    while(top-head>=0)
    {
        k=stack[head++];
        printf("%d ",k);
        for(int r=0;r<vn;r++)
        {
            if(weight[k][r]!=0&&state[r]==0)
                {
                    stack[++top]=r;
                    state[r]=1;
                }
        }
    }
}


int creatlist()
{
    int v0,v1,en,dln;
    scanf("%d %d",&vn,&en);
    for(int i=0;i<en;i++)
    {
        scanf("%d%d",&v0,&v1);
        weight[v0][v1]=weight[v1][v0]=1;
    }
    scanf("%d",&dln);
    return dln;
}

void start()
{
    for(int i=0;i<maxsize;i++)
        {
        state[i]=0;
        for(int j=0;j<maxsize;j++)
              {
                  weight[i][j]=0;
              }
        }
}

