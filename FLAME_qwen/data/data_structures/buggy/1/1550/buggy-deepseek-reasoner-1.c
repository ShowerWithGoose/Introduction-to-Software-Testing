#include<stdio.h>
#include<string.h>

int mark[10]; // @@ 数组大小应为大于等于n+1，当前大小10在n=10时访问mark[10]越界
int a[10]; // @@ 数组大小应为大于等于n+1，当前大小10在n=10时访问a[10]越界
int n;

void dfs(int x)
{
    int i;
    if(x == n + 1)
    {
        for(i = 1; i <= n; i++)
        {
            printf("%d",a[i]); // @@ 缺少空格分隔符，应改为 printf("%d ", a[i]) 以符合输出格式要求
        }
        puts("");
        return ;
    }
    for(i = 1; i <= n; i++)
    {
        if(!mark[i])
        {
            mark[i] = 1;
            a[x] = i;
            dfs(x + 1);
            mark[i] = 0;    
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}