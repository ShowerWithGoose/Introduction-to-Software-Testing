#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a, b, gragh[105][105], complete[105], tem[105], flag;
void DFS(int p);
void BFS(int p);

int main()
{
    int x, y;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= b; i++)
    {
        scanf(" %d%d", &x, &y);
        gragh[x][y] = 1;
        gragh[y][x] = 1;
    }
    scanf("%d",&x);
    DFS(0);
    printf("\n");
    for (int i=0;i<105;i++)
    {
        complete[i] = 0;
        flag = 0;
    }
    BFS(0);
    printf("\n");
    for (int i=0;i<105;i++)
    {
        complete[i] = 0;
        flag = 0;
    }
    complete[x] = 1;
    DFS(0);
    printf("\n");
    for (int i=0;i<105;i++)
    {
        complete[i] = 0;
        flag = 0;
    }
    complete[x] = 1;
    BFS(0);
    printf("\n");
    for (int i=0;i<105;i++)
    {
        complete[i] = 0;
        flag = 0;
    }
    return 0;
}

void DFS(int p)
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
    complete[p] = 1;
    for (int i = 1; i <= a; i++)
    {
        if (gragh[p][i] == 1 && complete[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int p)
{
    int t;
    tem[1] = p;
    for (int j = 1, r = 1; j <= r;)
    {
        t = tem[j++];
        if (complete[t] == 1)
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

        complete[t] = 1;
        for (int i = 1; i <= a; i++)
        {
            if (gragh[t][i] == 1 && complete[i] == 0)
            {
                tem[++r] = i;
            }
        }
    }
}

