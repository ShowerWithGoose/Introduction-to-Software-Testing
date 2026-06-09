#include <stdio.h>

#define MAXN 100
int gx[MAXN][MAXN];
int visit[MAXN];
int avi[MAXN];
int Nnode;
int queue[12 * MAXN];
int wei;
int tou;
void DFS(int no)
{
    if (avi[no] && visit[no] == 0)
    {
        printf("%d ", no);
        visit[no]++;
        for (int i = 0; i < Nnode; i++)
        {
            if (gx[no][i] && visit[i] == 0)
            {
                DFS(i);
            }
        }
    }
}

void BFS(int no)
{
    if (visit[no] == 0)
    {
        printf("%d ", no);
        visit[no]++;
        for (int i = 0; i < Nnode; i++)
        {
            if (gx[no][i] && visit[i] == 0 && avi[i])
            {
                queue[wei++] = i;
            }
        }
        if (tou < wei)
        {
            BFS(queue[tou++]);
        }
    }
    else
    {
        if (tou < wei)
        {
            BFS(queue[tou++]);
        }
         
    }
}

int intset(int *tar, int jige, int val)
{
    for (int i = 0; i < jige; i++)
    {
        tar[i] = val;
    }
    return jige;
}

int main()
{
    int Nbian, ina, inb;
    scanf("%d %d", &Nnode, &Nbian);
    for (int i = 0; i < Nnode; i++)
    {
        avi[i] = 1;
    }
    for (int i = 0; i < Nbian; i++)
    {
        scanf("%d %d", &ina, &inb);
        gx[ina][inb] = gx[inb][ina] = 1;
    }
    intset(visit, Nnode, 0);
    DFS(0);
    printf("\n");
    intset(visit, Nnode, 0);
    BFS(0);
    printf("\n");
    int del;
    scanf("%d",&del);
    avi[del]=0;
    intset(visit, Nnode, 0);
    DFS(0);
    printf("\n");
    intset(visit, Nnode, 0);
    BFS(0);
}

