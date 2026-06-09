/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int factor, exponent;
}term;

int cmp(const void*, const void*);

term a1[50000], a2[50000], ans[50000], temp[50000];

int main()
{
    int i, j;
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a1[i].factor, &a1[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len1 = i + 1; // @@ [If the input line is empty (no terms), i will be 0 and len1 becomes 1, but no valid term was read. Also, if break happens at i=0, then a1[0] was read but loop breaks after incrementing i to 0, so len1 = 1 is correct. However, more critically: if the input has only one term, getchar() consumes the newline after reading two integers, which is okay. But the real issue is in the combination logic later.]
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    // @@ [Same potential off-by-one concern as above, but actually correct if at least one term exists. However, if input is malformed or empty, behavior is undefined. But main bug lies elsewhere.]
    int n = len1 * len2;
    for(i = 0; i < len1; i++)
    {
        for(j = 0; j < len2; j++)
        {
            ans[i * len2 + j].factor = a1[i].factor * a2[j].factor;
            ans[i * len2 + j].exponent = a1[i].exponent + a2[j].exponent;
        }
    }
    int a[50000] = {};
    for(i = 0; i < n; i++)
        a[i] = i;
    qsort(a, n, sizeof(int), cmp); // @@ [The cmp function uses global array 'ans', but during sorting, 'ans' is not modified. However, the real problem is that 'cmp' compares based on 'ans[x].exponent', but if multiple terms have same exponent, they are not grouped correctly before merging. Also, using an index array adds unnecessary complexity and potential for error.]
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++) // @@ [This merging loop is flawed: when combining like terms, it shifts elements left by overwriting temp[j] with temp[j+1], but it does not handle cases where more than two terms share the same exponent. Also, after merging term i into i-1, it decrements i to re-check, but the shifting may cause missed merges or out-of-bound access if n becomes small. Moreover, if the last term is merged, n-- makes the loop condition invalid.]
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ [Loop condition should be j < n (after decrement), but here it's j < n - 1, so the last element isn't shifted properly. Also, after n--, the valid indices are 0 to n-1, so to shift from i onward, we need to copy from j+1 up to original n-1, which now is n (before decrement). This causes the last element to be dropped incorrectly or not shifted fully.]
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--;
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent);
    
    return 0;
}

int cmp(const void *p, const void *q)
{
    int x = *(int*)p, y = *(int*)q;
    if(ans[x].exponent > ans[y].exponent)
        return -1;
    if(ans[x].exponent < ans[y].exponent)
        return 1;
    return 0;
}