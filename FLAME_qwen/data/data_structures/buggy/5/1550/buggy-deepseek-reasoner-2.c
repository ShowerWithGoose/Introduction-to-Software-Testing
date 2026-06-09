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
    int a[20][2]; @@ Array size may be too small for the number of polynomial terms (reference uses 500).
    int b[20][2]; @@ Array size may be insufficient for the number of polynomial terms.
    int ans[50][2]; @@ Array size may be too small for the product (up to 20*20=400 terms needed).
    char c = '0';
    int i, j, k = 0;
    int num_fst = 0, num_scd = 0;
    while(c != '\n')
    {
        scanf("%d%d%c",&a[num_fst][0], &a[num_fst][1], &c);
        num_fst++;
    }
    c = '0';
    while(c != '\n')
    {
        scanf("%d%d%c",&b[num_scd][0], &b[num_scd][1], &c);
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

    for(i = 0; i < k - 1; i++) @@ This loop fails to properly combine more than two terms with the same exponent; it only combines consecutive pairs once, leaving multiple entries with the same exponent after zeroing.
    {
        if(ans[i][1] == ans[i + 1][1]) @@ The combination logic does not handle groups of more than two equal exponents correctly; it will leave residual non-zero terms.
        {
            ans[i][0] += ans[i + 1][0];
            ans[i + 1][0] = 0;
        }
    }
    for(i = 0; i < k; i++)
    {
        if(ans[i][0] != 0)
            printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}