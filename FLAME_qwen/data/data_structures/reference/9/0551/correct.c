#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
struct lines
{
    int x1;
    int x2;
    int y1;
    int y2;
    struct lines *next;
    int cnt;
} line[105], *p;
int n, i, j, max = 0, maxi;
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
        line[i].cnt = 1;
        line[i].next = NULL;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (line[i].x2 == line[j].x1 && line[i].y2 == line[j].y1)
            {
                line[i].next = &line[j];
                break;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        p = &line[i];
        while (p->next != NULL)
        {
            p = p->next;
            line[i].cnt++;
        }
        if (line[i].cnt > max)
        {
            max = line[i].cnt;
            maxi = i;
        }
    }
    printf("%d %d %d", max, line[maxi].x1, line[maxi].y1);
    return 0;
}

