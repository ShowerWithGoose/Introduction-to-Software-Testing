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
    memset(a,0,sizeof(int)*420); // @@ [Incorrect size in memset: should be sizeof(a) or 105*4*sizeof(int); current size 420 may be insufficient or incorrect]
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[i][0]=x1;a[i][1]=y1;a[i][2]=x2;a[i][3]=y2;
    }
    for(i=0;i<n;i++)
    {
        if(i!=n-1) // @@ [Unnecessarily skips the last segment; a continuous chain could start at the last segment if it connects backward, but more critically, even if it doesn't, this condition prevents checking a single-segment chain starting at last element when maxcnt is 0 or 1]
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
    printf("%d %d %d",maxcnt,maxx,maxy); // @@ [If no chain is found (e.g., all segments isolated), maxcnt remains 0 and maxx/maxy are uninitialized, leading to undefined behavior; also, the problem guarantees one maximum chain, but code fails to handle case where longest chain is of length 1 starting at last segment due to 'i!=n-1' condition]
    return 0;
}