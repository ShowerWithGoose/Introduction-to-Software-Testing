#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int st[100] = {}; // @@ In standard C, array initialization with empty braces is invalid; use {0} instead to avoid compilation errors.
int ar[100] = {}; // @@ In standard C, array initialization with empty braces is invalid; use {0} instead to avoid compilation errors.
int n;
void dfs(int x)
{
    int i;
    if (x > n)
    {
        for (i = 1; i <= n; i++)
        {
            printf("%d", ar[i]); // @@ Missing space separator between integers as required by the output format.
        }
        printf("\n"); // @@ Missing 'return;' statement after printing the permutation, causing the function to proceed to the loop and result in infinite recursion or incorrect output.
    }
    for (i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            ar[x] = i;
            dfs(x + 1);

            st[i] = 0;
            ar[x] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}