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
    printf("%d\n",n); // @@ [This outputs the total number of segments instead of the maximum chain length; also, the problem requires outputting the max chain length and the starting point coordinates, not all segments.]
    for(i=0;i<n;i++)
    {
        printf("%d %d %d %d\n",line[i].xf,line[i].yf,line[i].xb,line[i].yb); // @@ [This prints all segments after sorting, which is not what the problem asks for. The program should find the longest continuous chain and output only its length and starting point.]
    }
    return 0;
}