#include<stdio.h>
int a[100],num[100];
int n;
void rank(int in)
{
    if(in==n)
    {
        for(int i = 0;i<n;i++) // @@ Declaring loop variable inside 'for' may cause compilation error in C89 standard; declare 'int i' before the loop.
        {
            printf("%d",a[i]); // @@ Missing space separator between numbers as required by the output format.
        }
        printf("\n");
    } // @@ Missing 'return;' statement after base case print, causing fall-through to the next block and infinite recursion.
    { // @@ This block should be preceded by 'else' to prevent execution when the base case is met.
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