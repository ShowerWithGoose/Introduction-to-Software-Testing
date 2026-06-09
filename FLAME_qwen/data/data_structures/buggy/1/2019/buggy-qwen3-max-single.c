#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n); // @@ [The problem expects input N as an integer with 1<=N<=10, but using %lld reads a long long. While this may work, the bigger issue is the overall algorithmic approach which is inefficient and incorrect for generating permutations in lexicographical order.]
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ [Using pow() from math.h for integer powers introduces floating-point inaccuracies. For example, pow(10, 2) might return 99.999... instead of 100, leading to wrong min/max values.]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ [Same floating-point precision issue with pow() causing incorrect max value.]
    }
    int a[12],cnt;
    for(int i=min;i<=max;i++) // @@ [This loop iterates over a huge range (e.g., for N=10, min≈1234567890, max≈9876543210), which is computationally infeasible and unnecessary. Also, many numbers in this range are not valid permutations.]
    {
        int temp=i,flag=0,vis[20]={0};
        for(int j=n-1;j>=0;j--)
        {
            a[j]=temp%bit;
            temp/=bit;
            vis[a[j]]++;
            if(vis[a[j]]>1||a[j]>n||a[j]==0) // @@ [This checks for duplicates and invalid digits, but due to floating-point errors in min/max, the loop may start or end at wrong values, missing valid permutations or including invalid ones.]
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
    printf("cnt=%d\n",cnt); // @@ [Printing extra 'cnt=' line which is not part of expected output format. The problem requires only the permutations, nothing else.]
    return 0;
}