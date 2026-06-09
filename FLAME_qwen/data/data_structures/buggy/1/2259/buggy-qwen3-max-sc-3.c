#include<stdio.h>
int a[100],num[100];
int n;
void rank(int in)
{
    if(in==n)
    {
        for(int i = 0;i<n;i++)
        {
            printf("%d",a[i]); // @@ [Missing space between numbers as required by output format; should print "%d " instead of "%d"]
        }
        printf("\n");
    }
    { // @@ [Unnecessary extra block braces; not an error per se but indicates possible confusion, however the real issue is missing else or improper structure—though logically it still works. The main functional errors are elsewhere.]
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