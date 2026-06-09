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
          b[i]=1; @@ [The assignment b[i]=1 is incorrect. It should assign the current value 'i' to b[k], not set b[i] to 1. This causes wrong permutation values and overwrites previous positions in b.]
          f(k+1);
          a[i]=0;
          b[i]=0; @@ [Similarly, resetting b[i]=0 is wrong. It should only reset the marker array 'a', not the permutation array 'b'. Moreover, the position in b that was set is b[k], not b[i].]
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