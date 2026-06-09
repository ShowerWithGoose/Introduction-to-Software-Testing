#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned long long ull;
const int inf = (int)1e8;
int front, rear;
typedef struct graph
{
    int sumVertex, sumEdge;
    int **edge;
} Graph, *pGraph;

bool *visited;
bool flag = 0;

int Dequeue(Graph G, int *queue)
{
    int tmp = front;
    front = (front + 1) % G.sumVertex;
    return queue[tmp];
}

void Enqueue(Graph G, int *queue, int in)
{
    rear = (rear + 1) % G.sumVertex;
    queue[rear] = in;
}

bool isEmpty(Graph G)
{
    return (rear + 1) % G.sumVertex == front;
}

void DFS(Graph G, int vertex, bool visited[])
{
    int i;
    if (flag)
        printf(" ");
    printf("%d", vertex);
    flag = 1;
    visited[vertex] = true;
    for (i = 0; i < G.sumVertex; ++i)
        if (G.edge[vertex][i] && !visited[i])
            DFS(G, i, visited);
}

void BFS(Graph G, int *queue, bool visited[])
{
    memset(queue, 0, sizeof(queue));
    int i;
    if (!visited[0])
    {
        visited[0] = true;
        printf("%d", 0);
        Enqueue(G, queue, 0);
        while (!isEmpty(G))
        {
            i = Dequeue(G, queue);
            for (int j = 0; j < G.sumVertex; ++j)
            {
                if (G.edge[i][j] && !visited[j])
                {
                    printf(" %d", j);
                    visited[j] = true;
                    Enqueue(G, queue, j);
                }
            }
        }
    }
}
int main(int argc, const char *argv[])
{
    int v, e, l, r, u;
    scanf("%d %d", &v, &e);
    Graph G;
    front = 0;
    rear = v - 1;
    int *queue = (int *)calloc(v + 1, sizeof(int));
    visited = (bool *)calloc(v + 1, sizeof(bool));
    G.edge = (int **)calloc(v + 1, sizeof(int *));
    G.sumEdge = e;
    G.sumVertex = v;
    for (int i = 0; i <= v; ++i)
        G.edge[i] = (int *)calloc(v + 1, sizeof(int));
    for (int i = 0; i < e; ++i)
    {
        scanf("%d %d", &l, &r);
        G.edge[l][r] = 1;
        G.edge[r][l] = 1;
    }
    scanf("%d", &u);

    flag = 0;
    memset(visited, 0, sizeof(bool) * (v + 1));
    DFS(G, 0, visited);
    putchar('\n');

    memset(visited, 0, sizeof(bool) * (v + 1));
    BFS(G, queue, visited);
    putchar('\n');

    for (int i = 0; i < v; ++i)
    {
        G.edge[u][i] = 0;
        G.edge[i][u] = 0;
    }

    flag = 0;
    memset(visited, 0, sizeof(bool) * (v + 1));
    DFS(G, 0, visited);
    putchar('\n');

    memset(visited, 0, sizeof(bool) * (v + 1));
    BFS(G, queue, visited);
    putchar('\n');

    return 0;
}


