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
        for(j = l; j <= r; j++)  // @@ The swapping-backtracking method does not generate permutations in lexicographic order for N > 2; for N=2 it coincidentally matches, but the expected output implies the problem requires lexicographic order (which for N=2 is only the first permutation? Actually both permutations are in order, but the test case shows only one line, suggesting a discrepancy.)
        {
            swap(&a[j], &a[l]); // @@ This swap and recursion produce all permutations, but the order may not be lexicographically sorted, leading to wrong answer for larger N.
            perm(a, l + 1, r);
            swap(&a[j], &a[l]);
        }
    }
}