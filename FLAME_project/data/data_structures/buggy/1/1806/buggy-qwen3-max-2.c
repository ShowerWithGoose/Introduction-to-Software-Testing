#include<stdio.h>
int a[10]={1,2,3,4,5,6,7,8,9}, c[10], n, d[10];
void dfs(int i);
int main()
{
    scanf_s("%d", &n); // @@ [The function 'scanf_s' is not available in standard C (it's a Microsoft-specific secure version). The correct standard function is 'scanf'. This causes a compilation error because 'scanf_s' is implicitly declared and undefined during linking.]
    for (int i = 0; i < n; i++)
    {
        c[i] = 0;
    }
    dfs(0);
    return 0;
}
void dfs(int x)
{
    if (x == n)
    {
        for (int v = 0; v < n; v++)
        {
            printf("%d ", d[v]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (c[i] == 0)
            {
                d[x] = a[i];
                c[i] = 1;
                dfs(x + 1);
                c[i] = 0;
            }
        }
    }

}