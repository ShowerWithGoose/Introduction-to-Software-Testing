#include<stdio.h>
int a[100],num[100];
int n;
void rank(int in)
{
    if(in==n)
    {
        for(int i = 0;i<n;i++)
        {
            printf("%d",a[i]); // @@ Missing space separator between integers, violating the output format requirement.
        }
        printf("\n");
    } // @@ Missing return statement after printing the permutation; without it, execution falls through to the loop, causing incorrect recursion and output.
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