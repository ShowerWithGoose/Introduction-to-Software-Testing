#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_VERTEX 500

bool edge[MAX_VERTEX][MAX_VERTEX];
bool visited[MAX_VERTEX];
int queue[100];
int front, rear = -1;
int verNum, edgeNum;

void depthFirstTraverse(int);
void breadthFirstTraverse(int);

int main()
{

    int a, b;
    int numToDel;
    scanf("%d%d", &verNum, &edgeNum);
    for (int i = 1; i <= edgeNum; ++i)
    {
        scanf("%d%d", &a, &b);
        edge[a][b] = edge[b][a] = 1;
    }
    scanf("%d", &numToDel);
    depthFirstTraverse(0);
    putchar('\n');
    memset(visited, 0, sizeof(visited));
    breadthFirstTraverse(0);
    putchar('\n');
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < verNum; ++i)
    {
        edge[i][numToDel] = edge[numToDel][i] = 0;
    }

    depthFirstTraverse(0);
    putchar('\n');
    memset(visited, 0, sizeof(visited));
    breadthFirstTraverse(0);
    memset(visited, 0, sizeof(visited));
    return 0;
}

void depthFirstTraverse(int start)
{
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < verNum; ++i)
    {
        if (edge[i][start] && !visited[i])
        {
            depthFirstTraverse(i);
        }
    }
}

void breadthFirstTraverse(int start)
{
    visited[start] = 1;
    printf("%d ", start);
    queue[++rear] = start;
    while (rear >= front)
    {
        int vertex = queue[front++];
        for (int i = 0; i < verNum; ++i)
        {
            if (edge[i][vertex] && !visited[i])
            {
                visited[i] = 1;
                printf("%d ", i);
                queue[++rear] = i;
            }
        }
    }
}


