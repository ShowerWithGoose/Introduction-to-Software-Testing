#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct _graph
{
    int point;
    struct _graph *link;
} g, *pg;

pg graph[101] = {NULL};
int mark[101] = {0};
int mark0[101] = {0};
void add_path(int b, int a)
{
    pg p = graph[b], q = NULL, r = p;
    q = malloc(sizeof(g));
    q->point = a;
    if (p != NULL)
    {
        while (p != NULL && p->point < a)
        {
            r = p;
            p = p->link;
        }
        if (p != r)
        {
            q->link = p;
            r->link = q;
        }
        else
        {
            graph[b] = q;
            q->link = p;
        }
    }
    else
    {
        graph[b] = q;
        q->link = NULL;
    }
    return;
}

void create(int x, int y)
{
    add_path(x, y);
    add_path(y, x);
    return;
}

void depth_search(int x)
{
    int b;
    if (mark[x] == -1)
        return;
    mark[x] = -1;
    pg p = graph[x];
    while (p != NULL)
    {
        b = p->point;
        if (mark[b] != -1)
        {
            printf(" %d", b);
            depth_search(b);
        }
        p = p->link;
    }
    return;
}

void print_point(int x)
{
    int b;
    pg p = graph[x];
    while (p != NULL)
    {
        b = p->point;
        if (mark[b] != -2)
        {
            printf(" %d", b);
            mark[b] = -2;
        }
        p = p->link;
    }
}

void width_search(int x)
{
    pg p;
    int queue[101] = {0};
    int left = 0, right = 1, b;
    mark0[x] = -1;
    while (left != right)
    {
        print_point(queue[left]);
        p = graph[queue[left]];
        while (p != NULL)
        {
            b = p->point;
            if (mark0[b] != -1)
            {
                queue[right] = b;
                right++;
                mark0[b] = -1;
            }
            p = p->link;
        }
        left++;
    }
}

void delete(int x)
{
    int b;
    pg p = graph[x], q, r;
    while (p != NULL)
    {
        b = p->point;
        q = graph[b];
        r = q;
        while (q->point != x)
        {
            r = q;
            q = q->link;
        }
        if (r == q)
        {
            graph[b] = r->link;
            free(r);
        }
        else
        {
            r->link = q->link;
            free(q);
        }

        p = p->link;
    }

    p = graph[x];
    while (p != NULL)
    {
        r = p->link;
        free(p);
        p = r;
    }
    graph[x] = NULL;
}

int main()
{
    int points, path;
    int i;
    int x, y;
    scanf("%d%d", &points, &path);
    i = path;
    while (i--)
    {
        scanf("%d%d", &x, &y);
        create(x, y);
    }
    scanf("%d", &x);
    printf("0");
    for (i = 0; i < points; i++)
    {
        depth_search(i);
    }
    printf("\n0");
    mark[0] = -2;
    for (i = 0; i < points; i++)
    {
        width_search(i);
    }
    printf("\n0");
    for (i = 0; i < points; i++)
    {
        mark[i] = 0;
        mark0[i] = 0;
    }

    delete (x);

    for (i = 0; i < points; i++)
    {
        depth_search(i);
    }
    printf("\n0");
    mark[0] = -2;
    for (i = 0; i < points; i++)
    {
        width_search(i);
    }

    return 0;
}

/*
-----
3 3
0 1
1 2
0 2
1

0 1 2
0 1 2
0 2
0 2
-----
4 6
0 3
0 2
3 2
2 1
0 1
3 1
2

0 1 2 3
0 1 2 3
0 1 3
0 1 3
-----
9 9
0 1
1 2
2 3
3 4
2 6
0 5
5 6
6 7
7 8
1

0 1 2 3 4 6 5 7 8
0 1 5 2 6 3 7 4 8
0 5 6 2 3 4 7 8
0 5 6 2 7 3 8 4
-----
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

0 1 3 6 8 4 2 5 7
0 1 2 3 4 8 5 7 6
0 1 4 8 6 2 5 7
0 1 2 4 8 5 7 6
*/
