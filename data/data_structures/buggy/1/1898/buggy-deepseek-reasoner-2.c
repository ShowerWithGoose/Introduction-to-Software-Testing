#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int f[10],a[10]; // @@ Array size insufficient for indices 1..N when N=10 (out of bounds at f[10]).
int n;
void d(int x)
{
    if(x==n)
    {
        int i=0;
        while(i<n)
        {
            printf("%d",a[i]); // @@ Missing space between numbers; should be "%d " to match expected output.
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