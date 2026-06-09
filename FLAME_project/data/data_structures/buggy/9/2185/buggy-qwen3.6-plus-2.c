#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[101],b[101],c[101],d[101],e[105]={};
int main()
{
    int n,i,j=0,h=0,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(j=0;j<n;j++) // @@ The logic for finding connected segments is flawed. It modifies the loop variable `j` inside the loop (`j=i`), which disrupts the iteration order and prevents correctly tracing chains of segments. It also fails to mark visited segments, leading to incorrect counts or infinite loops in some cases, and doesn't properly handle the "start point" tracking for the longest chain.
    {
        for(i=0;i<n;i++)
        {
            if(c[j]==a[i]&&d[j]==b[i])
            {
                j=i; // @@ Modifying the outer loop variable `j` here causes the algorithm to skip segments and fail to explore all possible connections correctly. It essentially jumps to the next segment in a potential chain but breaks the systematic search required to find the longest chain starting from each unvisited segment.
                i=0;
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ Resetting `j` to `h` (which increments each outer loop iteration) is arbitrary and does not correctly reset the state for finding the next independent chain or segment.
        h=h+1;    
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) // @@ This logic for finding the maximum count is incorrect. It compares adjacent elements and updates `k` based on local comparisons, not finding the global maximum. Also, `e[i+1]` might be out of bounds or uninitialized if `i` reaches `n-1`.
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i]; // @@ This overwrites the count of the next segment with the current one, corrupting the data array `e` which is supposed to store the length of the chain starting at each segment.
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ Since the calculation of `e` and `k` is wrong, the output will be incorrect. The `+1` suggests an attempt to correct for 0-based counting or initial segment, but the underlying data is flawed.
    return 0;
}