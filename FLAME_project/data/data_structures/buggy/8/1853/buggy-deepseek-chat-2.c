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
                DF(ii); // @@ [Error: Function name 'DF' is used but not declared; should be 'DFS' or the function defined below is named 'DF', but the call here is inconsistent with the expected DFS traversal. Also, this loop skips vertex v but does not start from vertex 0 as required, causing incorrect output order.]
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
                        printf("%d ", v); // @@ [Error: This prints vertex v (the deleted vertex) which should not appear in the BFS output before deletion. The BFS should start from vertex 0, not v.]
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
        Ga[i][j] = 1000; // @@ [Error: Variable 'i' is out of scope here; it should be 'v' instead of 'i'. This line incorrectly uses the loop variable 'i' from the previous loop, which is now equal to vern, causing out-of-bounds access.]
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
                DF(ii); // @@ [Error: Same as before, function name 'DF' is used but should be 'DFS' or the defined function. Also, this loop does not start from vertex 0, causing incorrect DFS order after deletion.]
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
                        printf("0 "); // @@ [Error: This hardcodes printing "0 " instead of the actual starting vertex (which should be the first unvisited vertex in the loop). This causes incorrect BFS output after deletion.]
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
 void DF(int v) // @@ [Error: Function name 'DF' is used instead of 'DFS', which is inconsistent with the problem's expected function name and may cause confusion, though it works internally.]
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