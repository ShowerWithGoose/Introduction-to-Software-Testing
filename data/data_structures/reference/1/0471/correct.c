#include <stdio.h>
int n,top;
int a[15];
int stc[15];
int flat[15];
void del()
{
    int i=0;
    for(;i<n;i++)
    {
        flat[i]=1;
    }
}
void dfs(int x)
{
    int j;
    if(x==n)
    {
        for(int i=0;i<n;i++)
            printf("%d ",stc[i]);
        printf("\n");
        return ;
    }
    for(j=0;j<n;j++)
    {
        if(flat[j]==1)
        {
            flat[j]=0;
            stc[top++]=a[j];
            dfs(x+1);
            top--;
            flat[j]=1;
        }
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    del();
    top=0;
    dfs(0);
    return 0;
}



