#include <stdio.h>
#include <stdbool.h>

#define MAX_N (15)

void perm(int n, int step, bool isNotUsed[], int numPerm[]);

int main()
{
    int n;
    scanf("%d", &n);

    bool isNotUsed[MAX_N];
    int numPerm[MAX_N];

    for (int i = 0; i < MAX_N; ++i)
    {
        isNotUsed[i] = true;
        numPerm[i] = 0;
    }

    perm(n, 1, isNotUsed, numPerm);
}

void perm(int n, int step, bool isNotUsed[], int numPerm[])
{
    if (step == n + 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            printf("%d%c", numPerm[i], (i == n) ? '\n' : ' ');
        }
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (isNotUsed[i])
        {
            isNotUsed[i] = false;
            numPerm[step] = i;
            perm(n, step + 1, isNotUsed, numPerm);
            isNotUsed[i] = true;
            numPerm[step] = 0;
        }
    }
}


