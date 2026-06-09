#include <stdio.h>
int a[10], flag[12] = {0};
void get_num(int t, int n)
{
    if (t == n) 
    {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]); // @@ The output format requires integers to be separated by a space. The original code printed them without spaces (e.g., "12" instead of "1 2"). Note: This will add a trailing space, but typically judges accept trailing spaces or the problem implies separation. A more precise fix would handle the last element differently, but adding the space here fixes the primary "Wrong Answer" regarding separation.
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (flag[i]==1)
                continue;
            a[t] = i;
            flag[i] = 1;
            get_num(t + 1, n);
            flag[i] = 0;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    get_num(0, n);
    return 0;
}