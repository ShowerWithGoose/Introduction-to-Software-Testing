#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define INF 65535
void dfs(int a);
void bfs(int p);

int vertex[100][100] = {0};
int flag = 0, n, l, temp[100], s, tempp[100];

int main()
{
    int i = 0, tmp1, tmp2;
    scanf("%d %d", &n, &l);
    for (i = 0; i < l; i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        vertex[tmp1][tmp2] = 1;
        vertex[tmp2][tmp1] = 1;
    }
    scanf("%d", &s);
    dfs(0);
    printf("\n");
    for (i = 0; i < 100; i++)
    {
        temp[i] = 0;
    }
    flag = 0;
    bfs(0);
    printf("\n");
    for (i = 0; i < 100; i++)
    {
        temp[i] = 0;
    }
    flag = 0;
    temp[s] = 1;
    dfs(0);
    printf("\n");
    for (i = 0; i < 100; i++)
    {
        temp[i] = 0;
    }
    flag = 0;
    temp[s] = 1;
    bfs(0);
    return 0;
}

void dfs(int a)
{
    if (flag == 0)
    {
        printf("%d", a);
        flag = 1;
        temp[a] = 1;
    }
    else
    {
        printf(" %d", a);
        temp[a] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if ((vertex[a][i] == 1) && (temp[i] == 0))
        {
            dfs(i);
        }
    }
}

void bfs(int p)
{
    int t;
    tempp[1] = p;
    for (int j = 1, r = 1; j <= r;)
    {
        t = tempp[j++];
        if (temp[t] == 1)
        {
            continue;
        }
        if (flag == 0)
        {
            printf("%d", t);
            flag = 1;
        }
        else
        {
            printf(" %d", t);
        }

        temp[t] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vertex[t][i] == 1 && temp[i] == 0)
            {
                tempp[++r] = i;
            }
        }
    }
}
