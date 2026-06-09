#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_v, num_e, num_del;
int del[105], check_search[105], queue[100005];

typedef struct edge
{
    int adjvex;
    struct edge *next;
} Elink;

typedef struct ver
{
    Elink *link;
} Vlink;

Vlink g[105];

void createG(int x, int y)
{
    Elink *p = malloc(sizeof (Elink)), *head;
    p->adjvex = y;
    p->next = NULL;
    head = g[x].link;
    if (head == NULL) g[x].link = p;
    else if (head->adjvex > y)
    {
        g[x].link = p;
        p->next = head;
    }
    else
    {
        while (1)
        {
            if (head->next == NULL)
            {
                head->next = p;
                break;
            }
            else if (head->next->adjvex > y)
            {
                p->next = head->next;
                head->next = p;
                break;
            }
            else head = head->next;
        }
    }
    p = malloc(sizeof (Elink));
    p->adjvex = x;
    p->next = NULL;
    head = g[y].link;
    if (head == NULL) g[y].link = p;
    else if (head->adjvex > x)
    {
        g[y].link = p;
        p->next = head;
    }
    else
    {
        while (1)
        {
            if (head->next == NULL)
            {
                head->next = p;
                break;
            }
            else if (head->next->adjvex > x)
            {
                p->next = head->next;
                head->next = p;
                break;
            }
            else head = head->next;
        }
    }
}

void dfs(int s)
{
    check_search[s] = 1;
    printf("%d ", s);
    Elink *head = g[s].link;
    while (head != NULL)
    {
        if (!check_search[head->adjvex] && !del[head->adjvex]) dfs(head->adjvex);
        head = head->next;
    }
}

void bfs(int s)
{
    Elink *p;
    int head = 0, tail = 0;
    queue[tail ++ ] = s;
    check_search[s] = 1;
    while (tail - head > 0)
    {
        int tmp = queue[head];
        printf("%d ", tmp);
        head ++;
        p = g[tmp].link;
        while (p != NULL)
        {
            if (!check_search[p->adjvex] && !del[p->adjvex])
            {
                check_search[p->adjvex] = 1;
                queue[tail ++ ] = p->adjvex;
            }
            p = p->next;
        }
    }
}

int main()
{
    scanf("%d%d", &num_v, &num_e);
    for (int i = 0; i < num_v; i ++ ) g[i].link = NULL;
    for (int i = 1; i <= num_e; i ++ )
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        createG(v1, v2);
    }
    scanf("%d", &num_del);
    dfs(0);
    puts("");
    memset(check_search, 0, sizeof check_search);
    bfs(0);
    puts("");
    memset(check_search, 0, sizeof check_search);
    del[num_del] = 1;
    dfs(0);
    puts("");
    memset(check_search, 0, sizeof check_search);
    bfs(0);
    puts("");
    return 0;
}


