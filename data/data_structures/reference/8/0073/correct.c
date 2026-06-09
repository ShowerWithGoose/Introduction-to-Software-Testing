#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int a[101][101];
int x, y;

int m, n;                       //顶点和边
int visit[150], flag, que[150]; // flag记录是不是第一次打印,visit记录是不是找过了,que是在bfs中要用的队列
void dfs(int p)
{

    if (flag == 1)
    {
        printf(" %d", p);
    }
    if (flag == 0)
    {
        printf("%d", p);
        flag = 1;
    }

    visit[p] = 1;
    int i;
    for (i = 1; i <= m; i++)
    {
        if (a[p][i] == 1) //找下一个和他连着的
        {
            if (visit[i] == 0) //如果这条边还没有被找过那就找
            {

                dfs(i);
            }
        }
    }
}

void bfs(int q)
{
    que[1] = q;

    int l = 1, r = 1, i;
    while (l <= r)
    {
        int num = que[l];
        l++;
        if (visit[num])
            continue;
        if (flag == 0)
        {
            printf("%d", num);
            flag = 1;
        }
        else
            printf(" %d", num);

        visit[num] = 1;
        for (i = 1; i <= m; i++)
            if (a[num][i] == 1) //先把连着的点都入队
            {
                if (visit[i] == 0)
                    que[++r] = i;
            }
    }
    memset(visit, 0, sizeof(visit));
}

int main()
{

    scanf("%d%d", &m, &n);
    int i, j;
    for (i = 1; i <= n; i++)

    {
        scanf("%d%d", &x, &y);
        a[x][y] = 1; //利用矩阵进行存储；
        a[y][x] = 1;
    }
    flag = 0;

    dfs(0);
    printf("\n");
    memset(visit, 0, sizeof(visit)); //清0
    flag = 0;
    bfs(0);
    printf("\n");
    int de;
    scanf("%d", &de);
    visit[de] = 1; //我不看那个被删的了
    flag = 0;
    dfs(0);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    visit[de] = 1;
    flag = 0;
    bfs(0);
    printf("\n");
    return 0;
}
