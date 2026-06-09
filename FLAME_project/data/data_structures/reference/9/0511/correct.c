#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct line *next;
} node;

int main()
{
    int n, i, j;
    scanf("%d", &n);
    node head[100];
    memset(head, 0, sizeof(head));
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &head[i].x1, &head[i].y1, &head[i].x2, &head[i].y2);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (head[i].x1 == head[j].x2 && head[i].y1 == head[j].y2)
            {
                head[j].next = &head[i];
            }
            if (head[i].x2 == head[j].x1 && head[i].y2 == head[j].y1)
            {
                head[i].next = &head[j];
            }
        }
    }

    int count = 0, length = 0, x = 0, y = 0;
    node *p;
    for (i = 0; i < n; i++)
    {
        for (p = &head[i]; p->next != NULL; p = p->next)
        {
            count++;
        }
        count++;
        if (i == 0)
        {
            length = count;
            x = head[i].x1, y = head[i].y1;
        }
        else
        {
            if (count > length)
            {
                length = count;
                x = head[i].x1, y = head[i].y1;
            }
        }
        count = 0;
    }

    printf("%d %d %d\n", length, x, y);
}
