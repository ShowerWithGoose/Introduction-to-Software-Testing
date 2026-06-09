#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i);
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i);
    }
    int a[12],cnt; // @@ cnt is uninitialized, leading to undefined behavior when incremented and printed.
    for(int i=min;i<=max;i++) // @@ i is declared as int, but min and max can exceed INT_MAX when N=10, causing integer overflow. It should be long long.
    {
        int temp=i,flag=0,vis[20]={0}; // @@ temp should be long long to safely hold the value of i without overflow.
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
    printf("cnt=%d\n",cnt); // @@ The problem specification does not require printing the count. This extra output violates the specified output format.
    return 0;
}