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
        for(int i=1;i<=n;i++) // @@ Compilation error in C89 standard: 'for' loop initial declaration not allowed; declare 'int i;' at the start of the block.
        {
            printf("%d",a[i]);
        }
        printf("\n");
        return ;
    
    }
    for(int i=1;i<=n;i++) // @@ Compilation error in C89 standard: same issue as above.
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