#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef struct Line
{
    int begin[2];
    int end[2];
    int length;
} line;
int main()
{
    int count, max = 1, n = 0;
    line a[105];
    scanf("%d", &count);
    for (int i = 1; i <= count; i++)
    {
        scanf("%d", &a[i].begin[0]);
        scanf("%d", &a[i].begin[1]);
        scanf("%d", &a[i].end[0]);
        scanf("%d", &a[i].end[1]);
        a[i].length = 1;
    }
    for (int i = 1; i < count; i++)
    {
        if (a[i].length == 0)
        {
            continue;
        }
        for (int j = i + 1; j <= count; j++)
        {
            if (a[j].length == 0)
            {
                continue;
            }
            if (a[i].end[0] == a[j].begin[0] && a[i].end[1] == a[j].begin[1])
            {
                a[j].length += a[i].length;
                a[i].length = 0;
                a[j].begin[0] = a[i].begin[0];
                a[j].begin[1] = a[i].begin[1];
                break;
            }
            if (a[i].begin[0] == a[j].end[0] && a[i].begin[1] == a[j].end[1])
            {
                a[j].length += a[i].length;
                a[i].length = 0;
                a[j].end[0] = a[i].end[0];
                a[j].end[1] = a[i].end[1];
                break;
            }
        }
    }
    for (int i = 1; i <= count; i++)
    {
        if (a[i].length == 0)
        {
            continue;
        }
        if (a[i].length > max)
        {
            max = a[i].length;
            n = i;
        }
    }
    printf("%d %d %d\n", max, a[n].begin[0], a[n].begin[1]);
    return 0;
}
