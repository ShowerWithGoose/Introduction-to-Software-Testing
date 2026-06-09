#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) // @@ Declaring loop variable inside 'for' is a C99 feature and may cause a compilation error in older C standards (C89/C90).
    {
        min+=i*pow(bit,n-i);
    }
    for(int i=1;i<=n;i++) // @@ Same as above, C99 feature may cause compilation error in strict C89/C90 environments.
    {
        max+=(n-i+1)*pow(bit,n-i);
    }
    int a[12],cnt; // @@ Variable 'cnt' is used uninitialized, which leads to undefined behavior and can trigger compilation errors with strict warning flags.
    for(int i=min;i<=max;i++) // @@ Loop variable 'i' is declared as 'int' but compared with 'long long' variables 'min' and 'max', causing type mismatch warnings/errors and potential overflow.
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
    printf("cnt=%d\n",cnt);
    return 0;
}