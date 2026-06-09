#include<stdio.h>
struct index{
    int count;
    int xstart;
    int ystart;
    int xend;
    int yend;
}a[100];
int main()
{
    int n;
    scanf("%d", &n);
    int i, x1, y1, x2, y2;
    int j = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int i1;
        for(i1 = 0; i1 < j; i1++)
        {
            if(x1 == a[i1].xend && y1 == a[i1].yend)    //add at last
            {
                a[i1].count++;
                a[i1].xend = x2;
                a[i1].yend = y2;
                break;
            }
            else if(x2 == a[i1].xstart && y2 == a[i1].ystart)   //add at first
            {
                a[i1].count++;
                a[i1].xstart = x1;
                a[i1].ystart = y1;
                break;
            }
        }
        if(i1 == j) //create a new line
        {
            a[i1].count = 1;
            a[i1].xstart = x1;
            a[i1].ystart = y1;
            a[i1].xend = x2;
            a[i1].yend = y2;
            j++;
        }
    }
    /* integrate all line together */
    int i2, i3;
    for(i2 = 0; i2 < j; i2++)
    {
        for(i3 = 0; i3 < j; i3++)
        {
            for(i = i3 + 1; i < j; i++)
            {
                if(a[i].count == 0)
                    continue;
                if(a[i].xstart == a[i3].xend && a[i].ystart == a[i3].yend)  //add i to i3 at end
                {
                    a[i3].count += a[i].count;
                    a[i3].xend = a[i].xend;
                    a[i3].yend = a[i].yend;
                    a[i].count = 0;
                }
                else if(a[i].xend == a[i3].xstart && a[i].yend == a[i3].ystart)  //add i to i3 at first
                {
                    a[i3].count += a[i].count;
                    a[i3].xstart = a[i].xstart;
                    a[i3].ystart = a[i].ystart;
                    a[i].count = 0;
                }
            }
        }
    }
    int max = 0, imax = 0;
    for(i = 0; i < j; i++)
    {
        if(a[i].count >= max)
        {
            max = a[i].count;
            imax = i;
        }
    }
    printf("%d %d %d\n", a[imax].count, a[imax].xstart, a[imax].ystart);
    return 0;
}
