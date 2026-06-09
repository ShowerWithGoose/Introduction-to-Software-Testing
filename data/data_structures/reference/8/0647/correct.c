#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 105
void DFS(int G[][MAXNUM],int i);
void DFStravel(int G[][MAXNUM]);
void BFS(int G[][MAXNUM],int i);
void BFStravel(int G[][MAXNUM]);
int visited[MAXNUM] = {0};
int npoint;

int main()
{
    int Graph[MAXNUM][MAXNUM];
    memset(Graph,0,sizeof(Graph));
    int nedge,x,y;
    scanf("%d %d",&npoint,&nedge);
    for(int i=0; i<nedge; i++)
    {
        scanf("%d %d",&x,&y);
        Graph[x][y] = Graph[y][x] = 1;
    }
    DFStravel(Graph); printf("\n");
    BFStravel(Graph); printf("\n");

    int delet1;
    scanf("%d",&delet1);
    for(int i=0; i<npoint; i++)
        Graph[i][delet1] = 0;
    for(int i=0; i<npoint; i++)
        Graph[delet1][i] = 0;
    DFStravel(Graph); printf("\n");
    BFStravel(Graph); printf("\n");
}

void DFStravel(int G[][MAXNUM])
{
    for(int i=0; i<npoint; i++)
        visited[i] = 0;
    /*for(int i=0; i<npoint; i++)
        if(visited[i]==0)
            DFS(G,i);*/
    DFS(G,0);
}

void DFS(int G[][MAXNUM],int i)
{
    int j;
    visited[i] = 1;
    printf("%d ",i);
    for(j=0; j<npoint; j++)
    {
        if(visited[j]==0 && G[i][j]==1)
            DFS(G,j);
    }
}

void BFStravel(int G[][MAXNUM])
{
    for(int i=0; i<npoint; i++)
        visited[i] = 0;
    /*for(int i=0; i<npoint; i++)
        if(visited[i]==0)
            BFS(G,i);*/
    BFS(G,0);
}

void BFS(int G[][MAXNUM],int i)
{
    int Queue[MAXNUM];
    int front = 0; int rear = 0;
    printf("%d ",i);
    visited[i] = 1;
    Queue[rear++] = i;
    while(rear>front)
    {
        i = Queue[front++];
        for(int j=0; j<npoint; j++)
            if(!visited[j] && G[i][j]==1)
            {
                printf("%d ",j);
                visited[j] = 1;
                Queue[rear++] = j;
            }
    }
}
