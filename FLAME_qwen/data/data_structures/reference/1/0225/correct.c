#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n = 0;

inline void write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void dfs(int list[], int b[], int num)
{
    if (num == n)
    {
        for (int i = 0; i < n; i++)
        {
            write(list[i] + 1);
            putchar(' ');
        }
        putchar('\n');
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i])
        {
            continue;
        }
        b[i] = 1;
        list[num] = i;
        dfs(list, b, num + 1);
        b[i] = 0;
    }
}

int a[30], b[30];

int main()
{
    scanf("%d", &n);
    dfs(a, b, 0);
    return 0;
}


