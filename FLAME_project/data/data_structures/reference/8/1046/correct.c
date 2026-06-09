#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
void dfs(int i, int point);
int flag[1000], dui[1000], front, end, t[1000][1000];
int main()
{
    int i, j, n, point, x, y, del;
    scanf("%d %d", &point, &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        t[x][y] = 1;
        t[y][x] = 1;
    }
    scanf("%d", &del);
    for (i = 0; i < point; i++)
    {
        if (flag[i] == 0)
        {
            dfs(i, point);
        }
    }
    printf("\n");
    end = -1;
    for (i = 0; i < point; i++)
        flag[i] = 0;
    flag[0] = 1;
    dui[0] = 0;
    end = 0; // 0点入队
    for (front = 0; front <= end; front++)
    {
        printf("%d ", dui[front]);  //输出队头
        for (j = 0; j < point; j++) //队头的邻接表中没访问过的入队
            if (flag[j] == 0 && t[dui[front]][j] == 1)
            {
                dui[++end] = j;
                flag[j] = 1;
            }
    }
    printf("\n");
    for (i = 0; i < point; i++)
    {
        flag[i] = 0;
        t[del][i] = 0;
        t[i][del] = 0;
    }
    flag[del]=1;
    for (i = 0; i < point; i++)
    {
        if (flag[i] == 0)
        {
            dfs(i, point);
        }
    }
    printf("\n");
    for (i = 0; i < point; i++)
    {
        flag[i] = 0;
        dui[i] = 0;
    }
    flag[0] = 1;
    end = 0;
    for (front = 0; front <= end; front++)
    {
        printf("%d ", dui[front]);
        for (j = 0; j < point; j++) //队头的邻接表中没访问过的入队
            if (flag[j] == 0 && t[dui[front]][j] == 1)
            {
                dui[++end] = j;
                flag[j] = 1;
            }
    }
    return 0;
}
void dfs(int i, int point)
{
    int j;
    printf("%d ", i);
    flag[i] = 1;
    for (j = 0; j < point; j++)
        if (flag[j] == 0 && t[i][j] == 1)
            dfs(j, point);
}


