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
            printf("%d", a[i]); // @@ The output format requires integers to be separated by a space, but this line prints them consecutively without spaces. It should be printf("%d ", a[i]); or similar logic to handle spacing correctly (e.g., space after each except the last, or space after all and trim, but typically space after each is accepted if trailing space is allowed, however standard is usually "1 2". Let's look at expected: "1 2 ". The expected output in the prompt is "1 2 " with a trailing space or just "1 2"? The prompt says "Each integer in a line is separated by a space." Usually this means "1 2". The buggy output is "12". The fix is to add a space.
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