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
        depth(Graph, visited, 0, edge_num); // @@ [Calling depth() 'point_num' times from vertex 0 without resetting visited leads to only the first call printing anything; subsequent calls do nothing because visited[0] is already 1. Also, passing 'edge_num' as 'conclusion' is wrong—it should be 'point_num'.]
    clean(visited, point_num);
    printf("\n");
    wide(Graph, visited, 0, edge_num); // @@ [Passing 'edge_num' instead of 'point_num' as 'conclusion' causes BFS to only check first 'edge_num' vertices, which may skip valid vertices if edge_num < point_num.]
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
        depth(Graph, visited, i, edge_num); // @@ [Looping over all vertices and calling depth() on each will print disconnected fragments; DFS should start only from 0. Also, using 'edge_num' instead of 'point_num' again. Additionally, marking 'del' as visited before traversal is correct, but starting DFS from every unvisited node violates requirement to start from 0.]
    printf("\n");
    clean(visited, point_num);
    wide(Graph, visited, 0, edge_num); // @@ [Again, passing 'edge_num' instead of 'point_num' as 'conclusion' limits traversal range incorrectly.]
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
        for (int i = 0; i < conclusion; i++) // @@ [Loop bound uses 'conclusion' (which is passed as edge_num) instead of 'point_num', so it may not traverse all vertices if edge_num < point_num. Should loop up to point_num.]
        {
            if (Graph[start][i] != 0)
            {
                depth(Graph, visited, i, conclusion);
            }
        }
    }
}