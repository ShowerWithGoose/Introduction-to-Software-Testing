#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n); @@ [Using %lld for input but problem states N is between 1 and 10, which fits in int; however, the bigger issue is using floating-point pow() for integer exponentiation leading to precision errors]
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); @@ [pow() returns double and may introduce floating-point inaccuracies, causing incorrect digit placement]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); @@ [Same floating-point precision issue with pow() leading to wrong max value]
    }
    int a[12],cnt;
    for(int i=min;i<=max;i++)
    {
        int temp=i,flag=0,vis[20]={0};
        for(int j=n-1;j>=0;j--)
        {
            a[j]=temp%bit;
            temp/=bit;
            vis[a[j]]++;
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
    printf("cnt=%d\n",cnt); @@ [The problem does not require printing cnt=..., so this extra output causes mismatch with expected output]
    return 0;
}