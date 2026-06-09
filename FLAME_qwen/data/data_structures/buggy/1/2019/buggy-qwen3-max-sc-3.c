#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n); // @@ [The problem expects input N as an integer (1<=N<=10), but using %lld reads a long long. While this may work, it's inconsistent with typical usage for small N and can cause issues on some systems. However, the real issue is deeper.]
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ [Using pow() from math.h for integer powers introduces floating-point inaccuracies. For example, pow(10, 2) might return 99.999... instead of 100, leading to incorrect digit extraction. This breaks the generation of permutations.]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ [Same floating-point inaccuracy issue as above. This causes min and max bounds to be incorrect, leading to missing or extra numbers in the iteration range.]
    }
    int a[12],cnt;
    for(int i=min;i<=max;i++)
    {
        int temp=i,flag=0,vis[20]={0};
        for(int j=n-1;j>=0;j--)
        {
            a[j]=temp%bit;
            temp/=bit;
            vis[a[j]]++; // @@ [If a[j] is negative due to floating-point errors in min/max, this accesses vis out of bounds. Also, digits may be wrong due to earlier pow() inaccuracies.]
            if(vis[a[j]]>1||a[j]>n||a[j]==0)
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
            cnt++;
        }
    }
    printf("cnt=%d\n",cnt); // @@ [The problem does not require printing "cnt=...", so this extra output makes the solution invalid per the output format.]
    return 0;
}