#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2)
{
    int *a = (int *)p1;
    int *b = (int *)p2;
    return b[1] - a[1]; // @@ [The comparison function treats each element as an int array of size 2, but qsort passes pointers to elements of type int[2]. This cast is incorrect; it should cast to a pointer to the actual element type (e.g., int(*)[2]) or use proper struct. However, in practice this may work due to memory layout, but it's unsafe and not the main bug.]
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
            ans[i + 1][0] = 0; // @@ [This merging logic only merges consecutive duplicate exponents once and only forward. It fails to handle cases where more than two terms have the same exponent or when duplicates are not adjacent after sorting. Also, it overwrites ans[i+1] but doesn't remove it, leading to leftover zero-coefficient terms that might interfere if not filtered properly. More critically, it doesn't accumulate all like terms—only pairwise from left to right.]
        }
    }
    for(i = 0; i < k; i++)
    {
        if(ans[i][0] != 0)
            printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}