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

void BFS(int v) // @@ [The BFS implementation is recursive and incorrect. It should be iterative using a queue, but instead it recursively calls BFS on each neighbor, which leads to incorrect traversal order and potential infinite recursion or stack overflow. Also, the initial "0 " is printed separately in main(), causing duplication or misalignment.]
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
        BFS(v); // @@ [Recursive call to BFS inside BFS is wrong. This turns BFS into a hybrid DFS/BFS and breaks level-order traversal. Should process neighbors iteratively without recursion.]
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
    printf("0 "); // @@ [Hardcoding "0 " here assumes BFS starts with 0, but BFS(0) also prints "0 " again, leading to duplicate "0" in output. The BFS function itself already prints the starting vertex, so this causes incorrect output like "0 0 ...".]
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