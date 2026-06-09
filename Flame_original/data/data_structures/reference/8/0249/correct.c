#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define N 123
int table[N][N];
int visited[N];
void DFS(int i,int numVertex){
    printf("%d ",i);
    visited[i]=1;
    for (int j = 0; j < numVertex; j++)
    {
        if (table[i][j]&&!visited[j])
        {
            DFS(j,numVertex);
        }
    }
}

int queue[N];
int head=0;
int rear=-1;
void BFS(int i,int numVertex){
    queue[++rear]=i;
    visited[queue[head]]=1;
    do{
        for (int j = 0; j < numVertex; j++)
        {
            if (table[queue[head]][j]&&!visited[j])
            {
                visited[j]=1;
                queue[++rear]=j;
            }
        }
        printf("%d ",queue[head]);
        head++;
    }while (head!=rear+1);
}
int main(){
    memset(table,0,sizeof(table));
    memset(visited,0,sizeof(visited));
    memset(queue,0,sizeof(queue));
    int numVertex,numEdge;
    scanf("%d%d",&numVertex,&numEdge);
    int vexA,vexB;
    for (int i = 0; i < numEdge; i++)
    {
        scanf("%d%d",&vexA,&vexB);
        table[vexA][vexB]=table[vexB][vexA]=1;
    }
    int verDel;
    scanf("%d",&verDel);
    memset(visited,0,sizeof(visited));
    DFS(0,numVertex);
    putchar('\n');
    memset(visited,0,sizeof(visited));
    memset(queue,0,sizeof(queue));
    rear=-1;head=0;      
    BFS(0,numVertex);
    putchar('\n');
    for (int j = 0; j < numVertex; j++)
    {
        table[verDel][j]=table[j][verDel]=0;
    }
    memset(visited,0,sizeof(visited));
    DFS(0,numVertex);
    putchar('\n');
    memset(visited,0,sizeof(visited));
    memset(queue,0,sizeof(queue));
    rear=-1;head=0;      
    BFS(0,numVertex);
    putchar('\n'); 
    return 0;
}


