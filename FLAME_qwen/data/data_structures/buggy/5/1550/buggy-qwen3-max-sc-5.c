#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2)
{
    int *a = (int *)p1; // @@ [The comparison function incorrectly treats each element as an int array, but qsort passes pointers to elements of type int[2]. The correct approach is to cast to int(*)[2] or use proper struct. This leads to undefined behavior during sorting.]
    int *b = (int *)p2; // @@ [Same issue as above: casting to int* instead of handling the 2-element array correctly.]
    return b[1] - a[1]; // @@ [Due to incorrect pointer casting, accessing b[1] and a[1] may read invalid memory, causing undefined behavior.]
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
    qsort(ans, k, sizeof(ans[0]), cmp); // @@ [Passing a comparison function that misinterprets the data layout causes undefined behavior during sorting.]

    for(i = 0; i < k - 1; i++)
    {
        if(ans[i][1] == ans[i + 1][1])
        {
            ans[i][0] += ans[i + 1][0];
            ans[i + 1][0] = 0; // @@ [This only zeroes the next term but doesn't remove it or shift subsequent terms, leading to duplicate exponents and potential zero-coefficient terms being printed later.]
        }
    }
    for(i = 0; i < k; i++)
    {
        if(ans[i][0] != 0)
            printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}