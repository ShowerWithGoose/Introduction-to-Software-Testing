#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n); // @@ [The problem expects input N as an integer (1<=N<=10), but using %lld reads a long long. While this may work, it's inconsistent with typical usage for small N and could cause issues on some systems. However, the real issue is algorithmic, not compilation. But note: the reported error was "gcc: not found", which is a compilation environment issue, not code error. Yet the actual bug is logical.]
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ [Using pow() from math.h for integer powers introduces floating-point inaccuracies. For example, pow(10,2) might return 99.999... which becomes 99 when cast to int, breaking digit extraction. This causes incorrect min/max bounds and wrong permutations.]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ [Same floating-point inaccuracy issue with pow() as above, leading to incorrect max value.]
    }
    int a[12],cnt;
    for(int i=min;i<=max;i++) // @@ [This loop iterates over a numeric range assuming all numbers in [min, max] with n digits in base-10 are permutations, which is false. Many numbers in this range have repeated digits or zeros, but more critically, due to pow() errors, min and max themselves may be wrong, causing missed or extra permutations. Also, lexicographical order is not guaranteed because numeric order of these constructed numbers does not match lex order of permutations when N<10 (e.g., for N=2: 12,21 is correct, but if N=3, 123,132,... but numeric iteration includes 124 which is invalid).]
    {
        int temp=i,flag=0,vis[20]={0};
        for(int j=n-1;j>=0;j--)
        {
            a[j]=temp%bit;
            temp/=bit;
            vis[a[j]]++;
            if(vis[a[j]]>1||a[j]>n||a[j]==0) // @@ [This check correctly filters out invalid digits, but due to earlier pow() inaccuracies, the loop bounds (min, max) are wrong, so valid permutations might be skipped or invalid ones considered. Also, the array 'a' is filled from least significant digit, so for i=123, a[0]=3,a[1]=2,a[2]=1, which reverses the permutation. Thus output order is reversed per number, breaking lexicographical order.]
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",a[j]); // @@ [Because a[j] was filled from least significant digit (rightmost) to most (leftmost), the printed permutation is reversed. For example, the number 123 (which should represent [1,2,3]) is stored as a[0]=3, a[1]=2, a[2]=1, so it prints "3 2 1", which is wrong.]
            }
            printf("\n");
            cnt++;
        }
    }
    printf("cnt=%d\n",cnt); // @@ [The problem does not require printing the count. This extra line causes output mismatch. Also, 'cnt' is uninitialized, leading to undefined behavior (though it may appear to work by chance).]
    return 0;
}