#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int f[10],a[10]; // @@ Array size should be at least 11 to safely handle N=10, as index 10 is accessed causing out-of-bounds.
int n;
void d(int x)
{
    if(x==n)
    {
        int i=0;
        while(i<n)
        {
            printf("%d",a[i]); // @@ Missing space separator between numbers as required by the output format.
            i++;
        }
        printf("\n");
        return;
    }
    else
    {
        int i=1;
        while(i<=n)
        {
            if(!f[i])
            {
                a[x]=i;
                f[i]=1;
                d(x+1);
                f[i]=0;
            }
            i++;
        }
    }
}
int main()
{
    scanf("%d",&n);
    d(0);
    return 0;
}