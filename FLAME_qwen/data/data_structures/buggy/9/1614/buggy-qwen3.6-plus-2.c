#include <stdio.h>
#include <stdlib.h>
typedef struct _line
{
    int xf,yf;
    int xb,yb;
}lines,*pline;
lines line[101]; // @@ Array size 101 may be insufficient if the number of segments exceeds 100, reference program uses 200.
int cmp(const void* p1,const void*p2)
{
    int ans;
    pline line1=(pline)p1;
    pline line2=(pline)p2;
    ans=line1->xf-line2->xf;
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i; // @@ In C89/C90 standards, variable declarations must be at the beginning of the block, which may cause a compilation error.
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].xf,&line[i].yf,&line[i].xb,&line[i].yb);
    }
    qsort(line,n,sizeof(line[0]),cmp);
    printf("%d\n",n); // @@ Incorrectly prints the total number of segments instead of calculating and printing the maximum number of segments in a continuous line.
    for(i=0;i<n;i++) // @@ Missing the core logic to find the longest continuous line segment; this loop incorrectly iterates to print all segments.
    {
        printf("%d %d %d %d\n",line[i].xf,line[i].yf,line[i].xb,line[i].yb); // @@ Incorrectly prints all segment coordinates instead of the starting point (x, y) of the longest continuous line.
    }
    return 0;
}