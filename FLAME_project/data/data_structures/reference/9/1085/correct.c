#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define check(VAR, CONV) printf("check:" #VAR "=%" #CONV "\n", VAR)
typedef long long ll;
typedef double db;
typedef struct segment_
{
    int position;
    int x1, x2, y1, y2;
    struct segment_ *next;
} segment;

int main(void)
{
    int i, j, n, t, maxlen = 0, len, maxx, maxy;
    segment segs[1919], segtemp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &(segs[i].x1), &(segs[i].y1), &(segs[i].x2), &(segs[i].y2));
        segs[i].position = 1;
        segs[i].next = NULL;
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (segs[i].x1 == segs[j].x2 && segs[i].y1 == segs[j].y2)
            {
                segs[j].next = &(segs[i]);
                segs[i].position = 0;
            }
            if (segs[j].x1 == segs[i].x2 && segs[j].y1 == segs[i].y2)
            {
                segs[i].next = &(segs[j]);
                segs[j].position = 0;
            }
        }
    for (t = 0; t < n; t++)
    {
        if (segs[t].position)
        {
            len = 1;
            segtemp = segs[t];
            while (segtemp.next != NULL)
            {
                segtemp = *(segtemp.next);
                len++;
            }
            if (len > maxlen)
            {
                maxlen = len;
                maxx = segs[t].x1;
                maxy = segs[t].y1;
            }
        }
    }
    printf("%d %d %d", maxlen, maxx, maxy);

    return 0;
}
