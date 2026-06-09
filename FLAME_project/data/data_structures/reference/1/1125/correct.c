#include<stdio.h>
int book[20];
int a[20];
int n;
void dfs(int x,int num)
{
    int i;
    if(num==n)
    {
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        puts("");
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[num]=i;
            dfs(i,num+1);
            book[i]=0;
        }
        
    }
}
int main()
{
    
    scanf("%d",&n);
    dfs(0,0);
    return 0;
}


