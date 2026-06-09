#include <stdio.h>

int a[20], m;
int b[20];

void dfs(int k)
{
    if (k == m)

    {
        for (int i = 0; i < m; i++)
            printf("%d", a[i]); // @@ The output format requires integers to be separated by a space, but this line prints them consecutively without spaces. It should be printf("%d ", a[i]); or similar logic to handle spacing correctly (e.g., space after each number except potentially the last, though the problem says "separated by a space" and typical judges accept trailing space). Given the expected output "1 2 ", a space after each number is likely expected or at least between them. Let's look at expected: "1 2 ". This implies a space after 1 and after 2. So printf("%d ", a[i]) is correct.
        printf("\n");
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i] == 0)
        {
            a[k] = i;
            b[i] = 1;
            dfs(k + 1);
            b[i] = 0;
        }
    }
    return;
}

int main()
{
    scanf("%d", &m);
    dfs(0);
    return 0;
}