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
        {printf("%d ",b[i]);} @@ [The array b is being used to store the current permutation, but in the loop below, b[i] is set to 1 instead of storing the actual value 'i' at position 'k'. This causes incorrect output because b[i] = 1 overwrites previous values and does not represent the permutation correctly.]
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!a[i])
        {
          a[i]=1;
          b[i]=1; @@ [This line should be b[k] = i; because we are placing the value 'i' at the k-th position in the permutation array b. Setting b[i] = 1 corrupts the permutation structure and leads to wrong output.]
          f(k+1);
          a[i]=0;
          b[i]=0; @@ [This line should be b[k] = 0; to backtrack the k-th position, not b[i]. Since b[i] was incorrectly assigned earlier, this also incorrectly resets the wrong index.]
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