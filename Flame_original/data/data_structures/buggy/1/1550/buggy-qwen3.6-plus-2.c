#include<stdio.h>
#include<string.h>

int mark[10]; // @@ Array size is too small. When N=10, accessing mark[10] causes out-of-bounds access. It should be at least 11.
int a[10]; // @@ Array size is too small. When N=10, accessing a[10] causes out-of-bounds access. It should be at least 11.
int n;

void dfs(int x)
{
    int i;
    if(x == n + 1)
    {
        for(i = 1; i <= n; i++)
        {
            printf("%d",a[i]); // @@ Missing space separator between integers. The output format requires each integer to be separated by a space.
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