#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2)
{
    int *a = (int *)p1;
    int *b = (int *)p2;
    return b[1] - a[1];
}

int main()
{
    int a[20][2];
    int b[20][2];
    int ans[50][2]; // @@ Array size is too small; multiplying two polynomials can produce up to 400 terms, causing buffer overflow.
    char c = '0';
    int i, j, k = 0;
    int num_fst = 0, num_scd = 0;
    while(c != '\n')
    {
        scanf("%d%d%c",&a[num_fst][0], &a[num_fst][1], &c); // @@ Using %c without skipping whitespace may read spaces instead of newlines, causing incorrect loop termination or reading garbage data.
        num_fst++;
    }
    c = '0';
    while(c != '\n')
    {
        scanf("%d%d%c",&b[num_scd][0], &b[num_scd][1], &c); // @@ Same issue as above; fragile parsing logic for input termination.
        num_scd++;
    }
    for(i = 0; i < num_fst; i++)
    {
        for(j = 0; j < num_scd; j++)
        {
            ans[k][0] = a[i][0] * b[j][0];
            ans[k++][1] = a[i][1] + b[j][1]; 
        }
    }
    qsort(ans, k, sizeof(ans[0]), cmp);

    for(i = 0; i < k - 1; i++)
    {
        if(ans[i][1] == ans[i + 1][1]) // @@ The merging logic is incorrect; it only merges adjacent pairs once and fails to properly combine three or more terms with the same exponent.
        {
            ans[i][0] += ans[i + 1][0]; // @@ Incorrect accumulation; coefficients are not summed across all like terms.
            ans[i + 1][0] = 0; // @@ Incorrectly zeroes out terms instead of shifting or properly merging, leading to fragmented results.
        }
    }
    for(i = 0; i < k; i++)
    {
        if(ans[i][0] != 0)
            printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}