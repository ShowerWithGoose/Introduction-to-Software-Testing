#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int a[101],b[101],c[101],d[101],e[105]={}; // @@ Empty initializer {} is not standard in strict C89/C90 and may cause compilation errors; use {0} instead.
int main()
{
    int n,i,j=0,h=0,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(c[j]==a[i]&&d[j]==b[i])
            {
                j=i; // @@ Modifying the outer loop control variable j inside the inner loop disrupts the iteration and breaks the chain-following logic.
                i=0;
                e[h]=e[h]+1; // @@ The count should be associated with the starting segment index (e.g., e[j] or a temporary counter), not h, which results in incorrect accumulation.
            }
        }
        j=h; // @@ Reassigning j to h at the end of each outer loop iteration overrides the loop's natural progression, causing incorrect segment processing.
        h=h+1;    
    }
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1]) // @@ Accessing e[i+1] when i=n-1 reads beyond the valid segment data range, potentially leading to incorrect maximum index calculation.
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i];
        }
    }
    printf("%d %d %d",e[k]+1,a[k],b[k]);
    return 0;
}