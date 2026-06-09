#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#define ll long long

typedef struct Line
{
    int x0, y0, x1, y1;

} L;
L line[1000];
int flag[1000];
int cmp(const void *p1, const void *p2)
{
    L *a = (L *)p1;
    L *b = (L *)p2;
    if (a->x0 != b->x0)
        return a->x0 - b->x0; //先排横坐标
    return a->y0 - b->y0;
}

int main()
{
    int i, j;
    int x,y;
    int linenum;
    scanf("%d", &linenum);

    for (i = 0; i < linenum; i++)
        scanf("%d%d%d%d", &line[i].x0, &line[i].y0, &line[i].x1, &line[i].y1);

    qsort(line, linenum, sizeof(L), cmp); //排序坐标
    int len, maxlen = -1;
    for (i = 0; i < linenum; i++)
    {
        len = 1;
        for(j=0;j<linenum;j++)
        {
            if((i!=j) && (line[i].x1 == line[j].x0) && (line[i].y1 == line[j].y0) && (flag[j] == 0))
            {
                line[i].x1 = line[j].x1;
                line[i].y1 = line[j].y1;
                flag[j] = 1;
                len++;
            }
        }
        if(len >= maxlen)
        {
            maxlen = len;
            x = line[i].x0;
            y = line[i].y0;
        }
    }
    printf("%d %d %d",maxlen,x,y);
    return 0;
}
