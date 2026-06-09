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
    for (int i = 0; i < point_num; i++) // @@ [This loop causes multiple DFS calls starting from 0, leading to repeated output and incorrect traversal. DFS should be called only once from vertex 0.]
        depth(Graph, visited, 0, edge_num); // @@ [The 'conclusion' parameter should be 'point_num' (number of vertices), not 'edge_num'. This causes DFS to only check first 'edge_num' vertices, which may skip valid vertices if edge_num < point_num.]
    clean(visited, point_num);
    printf("\n");
    wide(Graph, visited, 0, edge_num); // @@ [Same issue: 'conclusion' should be 'point_num', not 'edge_num'. BFS will not traverse all vertices if edge_num < point_num.]
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
    visited[del] = 1; // @@ [Marking deleted vertex as visited is correct, but the following loop is wrong.]
    for (int i = 0; i < point_num; i++) // @@ [This loop calls DFS on every vertex i, but traversal must start only from vertex 0. Also, it uses 'i' as start, which violates requirement to start from 0.]
        depth(Graph, visited, i, edge_num); // @@ [Again, 'conclusion' should be 'point_num', not 'edge_num'. Additionally, calling DFS on every i leads to multiple traversals and wrong output.]
    printf("\n");
    clean(visited, point_num); // @@ [This clean() call resets visited array AFTER printing DFS, so BFS uses a clean array but misses that 'del' should remain excluded. However, more critically, BFS below starts correctly from 0, but the prior DFS logic is completely broken.]
    wide(Graph, visited, 0, edge_num); // @@ ['conclusion' should be 'point_num', not 'edge_num'.]
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
        for (int i = 0; i < conclusion; i++) // @@ [Loop bound should be 'point_num' (or n), not 'conclusion' which is passed as 'edge_num'. This causes incomplete adjacency checks.]
        {
            if (Graph[start][i] != 0)
            {
                depth(Graph, visited, i, conclusion); // @@ [Same: 'conclusion' should be total number of vertices, not edges.]
            }
        }
    }
}