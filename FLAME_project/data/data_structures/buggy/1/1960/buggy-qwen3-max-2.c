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
          b[i]=1; // @@ [The error is here: it should assign 'i' to b[k], not 1 to b[i]. This causes incorrect permutation values and overwrites wrong positions in array b.]
          f(k+1);
          a[i]=0;
          b[i]=0; // @@ [Similarly, this should reset b[k], not b[i], but the main logical error is in the assignment above.]
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