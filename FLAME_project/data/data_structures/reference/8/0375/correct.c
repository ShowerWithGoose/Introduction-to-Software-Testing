#include <stdio.h>
#include <stdlib.h>
int a, b, str[102][102], temp[102], temp2[102], flag;
void Dfs(int p)
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
    int i;
    for (i = 1; i <= a; i++)
    {
        if (str[p][i] == 1 && temp[i] == 0)
        {
            Dfs(i);
        }
    }
}
void Bfs(int p)
{
    int t;
    temp2[1] = p;
    int j;
    int r;
    for (j = 1, r = 1; j <= r;)
    {
        t = temp2[j++];
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
        int i;
        for (i = 1; i <= a; i++)
        {
            if (str[t][i] == 1 && temp[i] == 0)
            {
                temp2[++r] = i;
            }
        }
    }
}

int main()
{
    int x, y;
    scanf("%d%d", &a, &b);
    int i;
    for ( i = 1; i <= b; i++) 
    {
        scanf("%d%d", &x, &y);
        str[x][y] = 1;
        str[y][x] = 1;
    }
    Dfs(0);
    printf("\n");
    int k;
    for ( k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    Bfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    scanf("%d",&x);
    temp[x] = 1;
    Dfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
    temp[x] = 1;
    Bfs(0);
    printf("\n");
    for (k = 0; k < 102; k++)
    {
        temp[k] = 0;
        flag = 0;
    }
}






