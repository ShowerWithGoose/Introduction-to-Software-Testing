#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int a[10],b[10]; // @@ [Array size should be at least 11 to accommodate index up to N (1..N). Using a[10] and b[10] leads to out-of-bounds access when i=10.]
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
          b[i]=1; // @@ [Logic error: b should store the value at position k, not index i. Should be b[k]=i. Using b[i]=1 incorrectly sets all positions to 1.]
          f(k+1);
          a[i]=0;
          b[i]=0;    
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