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
                DF(ii); // @@ [Function name 'DF' is used but the declared function is named 'DFS'; this causes a linker error because 'DF' is not defined anywhere before use.]
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
                        printf("%d ", v); // @@ [This prints the deleted vertex 'v' instead of the current starting vertex 'ii'. Also, traversal should start from vertex 0, but this loop starts from 'ii', which may not be 0.]
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0]; // @@ [Reusing loop variable 'ii' inside the BFS loop modifies the outer loop control variable, causing undefined behavior and breaking the outer for-loop logic.]
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
        Ga[i][j] = 1000; // @@ [Here, 'i' is used instead of 'v'; after the previous loop, 'i' equals 'vern', so this writes out of bounds and doesn't actually clear the adjacency list of vertex 'v'.]
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
                DF(ii); // @@ [Same issue as before: calling undefined function 'DF' instead of 'DFS'.]
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
                        printf("0 "); // @@ [Hardcoded "0 " is printed regardless of the actual starting vertex 'ii'; also, traversal must always start from vertex 0, but this loop iterates from 0 to n-1 and skips 'v', which violates the requirement.]
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0]; // @@ [Again, modifying loop variable 'ii' inside the BFS breaks the outer loop and leads to incorrect traversal.]
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
 void DF(int v) // @@ [Function is named 'DF' but should be 'DFS' to match declaration and standard naming; however, even if renamed, the logic still has issues like not enforcing start from vertex 0.]
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
                DF(Ga[v][i]); // @@ [Recursive call uses 'DF', which is consistent here, but the function name mismatch with declaration causes linker error.]
        }
    }
}