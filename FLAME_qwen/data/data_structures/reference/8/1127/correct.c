#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a, b, s[102][102], temp[102], hold[102], flag;
void Dfs(int p);
void Bfs(int p);

int main()
{
    int x, y,i,j,k;
    scanf("%d%d", &a, &b);
    for (i = 1; i <= b; i++) //建立邻接表
    {
        scanf("%d%d", &x, &y);
        s[x][y] = 1;
        s[y][x] = 1;
    }
    Dfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    Bfs(0);
    printf("\n");
    for ( k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    scanf("%d",&x);
    temp[x] = 1;
    Dfs(0);
    printf("\n");
    for ( k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    temp[x] = 1;
    Bfs(0);
    printf("\n");
    for ( k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
}

void Dfs(int p)
{int i,j,k,r;
    if (flag == 0)
    {
        printf("%d", p);
        flag = 1;
    }
    else
    {
        printf(" %d", p);
    }
    temp[p] = 1;
    for (i = 1; i <= a; i++)
    {
        if (s[p][i] == 1 && temp[i] == 0)
        {
            Dfs(i);
        }
    }
}

void Bfs(int p)
{int i,j,k;
    int t,r;
    hold[1] = p;
    for ( j = 1, r = 1; j <= r;)
    {
        t = hold[j++];
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
        for ( i = 1; i <= a; i++)
        {
            if (s[t][i] == 1 && temp[i] == 0)
            {
                hold[++r] = i;
            }
        }
    }
}




