#include <stdio.h>
void full_permutation(int k);
int a[10], b[10], n; // @@ Array b is declared with size 10, but indices up to n (which can be 10) are accessed, causing out-of-bounds access. It should be at least size 11.
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
            printf("%d", a[i]); // @@ Missing space separator between integers. The output format requires each integer to be separated by a space.
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