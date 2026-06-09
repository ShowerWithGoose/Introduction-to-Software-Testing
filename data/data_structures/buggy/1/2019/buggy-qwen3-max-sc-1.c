#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n); // @@ [The problem expects input N as an integer (1<=N<=10), but using %lld reads a long long. While this may work, it's inconsistent with typical expectations for small N. However, the real issue is algorithmic, not compilation. But note: the reported error was "gcc: not found", which is a system/environment error, not code error. Yet the actual bug is logical.]
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ [Using pow() from math.h returns a double, which can introduce floating-point inaccuracies when converting to integer. This leads to incorrect min/max values and thus wrong permutations. Also, the approach of iterating from min to max is inefficient and flawed for permutation generation.]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ [Same floating-point precision issue with pow(). For example, pow(10,2) might be 99.999... instead of 100, leading to truncation errors.]
    }
    int a[12],cnt;
    for(int i=min;i<=max;i++) // @@ [This loop assumes all valid permutations correspond to numbers between min and max in base-10, which is incorrect. For N=3, min=123, max=321, but numbers like 132 are in between, yet many numbers in [123,321] are not permutations (e.g., 122, 133). Also, for N=10, max is 10-digit number ~10^10, which exceeds int range and makes loop infeasible.]
    {
        int temp=i,flag=0,vis[20]={0};
        for(int j=n-1;j>=0;j--)
        {
            a[j]=temp%bit; // @@ [This extracts digits in reverse order, but for numbers with fewer than n digits (e.g., when i < 10^(n-1)), leading zeros would be implied, but temp%bit gives actual digits without padding. However, since min starts at 123...n, it avoids leading zeros, but the logic fails due to gaps and invalid numbers.]
            temp/=bit;
            vis[a[j]]++;
            if(vis[a[j]]>1||a[j]>n||a[j]==0) // @@ [Correctly checks for duplicates, out-of-range, or zero, but the overall enumeration method is fundamentally flawed and inefficient.]
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",a[j]);
            }
            printf("\n");
            cnt++; // @@ [Variable 'cnt' is used uninitialized. This leads to undefined behavior when incrementing. Should be initialized to 0.]
        }
    }
    printf("cnt=%d\n",cnt); // @@ [The problem does not require printing "cnt=...", so this extra output causes mismatch with expected output format. Also, 'cnt' is uninitialized, leading to garbage value.]
    return 0;
}