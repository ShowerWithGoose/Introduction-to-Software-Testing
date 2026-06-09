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
    for(j=0;j<n;j++) // @@ The logic for finding continuous segments is fundamentally flawed. It modifies the loop variable `j` inside the loop (`j=i`), which disrupts the iteration order and prevents correct chaining of multiple segments. It also fails to mark visited segments, leading to incorrect counts or infinite loops in some cases, and doesn't properly handle the "start point" tracking for the longest chain.
    {
        for(i=0;i<n;i++)
        {
            if(c[j]==a[i]&&d[j]==b[i])
            {
                j=i; // @@ Modifying the outer loop index `j` here causes the algorithm to skip segments and fail to explore all possible connections correctly. It essentially jumps to the next segment but loses the context of the current chain's start.
                i=0;
                e[h]=e[h]+1;
            }
        }
        j=h; // @@ Resetting `j` to `h` is incorrect logic. `h` is just a counter for chains started, not an index into the segment array that corresponds to the current position in a chain.
        h=h+1;    
    }
    for(i=0;i<n;i++) // @@ This loop attempts to find the maximum value in `e`, but the logic `if(e[i]<=e[i+1])` accesses `e[n]` when `i=n-1`, which is out of bounds if `n` equals the size of valid data, and the logic for updating `k` and `e` is convoluted and incorrect for finding the max index properly alongside its value.
    {
        if(e[i]<=e[i+1])
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i];
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]); // @@ The output uses `a[k]` and `b[k]` as the start point. However, due to the flawed chaining logic, `k` might not correspond to the actual start of the longest chain, or the chain construction itself was incorrect. The reference solution sorts segments and merges them, ensuring the start point is preserved from the first segment in the chain. This code does not preserve the original start point of a chain if it's formed by merging.
    return 0;
}