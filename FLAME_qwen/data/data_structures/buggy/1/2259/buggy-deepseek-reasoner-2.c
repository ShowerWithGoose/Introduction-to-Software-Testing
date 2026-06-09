#include<stdio.h>
int a[100],num[100];
int n;
void rank(int in)
{
    if(in==n)
    {
        for(int i = 0;i<n;i++) // @@ Declaration of 'i' inside for loop not allowed in C89, causes compilation error
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    {
        for(int i = 1;i<=n;i++) // @@ Declaration of 'i' inside for loop not allowed in C89, causes compilation error
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