#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int C[15];
int ans[15];
int n;
void f(int a,int b)
{
    int i;
    if(b==0)
    {
        for(int j=0;j<n;j++) // @@ [C89 may not allow declaration inside for; use separate int j;]
            printf("%d",ans[j]); // @@ [Missing space between numbers; should be "%d "]
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(C[i]==0)
        {
            C[i]=1;
            ans[a]=i;
            f(a+1,b-1);
            C[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    f(0,n);
    return 0;
}