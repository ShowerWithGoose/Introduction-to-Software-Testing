#include <stdio.h>
int a[10], flag[12] = {0};
void get_num(int t, int n)
{
    if (t == n) 
    {
        for (int i = 0; i < n; i++)
            printf("%d", a[i]); // @@ missing space between numbers, output should have spaces.
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