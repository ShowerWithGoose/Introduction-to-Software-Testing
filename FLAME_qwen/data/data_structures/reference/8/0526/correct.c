#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a, b, str[102][102], temp[102], tempp[102], flag;
void Dfs(int p);
void Bfs(int p);

int main()
{
    int x, y;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= b; i++)
    {
        scanf("%d%d", &x, &y);
        str[x][y] = 1;
        str[y][x] = 1;
    }
    Dfs(0);
    printf("\n");
    f5();
    Bfs(0);
    printf("\n");
    f5();
    scanf("%d",&x);
    for(int i=0;i<a;i++)
    {
        str[x][i]=0;
        str[i][x]=0;
    }
    Dfs(0);
    printf("\n");
    f5();
    Bfs(0);
    printf("\n");
}

void Dfs(int p)//深度优先遍历
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
    for (int i = 1; i <= a; i++)
    {
        if (str[p][i] == 1 && temp[i] == 0)
        {
            Dfs(i);
        }
    }
}

void Bfs(int p)//广度优先遍历
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
        for (int i = 1; i <= a; i++)
        {
            if (str[t][i] == 1 && temp[i] == 0)
            {
                tempp[++r] = i;
            }
        }
    }
}

void f5()
{
    flag=0;
    memset(temp,0,sizeof(temp));
}

