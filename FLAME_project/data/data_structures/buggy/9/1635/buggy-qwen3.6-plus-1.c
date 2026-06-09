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
                j=0; // @@ The logic for extending the line segment is flawed. It only checks forward connections (end of current to start of next) and resets j=0, but it fails to properly track the full chain or handle backward extensions correctly in a single pass without visited flags. More critically, it doesn't restart the scan from the beginning correctly for all potential links in a complex chain, or rather, the specific bug here is that it only extends in one direction (forward) from the initial segment i. It misses segments that connect to the *start* of the current chain (backward extension). For example, if segment A connects to B, and B connects to C, starting at B might find C. But if we start at A, we find B. If we start at C, we find nothing forward. The reference solution checks both forward and backward extensions for every segment as a potential start/middle. This code only tries to extend forward from segment `i`. It needs to also check if any segment ends at `x1[k], y1[k]` to extend backwards.
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
    if(countmax==29||countmax==6) // @@ Hardcoded adjustments for specific test cases are incorrect and indicate a fundamental logical error in the algorithm rather than a simple off-by-one. This line should be removed, and the logic above fixed.
    countmax++;
    printf("%d %d %d",countmax,xmax,ymax);
    return 0;
}