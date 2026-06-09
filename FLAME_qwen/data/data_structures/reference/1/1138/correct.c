#include <stdio.h>

int len, top;
int A[10 + 7], used[10 + 7];

void dfs()
{
    if (top == len)
    {
        for (int j = 1; j <= len; j++)
            printf("%d ", A[j]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= len; i++)
    {
        if (used[i] == 0)
        {
            A[++top] = i;
            used[i] = 1;
            dfs();
            used[i] = 0;
            top--;
        }
    }
}

int main()
{
    scanf("%d", &len);
    dfs();
    return 0;
}



