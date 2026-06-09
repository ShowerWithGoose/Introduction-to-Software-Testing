#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int A[105][105], vd[105] = {0}, vb[105] = {0};
int point, n, del, flag = 0;
int queue[105], head = 0, rear = 0;

void dfs(int t);
void bfs(int t);

int main()
{
    int a, b;
    scanf("%d%d", &point, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        A[a][b] = 1, A[b][a] = 1;
    }
    scanf("%d", &del);
    dfs(0);
    printf("\n");
    for (int i = 0; i < point; i++)
    {
        vd[i] = 0;
    }
    bfs(0);
    printf("\n");
    for (int i = 0; i < point; i++)
    {
        vb[i] = 0;
    }
    vd[del] = 1, vb[del] = 1;
    dfs(0);
    printf("\n");
    bfs(0);
    system("pause");
    return 0;
}

void dfs(int t)
{
    printf("%d ", t);
    vd[t] = 1;
    for (int i = 0; i < point; i++)
    {
        if (A[t][i] != 0 && vd[i] == 0)
        {
            dfs(i);
        }
    }
}

void bfs(int t)
{
    printf("%d ", t);
    vb[t] = 1;
    queue[0] = t;
    head = 0, rear = 0;
    int i;
    while (head <= rear)
    {
        int num = queue[head++];
        for (i = 0; i < point; i++)
        {
            if (A[num][i] != 0 && vb[i] == 0)
            {
                printf("%d ", i);
                queue[++rear] = i;
                vb[i] = 1;
            }
        }
    }
}
