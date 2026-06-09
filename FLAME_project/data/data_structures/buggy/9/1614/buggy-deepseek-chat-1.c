#include <stdio.h>
#include <stdlib.h>
typedef struct _line
{
    int xf,yf;
    int xb,yb;
}lines,*pline;
lines line[101];
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
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].xf,&line[i].yf,&line[i].xb,&line[i].yb);
    }
    qsort(line,n,sizeof(line[0]),cmp);
    printf("%d\n",n); // @@ Error: This prints the total number of segments (2) instead of the maximum number of segments in the longest continuous line (which should be 2). The problem requires outputting the maximum number of segments in the longest continuous line, not the total count. Additionally, the output format is wrong; it should print the count followed by the starting point coordinates on the same line, not on separate lines.
    for(i=0;i<n;i++)
    {
        printf("%d %d %d %d\n",line[i].xf,line[i].yf,line[i].xb,line[i].yb); // @@ Error: This prints all input segments, but the problem only requires outputting the maximum number of segments and the starting point coordinates. The program should instead find the longest continuous line segment and output its count and starting point.
    }
    return 0;
}