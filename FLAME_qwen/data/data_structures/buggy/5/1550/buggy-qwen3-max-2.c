#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2)
{
    int *a = (int *)p1; // @@ [The comparison function incorrectly treats each element as an int array, but 'ans' is an array of arrays (2D), so each element passed to qsort is of type int[2]. Casting to 'int*' and accessing b[1] leads to undefined behavior because the actual structure is not a flat int array. It should cast to a pointer to the actual element type, e.g., int(*)[2], or use proper struct handling like in the reference.]
    int *b = (int *)p2; // @@ [Same issue as above: incorrect casting and indexing in comparison function.]
    return b[1] - a[1]; // @@ [This relies on the flawed assumption that p1 and p2 point to int arrays where index 1 is the exponent. While it may appear to work due to memory layout, it's technically undefined behavior and fragile. Moreover, it doesn't handle equal exponents correctly during sort stability, but more critically, the merging logic later assumes sorted order but doesn't fully combine all same-exponent terms.]
}

int main()
{
    int a[20][2];
    int b[20][2];
    int ans[50][2];
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

    for(i = 0; i < k - 1; i++)
    {
        if(ans[i][1] == ans[i + 1][1])
        {
            ans[i][0] += ans[i + 1][0];
            ans[i + 1][0] = 0; // @@ [This only merges adjacent duplicate exponents once and sets the next term's coefficient to zero, but does not remove or shift elements. If there are more than two terms with the same exponent, they won't be fully combined. Also, zero-coefficient terms are printed unless filtered, but the filtering happens later—however, the merging is incomplete for >2 same exponents.]
        }
    }
    for(i = 0; i < k; i++)
    {
        if(ans[i][0] != 0)
            printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}