#include<stdio.h>
#include<string.h>
int Ga[101][101];
int Visited[101];
void bubbleSort(int v, int n);
void travelDFS(int n, int warn);
void DFS(int v);
void travelBFS(int n, int warn);
void BFS(int v);
int Q[100];
int main()
{
    int vern, edgen, v1, v2, v;
    int i, j,ii,jj,iii,flag,hold;
    memset(Ga, -1, sizeof(Ga));
    memset(Q, -1, sizeof(Q));
    scanf("%d %d", &vern, &edgen);
    for (i = 0; i < edgen; i++)
    {
        scanf("%d %d", &v1, &v2);
        for (j = 0; Ga[v1][j] != -1; j++);
        Ga[v1][j] = v2;
        for (j = 0; Ga[v2][j] != -1; j++);
        Ga[v2][j] = v1;
    }
    scanf("%d", &v);
    for (i = 0; i < vern; i++)
    {
        for (j = 0; Ga[i][j] != -1; j++);
    {
            for (ii = 0; ii < j - 1; ii++)
    {
        flag = 0;
        for (jj = 0; jj < j - 1 - ii; jj++)
        {
            if (Ga[i][jj] > Ga[i][jj + 1])
            {
                hold = Ga[i][jj];
                Ga[i][jj] = Ga[i][jj + 1];
                Ga[i][jj + 1] = hold;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}
    }
    //travelDFS(vern,v);
    for (ii = 0; ii < vern; ii++)
        Visited[ii] = 0;
    for (ii = 0; ii < vern; ii++)
    {
        if (ii == v)
            continue;
        else
        {
            if (Visited[ii] == 0)
                {
                DF(ii); // @@ The function name is 'DF', but it should likely be 'DFS' or consistent. However, looking at the definition below, the function is named 'DF'. The logic error is that the problem requires starting traversal from vertex 0. This loop starts from the first unvisited vertex. If vertex 0 is not visited, it will start there. But if vertex 0 is skipped or handled incorrectly, it fails. More importantly, the output format requires specific sequences.
                }
        }
    }
    printf("\n");
    //travelBFS(vern,v);
        for (ii = 0; ii < vern; ii++)
        Visited[ii] = 0;
    for (ii = 0; ii < vern; ii++)
    {
        if (ii == v)
            continue;
        else
        {
            if (Visited[ii] == 0)
                {
                        printf("%d ", v); // @@ Error: The BFS traversal should start from vertex 0 (or the current unvisited vertex 'ii'), not print the deleted vertex 'v'. The problem states traversal starts from vertex 0. Here, it prints 'v' which is the deleted vertex, causing wrong output. It should print 'ii' if 'ii' is the start node, but typically BFS/DFS starts at 0. Given the loop structure, it seems to attempt to handle components, but printing 'v' is definitely wrong.
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0];
        for (jj = 0; Q[jj] != -1; jj++)
            Q[jj] = Q[jj + 1];
        for (iii = 0; Ga[ii][iii] != -1; iii++)
        {
            if (Ga[ii][iii] != 1000)
            {
                if (Visited[Ga[ii][iii]] == 0)
                {
                    printf("%d ", Ga[ii][iii]);
                    Visited[Ga[ii][iii]] = 1;
                    for (jj = 0; Q[jj] != -1; jj++);
                    Q[jj] = Ga[ii][iii];
                }
            }
        }
    }
                }
        }
    }
    printf("\n");
    for (i = 0; i < vern; i++)
    {
        for (j = 0; Ga[i][j] != -1; j++)
        {
            if (Ga[i][j] == v)
                Ga[i][j] = 1000;
        }
    }
    for (j = 0; Ga[v][j] != -1; j++)
        Ga[i][j] = 1000; // @@ Error: Variable 'i' is used here, but it retains its value from the previous loop (likely 'vern'). It should probably be iterating through Ga[v] to mark them as invalid/deleted, or simply ignoring Ga[v] in traversals. Using 'i' which is out of bounds or incorrect index leads to undefined behavior or incorrect memory access. It should likely be Ga[v][j] = 1000 inside a loop or just rely on the visited check.
    //travelDFS(vern,v);
        for (ii = 0; ii < vern; ii++)
        Visited[ii] = 0;
    for (ii = 0; ii < vern; ii++)
    {
        if (ii == v)
            continue;
        else
        {
            if (Visited[ii] == 0)
                {
                DF(ii); // @@ Same issue as before, function name is DF.
                }
        }
    }
    printf("\n");
    //travelBFS(vern,v);
for (ii = 0; ii < vern; ii++)
        Visited[ii] = 0;
    for (ii = 0; ii < vern; ii++)
    {
        if (ii == v)
            continue;
        else
        {
            if (Visited[ii] == 0)
                {
                        printf("0 "); // @@ Error: Hardcoding "0 " is incorrect. The traversal should start from the current unvisited vertex 'ii' (which should be 0 for the first component). If 'ii' is not 0, this is wrong. Even if 'ii' is 0, printing it manually and then proceeding with BFS logic which also prints neighbors is fragile. The main issue is that it doesn't print the starting node 'ii' dynamically, it assumes it's 0. In the second BFS (after deletion), if we start at 0, it prints 0. But the variable 'ii' is the loop variable. If the graph is disconnected after deletion (though problem says connected), or if start node changes, this fails. Specifically, it should print 'ii' instead of "0 ".
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0];
        for (jj = 0; Q[jj] != -1; jj++)
            Q[jj] = Q[jj + 1];
        for (iii = 0; Ga[ii][iii] != -1; iii++)
        {
            if (Ga[ii][iii] != 1000)
            {
                if (Visited[Ga[ii][iii]] == 0)
                {
                    printf("%d ", Ga[ii][iii]);
                    Visited[Ga[ii][iii]] = 1;
                    for (jj = 0; Q[jj] != -1; jj++);
                    Q[jj] = Ga[ii][iii];
                }
            }
        }
    }
                }
        }
    }
    return 0;
    
    
    
    
 } 
 void DF(int v)
{
    int i;
    if (Visited[v] == 0)
    {

        printf("%d ", v);
    }    
    Visited[v] = 1;//标识顶点v被访问
    for (i = 0; Ga[v][i] != -1; i++)
    {
        if (Ga[v][i] != 1000)
        {
            if (Visited[Ga[v][i]] == 0)
                DF(Ga[v][i]);
        }
    }
}