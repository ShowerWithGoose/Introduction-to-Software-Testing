#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ [undefined reference to `pow` because math library is not linked during compilation; also, using floating-point `pow` for integer exponentiation is error-prone and unnecessary]
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ [same issue: undefined reference to `pow` due to missing math library linking; additionally, logic for generating permutations via numeric range is fundamentally flawed]
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
    printf("cnt=%d\n",cnt);
    return 0;
}