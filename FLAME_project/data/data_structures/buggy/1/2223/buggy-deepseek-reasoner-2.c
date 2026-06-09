#include <stdio.h>
int num[9]; // @@ array size too small for N up to 10; need at least 11 for 1-indexed usage
int repeat(int a[],int n)
{
    int i,j;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<n+1; j++)
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
                printf("%d",num[i]); // @@ missing space after each number; should be "%d "
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