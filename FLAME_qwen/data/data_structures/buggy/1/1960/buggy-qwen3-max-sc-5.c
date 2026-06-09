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
          b[i]=1; // @@ [This line incorrectly assigns 1 to b[i] instead of assigning the current value 'i' to b[k]. It should be b[k] = i to store the permutation correctly.]
          f(k+1);
          a[i]=0;
          b[i]=0; // @@ [This line incorrectly resets b[i] instead of b[k]. Since the assignment was to b[i] (which is wrong), resetting b[i] also corrupts the permutation array. It should reset b[k] if it were assigned correctly, but the real fix is to assign to b[k] in the first place.]
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