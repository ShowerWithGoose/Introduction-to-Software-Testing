#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int f[10],a[10]; // @@ Array size is insufficient. N can be up to 10, and f is indexed from 1 to N, so accessing f[10] causes an out-of-bounds error. Size should be at least 11.
int n;
void d(int x)
{
    if(x==n)
    {
        int i=0;
        while(i<n)
        {
            printf("%d",a[i]); // @@ Missing space separator between integers. The problem requires each integer in a line to be separated by a space.
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