#include <stdio.h>
int graph[101][101];
int visited[100];
int node,edge;
int delnum;



void DFS(int knot){
    int i;
    printf("%d ",knot);
    for(i=0;i<node;i++){
        if(graph[knot][i]==1&&visited[i]==0)
        {
            visited[i]=1;
            DFS(i);
        }
    }

}


void BFS(){
    int queue[101];
    int top=0,tail=1;
    queue[0]=0;

    int i;
    while(top<tail){
        for(i=0;i<node;i++){
            if(graph[queue[top]][i]==1&&visited[i]==0){
                queue[tail]=i;
                visited[i]=1;
                tail++;
            }
        }
        printf("%d ",queue[top]);
        top++;
    }
}


int main()
{
    scanf("%d %d",&node,&edge);
    int i,v1,v2;
    for(i=0;i<edge;i++){
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    scanf("%d",&delnum);

    visited[0]=1;

    printf("%d ",0);
    for(i=0;i<node;i++){
        if(graph[0][i]==1&&visited[i]==0)
        {
            visited[i]=1;
            DFS(i);
        }
    }




    for(i=0;i<node;i++)
        visited[i]=0;

    printf("\n");

    visited[0]=1;
    BFS(0);


    for(i=0;i<node;i++)
        visited[i]=0;

    printf("\n");

    visited[delnum]=1;
    visited[0]=1;
    printf("%d ",0);
    for(i=0;i<node;i++){
        if(graph[0][i]==1&&visited[i]==0)
        {
            visited[i]=1;
            DFS(i);
        }
    }

    for(i=0;i<node;i++)
        visited[i]=0;

    printf("\n");

    visited[delnum]=1;
    visited[0]=1;
    BFS(0);

    return 0;
}


