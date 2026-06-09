#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int u, v, CH[102][102], TMP[102], PTMOP[102], flag;
void DOLLL(int p)
{
    if (0 == flag)
    {
        printf("%d", p);
        flag = 1;
    }
    else printf(" %d", p);
    TMP[p] = 1;
    for (int i = 1; i <= u; i++)
    {
        if (CH[p][i] == 1 && TMP[i] == 0)
        {
            DOLLL(i);
        }
    }
}
void COACH(int p)
{
    int t;
    PTMOP[1] = p;
    for (int j = 1, r = 1; j <= r;)
    {
        t = PTMOP[j++];
        if (TMP[t] == 1)
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

        TMP[t] = 1;
        for (int i = 1; i <= u; i++)
        {
            if (CH[t][i] == 1 && TMP[i] == 0)
            {
                PTMOP[++r] = i;
            }
        }
    }
}
int main()
{
    int x, y;
    scanf("%d%d", &u, &v);
    for (int i = 0; i < v; i++)
    {
        scanf("%d%d", &x, &y);
        CH[x][y] = 1;
        CH[y][x] = 1;
    }
    DOLLL(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        TMP[k] = 0;
        flag = 0;
    }
    COACH(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        TMP[k] = 0;
        flag = 0;
    }
    scanf("%d",&x);
    TMP[x] = 1;
    DOLLL(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        TMP[k] = 0;
        flag = 0;
    }
    TMP[x] = 1;
    COACH(0);
    printf("\n");
    for (int k = 0; k < 102; k++)
    {
        TMP[k] = 0;
        flag = 0;
    }
}




