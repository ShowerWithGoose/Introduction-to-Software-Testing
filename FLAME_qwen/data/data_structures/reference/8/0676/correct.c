#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a, b, str[102][102], temp[102], tempp[102], flag;
void dfs(int p);
void bfs(int p);

int main()
{
    int x, y;
    int i=0,k=0;
    scanf("%d%d", &a, &b);
    for (i = 1; i <= b; i++) 
    {
        scanf("%d%d", &x, &y);
        str[x][y] = 1;
        str[y][x] = 1;
    }
    dfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    bfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    scanf("%d",&x);
    temp[x] = 1;
    dfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    temp[x] = 1;
    bfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
}

void dfs(int p)
{
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
    int i=0;
    for (i = 1; i <= a; i++)
    {
        if (str[p][i] == 1 && temp[i] == 0)
        {
            dfs(i);
        }
    }
}

void bfs(int p)
{
    int t;
    tempp[1] = p;
    int i=0,j=0,r=0;
    for (j = 1, r = 1; j <= r;)
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
        for (i = 1; i <= a; i++)
        {
            if (str[t][i] == 1 && temp[i] == 0)
            {
                tempp[++r] = i;
            }
        }
    }
}


