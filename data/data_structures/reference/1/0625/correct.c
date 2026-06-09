#include <stdio.h>

int n;
char flag[100] = {0};
int out[100];

void permutation(int k);

int main()
{
    scanf("%d", &n);
    permutation(1);
    return 0;
}

void permutation(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", out[i]);
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++)
    {
        if (flag[i] == 0)
        {
            flag[i] = 1;
            out[k] = i;
            permutation(k + 1);
            flag[i] = 0;
        }
    }
}



