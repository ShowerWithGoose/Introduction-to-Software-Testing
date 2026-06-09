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
        {printf("%d ",b[i]);} // @@ [The array b is being used to store the permutation, but in the loop below, b[i] is set to 1 instead of storing the actual value 'i' at position 'k'. This causes incorrect output where all selected positions show 1 instead of the chosen number.]
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!a[i])
        {
          a[i]=1;
          b[i]=1; // @@ [This line incorrectly assigns 1 to b[i]. It should assign 'i' to b[k] to record that at position 'k' in the permutation, the value 'i' is placed. Using b[i]=1 corrupts the permutation storage and leads to wrong output.]
          f(k+1);
          a[i]=0;
          b[i]=0; // @@ [Similarly, this reset should be b[k]=0, not b[i]=0, because the assignment was (incorrectly) made to b[i]. Even if fixed above, resetting b[k] would be correct. As it stands, this line does not properly backtrack the permutation array.]
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