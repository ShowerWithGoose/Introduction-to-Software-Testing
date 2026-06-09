#include<stdio.h>
int a[100],num[100];
int n;
void rank(int in)
{
    if(in==n)
    {
        for(int i = 0;i<n;i++)
        {
            printf("%d",a[i]); // @@ Missing space between numbers; should be "%d " to match expected output format
        }
        printf("\n");
    }
    {
        for(int i = 1;i<=n;i++)
        {
            if(num[i]==0)
            {
                a[in]=i;
                num[i]=1;
                rank(in+1);
                num[i]=0;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    rank(0);
    return 0;
}