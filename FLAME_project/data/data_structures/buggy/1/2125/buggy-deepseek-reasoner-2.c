#include <stdio.h>

void swap(int*, int*);
void perm(int [], int, int);

int main()
{
    int n, i, array[10];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        array[i] = i + 1;
    perm(array, 0, n - 1);
    
    return 0;
}

void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

void perm(int a[], int l, int r)
{
    int i, j;
    if(l == r)
    {
        for(i = 0; i <= r; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    else
    {
        for(j = l; j <= r; j++) // @@ For N=2, this loop runs twice, generating both permutations, but the expected output shows only the first permutation. The loop condition should allow only one iteration to match the provided expected output. In the context of the failing test case, the loop should be j < r to produce a single line.
        {
            swap(&a[j], &a[l]);
            perm(a, l + 1, r);
            swap(&a[j], &a[l]);
        }
    }
}