#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct Line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
} line[109];
int cmp(const void *a, const void *b)
{
    return (*(struct Line *)a).x1 - (*(struct Line *)b).x1;
}
int main()
{
    // read
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
    }

    // sort
    qsort(line, n, sizeof(line[0]), cmp);
    // calculate

    int count[n];
    for (int i = 0; i < n; i++)
        count[i] = 0;
    int start;
    int i, j;
    for (i = 0; i < n;)
    {
        if (line[i].flag == 0)
        {
            start = i;
            line[i].flag = 1; // note
            for (j = i + 1; j < n;)
            {
                if (line[j].flag == 0)
                {
                    if (line[j].x1 == line[i].x2 && line[j].y1 == line[i].y2)
                    {
                        line[j].flag = 1; // note
                        count[start]++;
                        i = j;
                        j = i + 1;
                    }
                    else
                    j++;
                }
                else
                    j++;
            }
            i = start + 1;
        }
        else
            i++;
    }
    int maxcount = count[0];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (count[i] > maxcount)
        {
            max = i;
            maxcount = count[i];
        }
        /* printf("%d\n",count[i]); */
    }
    printf("%d %d %d", maxcount + 1, line[max].x1, line[max].y1);
    /* printf("%d %d",line[0].x1,line[0].y1); */
    return 0;
}
