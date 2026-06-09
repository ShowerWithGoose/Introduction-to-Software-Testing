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
          b[i]=1; // @@ Error: This line assigns the value 1 to b[i] instead of b[k]. It should be b[k]=i; to store the current permutation element at position k.
          f(k+1);
          a[i]=0;
          b[i]=0; // @@ Error: This line resets b[i] to 0, but it should reset b[k] to 0 to match the correct assignment. It should be b[k]=0;
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