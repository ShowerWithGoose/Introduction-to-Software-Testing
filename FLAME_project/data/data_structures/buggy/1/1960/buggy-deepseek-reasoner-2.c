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
          b[i]=1; // @@ Should be b[k]=i to store the current number at position k
          f(k+1);
          a[i]=0;
          b[i]=0; // @@ Should be b[k]=0 to clear the current position
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