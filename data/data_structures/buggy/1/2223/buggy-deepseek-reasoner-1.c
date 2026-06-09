#include <stdio.h>
int num[9]; // @@ [Array size should be at least 11 to safely store indices 1..10 for N up to 10. Current size 9 causes out-of-bounds access when N>=9.]
int repeat(int a[],int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<n+1; j++)
        {
            if(a[i]==a[j])
            {
                return 1;
            }
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
                printf("%d",num[i]); // @@ [Missing space between numbers. Should be "%d " to match required output format.]
            }
            printf("\n");
        }
    }
    else
    {
        for(i=1; i<=n; ++i) // @@ [This loop generates all n^n sequences without pruning, leading to an exponential number of recursive calls. For N=10, it requires 10^10 iterations, which is infeasible. The correct backtracking should skip numbers already used with a flag (as in the reference program).]
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