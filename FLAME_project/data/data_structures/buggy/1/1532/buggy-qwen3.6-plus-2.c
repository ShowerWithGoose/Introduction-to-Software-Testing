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
            printf("%d",path[i] ); // @@ The output format is incorrect. Integers should be separated by a space, but this code prints them consecutively without spaces.
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