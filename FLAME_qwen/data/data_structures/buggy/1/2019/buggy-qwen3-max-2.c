#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n); // @@ [The problem expects input N as an integer (1<=N<=10), but using %lld reads a long long. While this may work, it's inconsistent with typical int usage for small N and can cause issues on some systems. However, the real issue is deeper.]
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ [Using pow() from math.h introduces floating-point inaccuracies. For example, pow(10, 2) might return 99.999... instead of 100, leading to incorrect integer conversion. This breaks the generation of correct numeric ranges.]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ [Same floating-point inaccuracy issue as above. This causes min and max to be incorrect, so the loop range [min, max] does not correctly represent all n-digit numbers in base 10 with digits 1..n.]
    }
    int a[12],cnt;
    for(int i=min;i<=max;i++) // @@ [Because min and max are likely wrong due to floating-point errors, this loop may skip valid permutations or include invalid numbers. Also, the approach itself is flawed: not all numbers between min and max correspond to permutations (e.g., includes numbers with 0 or repeated digits), and lexicographical order is not guaranteed because numeric order ≠ lexicographic order for permutations when n<10 (e.g., 12 vs 2).]
    {
        int temp=i,flag=0,vis[20]={0};
        for(int j=n-1;j>=0;j--)
        {
            a[j]=temp%bit;
            temp/=bit;
            vis[a[j]]++;
            if(vis[a[j]]>1||a[j]>n||a[j]==0) // @@ [This check correctly filters out non-permutations, but because the outer loop range is broken, many valid permutations may never be reached, and invalid ones may be processed unnecessarily.]
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
    printf("cnt=%d\n",cnt); // @@ [Printing 'cnt' is not part of the expected output. The problem requires only the permutations, nothing else. This extra line causes output mismatch. Also, 'cnt' is uninitialized, so its value is garbage.]
    return 0;
}