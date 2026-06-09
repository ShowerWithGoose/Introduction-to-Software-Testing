#include <stdio.h>
#include <string.h>
int n;
int stack[1000];
void print_stack()
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int find_in_stack(int key,int len)
{
    for(int i=0;i<len;i++)
    {
        if(stack[i]==key)
        {
            return 1;
        }
    }
    return 0;
}
void dfs(int len)
{
    if(len==n){
        print_stack();
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!find_in_stack(i,len))
        {
            stack[len]=i;
            dfs(len+1);
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}

