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
        for(int i=1;i<=n;i++) // @@ Error: C89 does not allow declaration of variable inside for loop; causes compilation error in strict C89 mode.
        {printf("%d ",b[i]);}
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++) // @@ Error: same as above, C89 incompatibility.
    {
        if(!a[i])
        {
          a[i]=1;
          b[i]=1;
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