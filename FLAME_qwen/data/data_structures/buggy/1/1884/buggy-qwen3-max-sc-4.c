#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[15];
int b[15];
int n;
void dfs(int x)
{
    int i;
    if(x==(n+1))
    {
        for(i=1;i<=n;i++)
        {
            printf("%d",a[i]); // @@ [Missing space after each number; output format requires space separation]
        }
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            a[x]=i;
            b[i]=1;
            dfs(x+1);
            b[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}