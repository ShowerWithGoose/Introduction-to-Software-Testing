#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int a[10],b[10]; // @@ Array size is insufficient for N=10 since indices 1 to 10 are accessed, causing out-of-bounds. Should be at least 11.
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
          b[i]=1; // @@ Logical error: incorrectly assigns 1 to index i. Should store the current number i at the k-th position of the permutation array: b[k]=i;
          f(k+1);
          a[i]=0;
          b[i]=0; // @@ Logical error: incorrectly backtracks index i. Should backtrack the k-th position of the permutation array: b[k]=0;
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