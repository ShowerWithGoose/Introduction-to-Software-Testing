#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int path[12],mark[12];
void f(int n,int N)
{
    int i;
    if(N==n)
    {
        for(i=0;i<n;i++)
        {
            printf("%d",path[i] ); // @@ Missing space between numbers; should be "%d " to match expected output format with spaces.
        }
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(mark[i]==1)
        {
            continue;
        }
        path[N]=i;
        mark[i]=1;
        f(n,N+1);
        mark[i]=0;
        
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    f(n,0);
    return 0;
}