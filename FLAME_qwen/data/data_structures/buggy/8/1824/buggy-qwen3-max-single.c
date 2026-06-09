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
    for (int i = 0; i < point_num; i++) // @@ [This loop incorrectly calls depth() 'point_num' times starting from 0, causing repeated and incorrect DFS output. DFS should be called only once from vertex 0.]
        depth(Graph, visited, 0, edge_num);
    clean(visited, point_num); // @@ [The function 'clean' is declared without parameters but defined with parameters, causing a compilation error due to mismatched function signature.]
    printf("\n");
    wide(Graph, visited, 0, edge_num);
    clean(visited, point_num); // @@ [Same function signature mismatch error as above.]
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
    visited[del] = 1; // @@ [Marking the deleted vertex as visited before traversal is correct in intent, but the subsequent DFS loop is flawed.]
    for (int i = 0; i < point_num; i++) // @@ [This loop runs DFS from every vertex i (including non-zero and possibly unconnected ones), which violates the requirement to start from vertex 0 and produces wrong output.]
        depth(Graph, visited, i, edge_num);
    printf("\n");
    clean(visited, point_num); // @@ [Function signature mismatch again. Also, 'clean' is called after printing newline but before BFS, yet BFS uses global queue state that isn't reset properly.]
    wide(Graph, visited, 0, edge_num); // @@ [The 'wide' function uses global variables Graph__top and Graph__end which retain state from previous BFS call, leading to incorrect traversal. They must be reset to 0 before each BFS.]
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




void clean(int *visited, int point_num) // @@ [Function definition has parameters, but forward declaration 'void clean();' has none — this causes a compilation error in strict C.]
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
        for (int i = 0; i < conclusion; i++) // @@ [Loop bound should be 'point_num' (number of vertices), not 'conclusion' (which is edge_num). This causes out-of-bound or incomplete traversal when edge_num != point_num.]
        {
            if (Graph[start][i] != 0)
            {
                depth(Graph, visited, i, conclusion);
            }
        }
    }
}