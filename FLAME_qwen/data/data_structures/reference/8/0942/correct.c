#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int graph[101][101];
int visited[101];
int vN,eN;

void DFS(int graph[][101],int i){
    visited[i]=1;
    printf("%d ",i);
    for(int j=0;j<vN;j++){
        if((graph[i][j]==1)&&!visited[j])
            DFS(graph,j);
    }
}
int queue[200];
int head=0,rear=0;
void BFS(int graph[][101],int i){
    visited[i]=1;
    // printf("%d ",i);
    queue[rear++]=i;
    int save;

    while(head!=rear&&head<rear){
        save=queue[head++];
        printf("%d ",save);
        for(int j=0;j<vN;j++){
            if(!visited[j]&&graph[save][j]==1)
                {
                    visited[j]=1;
                    queue[rear++]=j;
                }
        }
    }
}
int main()
{
    scanf("%d%d",&vN,&eN);
    int a,b;
    for(int i=0;i<eN;i++){
        scanf("%d%d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }   
    for(int i=0;i<vN;i++){
        visited[i]=0;
    }
    DFS(graph,0);
    printf("\n");
    for(int i=0;i<vN;i++){
        visited[i]=0;
    }
    BFS(graph,0);
    printf("\n");

    for(int i=0;i<vN;i++){
        visited[i]=0;
    }
    scanf("%d",&a);
    for(int i=0;i<vN;i++){
        graph[a][i]=0;
        graph[i][a]=0;
    }
    DFS(graph,0);
    printf("\n");
    for(int i=0;i<vN;i++){
        visited[i]=0;
    }
    BFS(graph,0);
    return 0;
}
