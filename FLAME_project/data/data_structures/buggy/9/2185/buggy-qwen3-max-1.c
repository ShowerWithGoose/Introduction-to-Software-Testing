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
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(c[j]==a[i]&&d[j]==b[i])
            {
                j=i;
                i=0;
                e[h]=e[h]+1;
            }
        }
        j=h;
        h=h+1;    
    } @@ [The logic for building chains of connected segments is flawed. The outer loop variable `j` is being overwritten inside the inner loop, and resetting `i=0` causes unpredictable traversal. Also, `e[h]` counts connections but doesn't correctly track the starting point or full chain length.]
    for(i=0;i<n;i++)
    {
        if(e[i]<=e[i+1])
        {
            k=i+1; 
        }
        else
        {
            e[i+1]=e[i];
        }
    } @@ [This loop incorrectly compares `e[i]` with `e[i+1]` beyond array bounds (`e[n]` is uninitialized), and the logic does not properly find the index with maximum chain length. It also modifies `e[i+1]` which corrupts original counts.]
    printf("%d %d %d",e[k]+1,a[k],b[k]); @@ [The final output uses `e[k]+1` assuming `e[k]` stores number of connections, but due to incorrect chain building and max-finding logic, both `e[k]` and `k` are wrong. Also, `a[k], b[k]` may not correspond to the actual start of the longest chain.]
    return 0;
}