#include <stdio.h>
#include <stdlib.h>
typedef struct n1
{
    struct n1 *next;
    int adjvex;
} elink;
typedef struct n2
{
    elink *link;
    int vertex;
} vlink;
vlink points[1001];
int created[1001];
int visited[1001];
int bfsqueue[1000];
int qfront, qrear = -1;

void DFS(vlink G[], int v)
{
    elink *p;
    visited[v] = 1; //标识某顶点被访问过
    printf("%d ", G[v].vertex);
    for (p = G[v].link; p != NULL; p = p->next)
        if (!visited[p->adjvex])
            DFS(G, p->adjvex);
}
void BFS(vlink G[], int v)
{
    elink *p;
    if (!visited[v])
        printf("%d ", v);
    visited[v] = 1;
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if (!visited[p->adjvex])
        {
            bfsqueue[++qrear] = p->adjvex;
        }
    }
    if (qfront <= qrear)
        BFS(G, bfsqueue[qfront++]);
}
void delPoint(int x)
{
    int flg=0;
    elink *p, *prev, *q;
    p = points[x].link;
    prev = p;
    for (; p != NULL; p = p->next)
    {
        if(flg)
            free(prev);
        q = points[p->adjvex].link;
        prev=q;
        for (; q->adjvex != x; q = q->next)
        {
            prev = q;
        }
        if(prev!=q)
            prev->next = q->next;
        else
            points[p->adjvex].link = q->next;
        free(q);

        prev = p;
        flg=1;
    }
    free(prev);
    created[x]=0;
}
void inGraph(int st, int end)
{
    int sthash = st % 1001, flg = 0;
    elink *current, *prev;
    if (created[sthash] == 0)
    {
        points[sthash].vertex = st;
        // points[sthash].link=NULL;
        created[sthash] = 1;
    }

    if (points[sthash].link == NULL)
    {
        current = (elink *)malloc(sizeof(elink));
        points[sthash].link = current;
        current->next = NULL;
    }
    else
    {
        prev = points[sthash].link;
        if (prev->adjvex > end)
        {
            current = (elink *)malloc(sizeof(elink));
            points[sthash].link = current;
            current->next = prev;
        }
        else
        {
            while (prev->next != NULL)
            {
                if (prev->next->adjvex > end)
                {
                    flg = 1;
                    break;
                }
                prev = prev->next;
            }
            if (flg)
            {
                current = (elink *)malloc(sizeof(elink));
                current->next = prev->next;
                prev->next = current;
            }
            else
            {
                current = (elink *)malloc(sizeof(elink));
                if (prev->next == NULL)
                    current->next = NULL;
                prev->next = current;
            }
        }
    }
    current->adjvex = end;
}
int main()
{
    int pointnum, linenum, tmpstart, tmpend, i, delnum;
    scanf("%d%d", &pointnum, &linenum);
    for (i = 0; i < linenum; i++)
    {
        scanf("%d%d", &tmpstart, &tmpend);
        inGraph(tmpstart, tmpend);
        inGraph(tmpend, tmpstart);
    }
    scanf("%d", &delnum);

    for (i = 0; i < 1001; i++)
    {
        if (created[i] == 0)
            continue;
        else if (!visited[i])
            DFS(points, i);
    }
    for (i = 0; i < 1001; i++)
    {
        visited[i] = 0;
    }

    printf("\n");

    for (i = 0; i < 1001; i++)
    {
        if (created[i] == 1)
        {
            BFS(points, i);
            break;
        }
    }
    for (i = 0; i < 1001; i++)
    {
        visited[i] = 0;
    }
    printf("\n");

    delPoint(delnum);

    for (i = 0; i < 1001; i++)
    {
        if (created[i] == 0)
            continue;
        else if (!visited[i])
            DFS(points, i);
    }
    for (i = 0; i < 1001; i++)
    {
        visited[i] = 0;
    }

    printf("\n");

    for (i = 0; i < 1001; i++)
    {
        if (created[i] == 1)
        {
            BFS(points, i);
            break;
        }
    }
    printf("\n");

    return 0;
}
/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/
