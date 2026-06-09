#include<stdio.h>

int main()
{
    int x1[1000]={};
    int x2[1000]={};
    int y1[1000]={};
    int y2[1000]={};
    int n,i,j,k,count,countmax,x,y,xmax,ymax;
    countmax=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    for(i=0;i<n;i++)
    {
        count=1;
        k=i;
        for(j=0;j<n;j++)
        {
            if(count==1)
            {
                x=x1[k];
                y=y1[k];
            }
            if(x2[k]==x1[j]&&y2[k]==y1[j])
            {
                count++;
                k=j;
                j=0; // @@ The logic for extending the line segment is flawed. It only checks forward connections (end of current to start of next) and resets j to 0, but it doesn't handle backward connections or ensure that segments are not reused. More critically, it fails to correctly trace the entire chain because it restarts the search from j=0 every time a connection is found, which can lead to infinite loops or incorrect counts if not managed with a visited array, but here it just relies on the structure. However, the main issue is that it only extends in one direction (forward). It should also check if the current segment's start connects to another segment's end (backward extension) to find the true start of the chain, or simply traverse both ways. The reference solution sorts and then checks both directions. This code attempts to build a chain starting from segment i, but only looks for segments that start where the current one ends. It misses segments that end where the current one starts.
            }
            else if((x2[k]!=x1[j]||y2[k]!=y1[j])&&j==n-1)
            {
                if(count>countmax)
                {
                countmax=count;
                xmax=x;
                ymax=y;
                }
                break;
            }
            else
            continue;
        }
    }
    if(countmax==29||countmax==6) // @@ This is a hardcoded hack to pass specific test cases, which is incorrect logic. It should be removed.
    countmax++; // @@ This is a hardcoded hack to pass specific test cases, which is incorrect logic. It should be removed.
    printf("%d %d %d",countmax,xmax,ymax);
    return 0;
}