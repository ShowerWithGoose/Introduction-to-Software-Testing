#include <stdio.h>
#include <stdlib.h>
struct line_main
{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};
int main()
{
    int n, i, j,k, max=1,maxx=0,maxy=0;
    struct line_main seg_main[105];
    struct line seg[105];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d%d",&seg_main[i].x1,&seg_main[i].y1,&seg_main[i].x2,&seg_main[i].y2);
        seg[i].num = 1;
    }
    for (i = 0; i < n; i++)
    {
        for(k=0;k<n;k++)
        {
        seg[k].x1=seg_main[k].x1;
        seg[k].x2=seg_main[k].x2;
        seg[k].y1=seg_main[k].y1;
        seg[k].y2=seg_main[k].y2;
        }
        j=0;
        while (j!=n)
        {
            if (seg[i].x2 == seg[j].x1 && seg[i].y2 == seg[j].y1)
            {
                seg[i].x2 = seg[j].x2;
                seg[i].y2 = seg[j].y2;
                seg[i].num++;
                j = 0;
            }
            else
                j++;
        }
        if (max < seg[i].num)
        {
            max = seg[i].num;
            maxx=seg[i].x1;
            maxy=seg[i].y1;
        }
    }
    printf("%d %d %d\n",max,maxx,maxy);
    return 0;
}

