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
          b[k]=i; // @@ [The value i should be stored at index k (the current depth/position in permutation), not at index i. Using b[i]=1 incorrectly overwrites positions and fails to record the actual number chosen.]
          f(k+1);
          a[i]=0;
          b[k]=0; // @@ [Backtracking should reset the position k, not index i, to match the assignment change above.]
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