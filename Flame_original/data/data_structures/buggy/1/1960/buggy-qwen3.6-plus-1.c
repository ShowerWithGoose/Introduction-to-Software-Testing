#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int a[10],b[10]; // @@ Array size is insufficient for N=10 with 1-based indexing; should be at least 11 to prevent out-of-bounds access.
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
          b[i]=1; // @@ Logical error: should assign the current number i to the k-th position in the permutation array, i.e., b[k]=i;
          f(k+1);
          a[i]=0;
          b[i]=0;    // @@ Logical error: should reset the k-th position during backtracking, i.e., b[k]=0;
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