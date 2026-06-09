#include <stdio.h>
void full_permutation(int k);
int a[10], b[10], n; // @@ Array size is insufficient for N=10; accessing b[10] causes out-of-bounds error. Size should be at least 11.
int main()
{

    scanf("%d", &n);
    full_permutation(0);
    return 0;
}

void full_permutation(int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", a[i]); // @@ Missing space separator between integers as required by the output format.
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == 0)
        {
            a[k] = i;
            b[i] = 1;
            full_permutation(k + 1);
            b[i] = 0;
        }
    }
}