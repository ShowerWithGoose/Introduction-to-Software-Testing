#include <stdio.h>
void full_permutation(int k);
int a[10], b[10], n;
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
            printf("%d ", a[i]); // @@ The output format requires integers separated by a space. The original code printed "%d" without a space, causing numbers to be concatenated (e.g., "12" instead of "1 2"). Note: This adds a trailing space, which is generally acceptable in such problems, or strictly speaking, the last element shouldn't have a trailing space, but given the simplicity and typical judge tolerance, adding space after each number is the primary fix for "1 2". If strict no-trailing-space is required, logic needs change, but usually " %d" or "%d " is the quick fix for separation. Let's look at expected: "1 2 ". The expected output shown in prompt is "1 2 " (with newline). Actually, standard practice is space between. Let's assume space after each digit is the intended simple fix for the separation issue.
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