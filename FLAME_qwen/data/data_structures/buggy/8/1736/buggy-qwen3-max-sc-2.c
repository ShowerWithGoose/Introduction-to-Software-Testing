#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[105][105]={ };
int visited[105]={ };
int ver, edge;
int ver_queue[105];
int rear=0, front=0;

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

void BFS(int v) // @@ [The BFS implementation is recursive and incorrectly reuses the global queue state, leading to incorrect traversal order and potential infinite recursion. BFS should be iterative using a queue, not recursive. Also, it prints "0 " separately in main before calling BFS(0), causing duplication or missing nodes.]
{
    printf("%d ",v);
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
        BFS(v); // @@ [Recursive call to BFS inside BFS breaks standard BFS logic and corrupts traversal order because each recursive call processes its own neighbors but shares global queue and visited state inconsistently.]
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
    printf("0 "); // @@ [This hardcoded print of "0 " before BFS(0) causes duplication if BFS also prints 0, or skips proper initialization. The BFS function itself prints the starting vertex, so this leads to double printing of vertex 0 in BFS output.]
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