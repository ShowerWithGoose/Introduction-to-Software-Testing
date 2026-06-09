#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n); // @@ [The problem expects input N as an integer (1<=N<=10), but using %lld reads a long long. While this may work, the bigger issue is the overall algorithmic approach which is inefficient and incorrect for generating permutations in lexicographical order.]
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ [Using pow() from math.h introduces floating-point inaccuracies. For example, pow(10, 2) might return 99.999... instead of 100, leading to incorrect digit extraction. This causes wrong values in 'min' and 'max'.]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ [Same floating-point precision issue with pow() as above, leading to incorrect 'max' value.]
    }
    int a[12],cnt;
    for(int i=min;i<=max;i++) // @@ [This loop iterates over a huge range (e.g., for N=10, min≈1e9, max≈1e10), which is computationally infeasible and unnecessary. The approach of checking every number in this range for being a permutation is fundamentally flawed and inefficient.]
    {
        int temp=i,flag=0,vis[20]={0};
        for(int j=n-1;j>=0;j--)
        {
            a[j]=temp%bit; // @@ [Extracting digits assumes base-10 representation, but due to floating-point errors in 'min' and 'max', 'i' may not correspond to valid n-digit numbers with digits 1..n. Also, leading zeros or invalid digits may appear.]
            temp/=bit;
            vis[a[j]]++;
            if(vis[a[j]]>1||a[j]>n||a[j]==0) // @@ [This condition correctly checks for duplicates, out-of-range, or zero digits, but because 'i' ranges over invalid numbers due to earlier errors, many false negatives/positives occur.]
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
            cnt++; // @@ [Variable 'cnt' is used uninitialized. This leads to undefined behavior when incrementing and later printing its value.]
        }
    }
    printf("cnt=%d\n",cnt); // @@ [Printing 'cnt' is not part of the expected output format. The problem only requires the permutations, nothing else. This extra line causes output mismatch.]
    return 0;
}