#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[105][105]={ };
int visited[105]={ };
int ver, edge;
int ver_queue[105];
int rear=0, front=0; // @@ Global queue pointers are not reset between BFS calls, causing incorrect queue behavior in subsequent traversals.

void change()
{
    for(int i=0; i<ver; i++)
        visited[i]=0;
}

void DFS(int v)
{
    visited[v]=1;
    printf("%d ", v);
    for(int i=0; i<ver; i++)
    {
        if(graph[v][i]==1&&visited[i]!=1)
            DFS(i);
    }
}

void BFS(int v)
{
    printf("%d ",v); // @@ The recursive BFS implementation is non-standard and error-prone; standard BFS should use an iterative loop to process the queue.
    visited[v]=1;
    for(int i=0; i<ver; i++)
    {
        if(graph[v][i]==1&&visited[i]!=1){
            visited[i]=1;
            ver_queue[rear++]=i;
        }
    }
    while(rear>front)
    {
        v=ver_queue[front++];
        BFS(v); // @@ Recursive call misuses the queue and can cause stack overflow or incorrect traversal order; BFS should be iterative.
    }
}

int main()
{
    scanf("%d%d", &ver, &edge);
    for(int i=0; i<edge; i++)
    {
        int vi, vj;
        scanf("%d%d", &vi, &vj);
        graph[vi][vj]=graph[vj][vi]=1;
    }
    DFS(0);
    printf("\n");
    change();
    printf("0 "); // @@ Redundant output; BFS(0) already prints the starting vertex 0, resulting in an extra "0 " in the output.
    BFS(0);
    printf("\n");
    change();
    int dele_num;
    scanf("%d", &dele_num);
    for(int i=0; i<ver; i++)
        graph[dele_num][i]=graph[i][dele_num]=0;
    DFS(0);
    printf("\n");
    change();
    BFS(0);
    printf("\n");
    change();
    return 0;
}