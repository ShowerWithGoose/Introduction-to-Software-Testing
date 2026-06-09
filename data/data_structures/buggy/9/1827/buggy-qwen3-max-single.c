#include <stdio.h>
#include <string.h>
int f(int x2,int y2,int a[][4],int n)
{
    int i; 
    for(i=0;i<n;i++)
    {
        if(x2==a[i][0]&&y2==a[i][1])
            return i;
    }
    return -1;
} 
int main()
{
    int n,x1,x2,y1,y2,i,j,a[105][4],cnt=0,maxcnt=0,maxx,maxy;
    scanf("%d",&n);
    memset(a,0,sizeof(int)*420); // @@ [Incorrect size in memset: should be sizeof(a) or 105*4*sizeof(int); using sizeof(int)*420 assumes 420 ints but a has 105*4=420 elements, so this is actually correct. However, the real error is that unconnected segments may be counted incorrectly due to not resetting properly and missing chains that don't start at earliest segment. But the compilation error mentioned is misleading—actual issue is logical. However, based on test failure and problem constraints, the core error is that the loop skips the last segment (i!=n-1), so if the longest chain starts at the last segment (which is a single segment), it won't be considered. Since maxcnt starts at 0, and if all chains are length 1, maxcnt remains 0, leading to undefined maxx/maxy.]
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[i][0]=x1;a[i][1]=y1;a[i][2]=x2;a[i][3]=y2;
    }
    for(i=0;i<n;i++)
    {
        if(i!=n-1) // @@ [This condition incorrectly excludes the last segment from being the start of a chain. Even a single-segment chain starting at the last segment should be considered, especially when it's the only segment or part of the maximum (which could be 1). This causes maxcnt to remain 0 if all segments are isolated, leading to printing uninitialized maxx/maxy or wrong result.]
        {
            cnt=1;
            j=f(a[i][2],a[i][3],a,n);
            while(j!=-1)
            {
                cnt++;
                j=f(a[j][2],a[j][3],a,n);
            }
            if(cnt>maxcnt)
            {
                maxcnt=cnt;
                maxx=a[i][0];
                maxy=a[i][1];
            }
        }
    }
    printf("%d %d %d",maxcnt,maxx,maxy); // @@ [If no chain was found (e.g., all segments isolated and loop skipped last segment), maxcnt remains 0 and maxx/maxy are uninitialized, leading to undefined behavior or wrong output. The problem states there is always one continuous line with maximum segments, but even a single segment is valid. The loop must consider all i from 0 to n-1.]
    return 0;
}