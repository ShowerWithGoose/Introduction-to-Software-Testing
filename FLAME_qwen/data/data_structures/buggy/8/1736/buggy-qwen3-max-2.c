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

void BFS(int v) // @@ [The BFS implementation is recursive and incorrectly reuses the global queue without proper initialization or management. It also prints "0 " separately in main(), causing duplication or incorrect order. The BFS should be iterative and use a fresh queue each time.]
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
        BFS(v); // @@ [Recursive call to BFS is incorrect; BFS must be iterative. This causes incorrect traversal order and potential stack overflow. Also, the queue state (rear/front) is not reset between BFS calls, leading to interference between traversals.]
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
    printf("0 "); // @@ [Hardcoding "0 " here duplicates the starting vertex and interferes with BFS output. The BFS function already prints the starting vertex, so this leads to double printing of vertex 0.]
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