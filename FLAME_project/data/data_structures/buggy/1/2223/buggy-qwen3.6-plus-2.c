#include <stdio.h>
int num[9];
int repeat(int a[],int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<n+1; j++) // @@ [Array index out of bounds: accessing a[n] which is invalid for an array of size n indexed from 1 to n-1 or 0 to n-1 depending on context, but here logic is flawed. Also, the loop condition j<n+1 accesses a[n], which is out of bounds if a is treated as 1-indexed with size n. More importantly, the repeat function logic is inefficient and incorrect for checking permutations during generation.]
        {
            if(a[i]==a[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
void pl(int pt,int n)
{
    int i;
    if(pt>n)
    {
        if(repeat(num,n)==0)
        {
            for(i=1; i<=n; ++i)
            {
                printf("%d",num[i]); // @@ [Missing space between numbers in output. The problem requires each integer to be separated by a space.]
            }
            printf("\n");
        }
    }
    else
    {
        for(i=1; i<=n; ++i)
        {
            num[pt]=i;
            pl(pt+1,n);
        }
    }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    pl(1,n);
    return 0;
}