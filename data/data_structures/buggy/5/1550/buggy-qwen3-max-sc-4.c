#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2)
{
    int *a = (int *)p1; // @@ [The comparison function incorrectly treats each element as an int array, but ans is an array of arrays (2D), so each element passed to qsort is a 2-element array. Casting to int* and accessing b[1] leads to undefined behavior because p1 and p2 point to the first element of each 2-element subarray, not to an array of ints. It should cast to a pointer to the actual element type, e.g., int(*)[2], or use proper struct.]
    int *b = (int *)p2; // @@ [Same issue as above: incorrect casting in comparison function for qsort when used with 2D array.]
    return b[1] - a[1];
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
    qsort(ans, k, sizeof(ans[0]), cmp); // @@ [qsort is used with a 2D array and a comparison function that assumes elements are int*, but each element is actually an array of 2 ints. The comparison function must treat each element as int[2], not int*. This causes undefined behavior during sorting.]

    for(i = 0; i < k - 1; i++)
    {
        if(ans[i][1] == ans[i + 1][1])
        {
            ans[i][0] += ans[i + 1][0];
            ans[i + 1][0] = 0; // @@ [This only zeroes the next term but doesn't remove it or shift subsequent terms. Later, zero-coefficient terms are skipped in output, but this approach fails to combine more than two like terms correctly (e.g., three terms with same exponent). Also, after combining, the next term may still have same exponent as current, but loop moves forward without rechecking.]
        }
    }
    for(i = 0; i < k; i++)
    {
        if(ans[i][0] != 0)
            printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}