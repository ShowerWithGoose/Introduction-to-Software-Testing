#include<stdio.h>
int n;
int a[100];
int isuse[100];
int stack[100];
int deep = 1;
void dfs()
{
    if (deep == n+1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (isuse[i] == 0)
            {
                stack[deep] = a[i];
                deep++;
                isuse[i] = 1;
                dfs(deep);
                deep--;
                isuse[i] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        isuse[i] = 0;
    }
    dfs();
    return 0;
}


