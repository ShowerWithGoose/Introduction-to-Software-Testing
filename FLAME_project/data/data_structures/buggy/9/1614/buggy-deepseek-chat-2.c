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
    printf("%d\n",n); // @@ This line incorrectly prints the total number of segments n instead of the maximum number of segments in the longest continuous line. It also adds a newline, which does not match the expected output format.
    for(i=0;i<n;i++)
    {
        printf("%d %d %d %d\n",line[i].xf,line[i].yf,line[i].xb,line[i].yb); // @@ This line prints all input segments instead of the required output: the maximum segment count and the starting point coordinates. The program completely lacks the logic to find continuous line segments and compute the required result.
    }
    return 0;
}