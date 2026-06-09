#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Visited[102]={0};
int V,E,a,b,c=103;
void BFS(int v);
void DFS(int i);
void travelDFS(int n);
void travelBFS(int n);
int Queue[102],front=0,rear=-1;
int M[102][102]={0};
int main()
{
     scanf("%d%d",&V,&E);
     for(int i=0;i<E;i++)
     {
          scanf("%d%d",&a,&b);
          M[a][b]=1;
          M[b][a]=1;
     }
     travelDFS(V);
     printf("\n");
     travelBFS(V);
     printf("\n");
     scanf("%d",&c);
     for(int i=0;i<102;i++)
     {
          M[i][c]=0;
          M[c][i]=0;
     }
     travelDFS(V);
     printf("\n");
     travelBFS(V);
     printf("\n");
     
     
     return 0;
}
void DFS(int i)
{
     int j;
     Visited[i]=1;
     printf("%d ",i);
     for(j=0;j<V;j++)
          if(M[i][j]==1&&!Visited[j]&&j!=c)
               DFS(j);
}
void travelDFS(int n)
{
     int i;
     for(i=0;i<n;i++)
     {
          if(i==c)continue;
          Visited[i]=0;
     }
     for(i=0;i<n;i++)
          if(!Visited[i]&&i!=c)
               DFS(i);
}
void travelBFS(int n)
{
     int i;
     for(i=0;i<n;i++)
     {
          if(i==c)continue;
          Visited[i]=0;
     }
     for(i=0;i<n;i++)
          if(!Visited[i]&&i!=c)
               BFS(i);
}
void BFS(int v)
{
     Visited[v]=1;
     rear++;
     Queue[rear]=v;
     while(rear>=front)
     {
          v=Queue[front];
          front++;
          printf("%d ",v);
          for(int i=0;i<V;i++)
          {
               if(!Visited[i]&&M[i][v]==1&&i!=c)
               {
                    Visited[i]=1;
                    rear++;
                    Queue[rear]=i;
               }
          }
     }
}


