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
    printf("%d\n",n); // @@ [This line prints the total number of segments instead of the maximum chain length and starting point as required by the problem. The entire logic to find the longest continuous line segment is missing.]
    for(i=0;i<n;i++)
    {
        printf("%d %d %d %d\n",line[i].xf,line[i].yf,line[i].xb,line[i].yb); // @@ [This loop prints all segments after sorting, which is not part of the expected output format. The problem requires only the maximum number of segments in the longest continuous line and its starting point.]
    }
    return 0;
}