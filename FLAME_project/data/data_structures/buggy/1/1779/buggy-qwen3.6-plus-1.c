#include<stdio.h>
void dfs(int s);
int fangru[12],a[12];
int n;
int main()
{

    scanf("%d",&n);
    dfs(1);
    return 0;
}
void dfs(int s)
{
    if(s==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",a[i]); // @@ The output format requires integers to be separated by a space, but here only the number is printed without a trailing space or separator.
        }
        printf("\n");
        return ;
    
    }
    for(int i=1;i<=n;i++)
    {
        if(!fangru[i])
        {
            a[s]=i;
            fangru[i]=1;
            dfs(s+1);
            fangru[i]=0;
        }
    }
    
    
}