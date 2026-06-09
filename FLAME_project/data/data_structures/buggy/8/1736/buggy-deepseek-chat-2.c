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

void BFS(int v)
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
        BFS(v); // @@ [Error: Using recursion in BFS causes incorrect traversal order and duplicates. BFS should use an iterative queue-based approach, not recursive calls. The recursive call to BFS(v) after dequeuing leads to a depth-first-like behavior and prints vertices multiple times, as seen in the buggy output "0 0 1 2".]
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
    printf("0 "); // @@ [Error: This extra print statement causes the BFS output to start with "0 " before the actual BFS function runs, resulting in "0 0 1 2" instead of "0 1 2". The BFS function already prints the starting vertex, so this line should be removed.]
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