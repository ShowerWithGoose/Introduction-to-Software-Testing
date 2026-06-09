/*********************************************************************
    程序名: C/E6789 - ABCDEFGHIJ
    版权:
    作者:
    日期: 2024-05-22 11:59
    说明: Chinese Cabbage Dog
*********************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#define eps 1e-8
#define TRUE 1
#define FALSE 0

void clean();
void depth();
void wide();
int Graph__queue[100] = {0};
int Graph__top = 0, Graph__end = 0;

void wide(int Graph[][100], int visited[], int start, int conclusion)
{
    visited[start] = 1;
    if (start != 0)
        printf(" %d", start);
    else
        printf("%d", start);
    for (int i = 0; i < conclusion; i++)
    {
        if (Graph[start][i] != 0)
            if (visited[i] == 0)
            {
                visited[i] = 1;
                Graph__queue[Graph__end] = i;
                Graph__end++;
            }
    }
    if (Graph__top < Graph__end)
    {
        Graph__top++;
        wide(Graph, visited, Graph__queue[Graph__top - 1], conclusion);
    }
}


int main()
{
    int point_num, edge_num, begin, end, del;
    scanf("%d %d", &point_num, &edge_num);
    int Graph[100][100] = {0};
    int visited[100] = {0};

    for (int i = 0; i < edge_num; i++)
    {
        scanf("%d %d", &begin, &end);
        Graph[begin][end] = 1;
        Graph[end][begin] = 1;
    }

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < point_num; i++)
        depth(Graph, visited, 0, edge_num); // @@ [Error: The loop iterates point_num times, but depth() should only be called once from vertex 0. This causes repeated DFS calls, printing the same sequence multiple times. Also, the second parameter 'conclusion' should be point_num (number of vertices), not edge_num.]
    clean(visited, point_num);
    printf("\n");
    wide(Graph, visited, 0, edge_num); // @@ [Error: The fourth parameter 'conclusion' should be point_num (number of vertices), not edge_num. Using edge_num limits the loop to the number of edges, which may miss vertices.]
    clean(visited, point_num);
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
    scanf("%d", &del);
    for (int i = 0; i < point_num; i++)
    {
        Graph[i][del] = 0;
        Graph[del][i] = 0;
    }
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
    visited[del] = 1;
    for (int i = 0; i < point_num; i++)
        depth(Graph, visited, i, edge_num); // @@ [Error: This loop calls depth() for every vertex i, but DFS should start only from vertex 0. Also, visited[del] is set to 1, but the loop may call depth on unvisited vertices incorrectly. The fourth parameter should be point_num, not edge_num.]
    printf("\n");
    clean(visited, point_num);
    wide(Graph, visited, 0, edge_num); // @@ [Error: The fourth parameter 'conclusion' should be point_num, not edge_num. Also, after deletion, the graph may have disconnected components, but BFS should still start from 0.]
}




/***************************************************
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3



4 4
0 1
0 2
1 2
2 3

0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0
****************************************************/




void clean(int *visited, int point_num)
{
    for (int i = 0; i < point_num; i++)
        visited[i] = 0;
}

void depth(int Graph[][100], int visited[], int start, int conclusion)
{
    if (visited[start] == 0)
    {
        if (start != 0)
            printf(" %d", start);
        else
            printf("%d", start);
        visited[start] = 1;
        for (int i = 0; i < conclusion; i++)
        {
            if (Graph[start][i] != 0)
            {
                depth(Graph, visited, i, conclusion);
            }
        }
    }
}