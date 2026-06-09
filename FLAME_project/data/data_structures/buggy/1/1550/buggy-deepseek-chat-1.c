#include<stdio.h>
#include<string.h>

int mark[10];
int a[10];
int n;

void dfs(int x)
{
    int i;
    if(x == n + 1)
    {
        for(i = 1; i <= n; i++)
        {
            printf("%d",a[i]); // @@ Missing space between numbers; should be printf("%d ", a[i]);
        }
        puts(""); // @@ This prints an empty line, but the expected output requires a space after each number except the last; the current output has no spaces between numbers.
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