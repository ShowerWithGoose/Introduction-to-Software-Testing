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
                DF(ii); // @@ [Function 'DF' is used but the intended function name per problem and reference is 'DFS'; however, a function named 'DF' is defined later, so this is not a compilation error. But note: traversal must start from vertex 0, yet this loop starts from ii=0 and skips only 'v', which may not guarantee starting at 0 if 0 is not the first unvisited node. However, since 0 is never deleted (per problem), and loop starts at 0, it's okay. The real issue is in BFS part.]
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
                        printf("%d ", v); // @@ [This prints the deleted vertex 'v' instead of the current starting vertex 'ii'. Also, traversal should start from vertex 0, but this loop may start BFS from any unvisited non-deleted vertex. Since the graph is connected and 0 is not deleted, the first unvisited is 0, but printing 'v' here is wrong. It should print 'ii'. Moreover, this breaks the requirement to start from 0.]
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0]; // @@ [Reusing loop variable 'ii' as the current vertex in BFS corrupts the outer loop variable, causing undefined behavior and incorrect traversal. This will lead to skipping vertices or infinite loops.]
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
        Ga[i][j] = 1000; // @@ [Here, 'i' is used after the loop where 'i' reached 'vern', so Ga[i][j] accesses out-of-bounds memory (Ga[vern][j]), which is undefined behavior. It should be Ga[v][j] = 1000; but note that the row for vertex 'v' doesn't need to be cleared because during traversal we skip vertex 'v' anyway. However, the main issue is using 'i' instead of 'v'.]
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
                DF(ii); // @@ [Same as earlier: should start from 0, and since 0 is not deleted, the first call should be with 0. However, because the loop starts at 0 and 0 != v, it will call DF(0) first, which is correct. So this line is actually okay. The real errors are elsewhere.]
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
                        printf("0 "); // @@ [Hardcoding "0 " is incorrect. It should print the current vertex 'ii'. Since traversal must start from 0 and 0 is not deleted, the first 'ii' is 0, but printing "0 " regardless of 'ii' is wrong if by chance the BFS started elsewhere (though it shouldn't). More critically, if the graph after deletion is still connected and starts at 0, then only when ii==0 should it print 0. But this prints "0 " even if ii is not 0, which is wrong. Also, reusing 'ii' in the inner loop below causes corruption.]
    Visited[ii] = 1;
    for (jj = 0; Q[jj] != -1; jj++);
    Q[jj] = ii;
    while (Q[0] != -1)
    {
        ii = Q[0]; // @@ [Again, reusing loop variable 'ii' corrupts the outer for-loop, leading to incorrect iteration and potential crashes or wrong output.]
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