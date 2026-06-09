#include <stdio.h>
int num[9];
int repeat(int a[],int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++) // @@ The loop condition j<n+1 accesses a[n+1] which is out of bounds for an array of size n (indexed 1 to n). It should be j<=n. Also, the outer loop should likely start from 1 and go up to n-1, but the main issue here is the inner loop bound causing potential out-of-bounds access or incorrect comparison logic depending on array usage. However, looking at `pl`, `num` is 1-indexed. `repeat` checks duplicates. The loop `j<n+1` means `j` goes up to `n`. If `a` has valid indices 1..n, `a[n]` is valid. But `j` starts at `i+1`. If `i=n-1`, `j=n`. `a[n]` is valid. Wait, the array `num` in `pl` is filled from index 1 to n. So `a[1]...a[n]` are valid. The loop `j < n+1` is equivalent to `j <= n`. This part might be technically okay for bounds if we assume 1-based indexing into an array large enough. However, the standard duplicate check usually compares all pairs. Let's look closer. `i` goes from 1 to `n-1`. `j` goes from `i+1` to `n`. This covers all pairs. So `repeat` logic for bounds is actually okay IF the array is 1-indexed and size >= n+1. `num` is size 9. N<=10? Problem says N<=10. `num[9]` is too small for N=10 if 1-indexed (needs index 10). But test case is N=2.
        // Let's look at the output format.
        if(a[i]==a[j])
        {
            return 1;
        }
    }
    return 0;
}
void pl(int pt,int n)
{
    int i;
    if(pt>n)
    {
        if(repeat(num,n)==0)
        {
            for(i=1; i<=n; ++i)
            {
                printf("%d ",num[i]); // @@ The expected output requires spaces between numbers. The original code prints "%d" without a space, resulting in "12" instead of "1 2".
            }
            printf("\n");
        }
    }
    else
    {
        for(i=1; i<=n; ++i)
        {
            num[pt]=i;
            pl(pt+1,n);
        }
    }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    pl(1,n);
    return 0;
}