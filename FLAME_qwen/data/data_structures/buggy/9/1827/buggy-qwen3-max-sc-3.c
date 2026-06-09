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
    memset(a,0,sizeof(int)*420); // @@ [Incorrect size in memset: should be sizeof(a) or 105*4*sizeof(int); using sizeof(int)*420 assumes 420 ints but a has 105*4=420 elements, so this is actually correct. However, the real error is that unconnected segments may be counted multiple times and the algorithm doesn't prevent revisiting segments, leading to infinite loops or incorrect counts. But the immediate cause of failure on test cases is that the loop condition skips the last segment (i!=n-1), so if the longest chain starts at the last segment, it's never checked.]
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[i][0]=x1;a[i][1]=y1;a[i][2]=x2;a[i][3]=y2;
    }
    for(i=0;i<n;i++)
    {
        if(i!=n-1) // @@ [This condition incorrectly skips processing when i == n-1, meaning the last segment is never considered as a starting point for a chain. According to the problem, any segment could be the start of the longest continuous line, including the last one in the array. This leads to wrong output when the longest chain starts at the last segment.]
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