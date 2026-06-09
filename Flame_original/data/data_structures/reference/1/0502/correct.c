//5. 全排列数的生成

#include <stdio.h>

#define SIZE 50

void permutation(int *number, int *is_done, int n, int depth);

int main()
{
    int n;
    int number[SIZE] = {0};
    int is_done[SIZE] = {0};
    scanf("%d", &n);
    permutation(number, is_done, n, 1);
    return 0;
}

void permutation(int *number, int *is_done, int n, int depth)
{
    int i;
    if (depth == n + 1)
    {
        for (i = 1; i <= n; i++)
        {
            printf("%d ", number[i]);
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= n; i++)
    {
        if (is_done[i] == 0)
        {
            is_done[i] = 1;
            number[depth] = i;
            permutation(number, is_done, n, depth + 1);
            is_done[i] = 0;
        }
    }
}



