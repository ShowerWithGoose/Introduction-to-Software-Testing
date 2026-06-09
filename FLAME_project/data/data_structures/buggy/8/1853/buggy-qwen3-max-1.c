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
                DF(ii); // @@ [The traversal should always start from vertex 0, but this loop starts from ii=0 and skips v, which may not start from 0 if v==0 (but v!=0 per problem), however more critically, it runs DFS on every unvisited node, not just starting from 0. The problem requires traversal to start from vertex 0 only.]
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
                        printf("%d ", v); // @@ [This prints the deleted vertex 'v' at the start of BFS, which is wrong. Also, traversal must start from vertex 0, not from arbitrary 'ii'. Additionally, it should not print 'v' because v is excluded in the "before deletion" traversal? No — actually this block is supposed to be BEFORE deletion, so v should be included, but the logic is flawed: it's looping over all vertices except v and doing BFS on each component, but graph is connected and must start from 0. This entire BFS implementation is incorrect.]
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0]; // @@ [Reusing loop variable 'ii' inside the BFS loop corrupts the outer loop control variable, leading to undefined behavior and incorrect traversal.]
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
        Ga[i][j] = 1000; // @@ [Here, 'i' is used instead of 'v'. After the previous loop, 'i' equals 'vern', so this writes out of bounds and fails to clear Ga[v]. Should be Ga[v][j] = 1000;]
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
                DF(ii); // @@ [Same error as before: should start DFS only from vertex 0, not from every unvisited node. After deletion, graph is still connected and must start from 0.]
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
                        printf("0 "); // @@ [Hardcoded "0 " is printed regardless of actual start. But more importantly, traversal should start from 0 only once. This loop structure is fundamentally wrong — it attempts BFS on every unvisited node, but should only start from 0. Also, if ii != 0, this prints "0 " incorrectly.]
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0]; // @@ [Again, reusing 'ii' corrupts the outer loop variable.]
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