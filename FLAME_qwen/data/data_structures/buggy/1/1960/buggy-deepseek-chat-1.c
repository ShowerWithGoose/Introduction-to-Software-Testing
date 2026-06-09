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
          b[i]=1; // @@ Error: This should be b[k]=i; not b[i]=1; The current code sets b[i] to 1 instead of storing the permutation value i at position k.
          f(k+1);
          a[i]=0;
          b[i]=0; // @@ Error: This should be b[k]=0; to reset the position k, not b[i]=0.
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