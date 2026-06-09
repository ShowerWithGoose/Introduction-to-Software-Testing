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
    memset(a,0,sizeof(int)*420); // @@ [Incorrect size in memset: should be sizeof(a) or 105*4*sizeof(int). Using sizeof(int)*420 assumes 420 ints, but a has 105*4=420 elements, so this is actually correct. However, the real issue is logic: the program only checks chains starting from segment i and following forward, but doesn't consider that a chain might start earlier. Also, it skips the last segment (i!=n-1), which could be part of the longest chain as a continuation, but more critically, if the longest chain starts at the last segment (length 1), it will be ignored. This causes wrong output when the maximum chain is of length 1 and starts at the last segment.]
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[i][0]=x1;a[i][1]=y1;a[i][2]=x2;a[i][3]=y2;
    }
    for(i=0;i<n;i++)
    {
        if(i!=n-1) // @@ [This condition incorrectly excludes the last segment (i = n-1) from being considered as the start of a chain. Even if a segment cannot be extended (chain length 1), it should still be considered, especially since the problem states there is only one continuous line segment with maximum segments, and it might be of length 1. Excluding i = n-1 can lead to maxcnt remaining 0 if all chains are length 1 and the last segment is the only one (or part of the max), but more generally, any segment should be allowed as a start.]
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
    printf("%d %d %d",maxcnt,maxx,maxy);
    return 0;
}