#include <math.h>
#include <stdio.h>
#define bit 10
int main()
{
    long long min=0,max=0,n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        min+=i*pow(bit,n-i); // @@ The base‑10 representation cannot handle digits larger than 9. For n=10, the correct permutation includes the number 10, but this line treats it as a single digit. Also pow may cause precision issues.
    }
    for(int i=1;i<=n;i++)
    {
        max+=(n-i+1)*pow(bit,n-i); // @@ Same issue: single‑digit assumption fails for n=10.
    }
    int a[12],cnt; // @@ cnt is uninitialized; using it later (line 38) leads to undefined behavior.
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
    printf("cnt=%d\n",cnt); // @@ This extra output does not match the required format (only permutation lines should be printed).
    return 0;
}