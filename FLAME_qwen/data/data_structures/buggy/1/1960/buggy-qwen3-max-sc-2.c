#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int a[10],b[10];
int n;
void f(int k)
{
    if(k>n)
    {
        for(int i=1;i<=n;i++)
        {printf("%d ",b[i]);}
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!a[i])
        {
          a[i]=1;
          b[i]=1; @@ [The assignment b[i]=1 is incorrect. It should assign the current value 'i' to b[k], not set b[i] to 1. This causes wrong permutation output and overwrites previous values in b.]
          f(k+1);
          a[i]=0;
          b[i]=0; @@ [Similarly, resetting b[i]=0 is wrong. It should only backtrack a[i]; b[k] will be overwritten in next iterations. This corrupts the permutation array b.]
        }
    }
    return;
}
int main()
{
   scanf("%d",&n);
   f(1);
   return 0;
}