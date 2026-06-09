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
    const int len1 = i + 1; // @@ [If the input line is empty or only has one term, `i` may be 0, but more critically, if the loop breaks on first iteration, `len1 = 1` is correct. However, the real issue is that if no input is given (though problem states there will be non-zero terms), this could be problematic. But the main error lies elsewhere.]
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    // @@ [Same as above, but again not the primary bug.]
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
    qsort(a, n, sizeof(int), cmp); // @@ [`cmp` function uses global array `ans`, which is fine, but note: `cmp` expects to sort indices based on `ans`'s exponents in descending order. However, the logic in `cmp` returns -1 when `ans[x].exponent > ans[y].exponent`, which correctly sorts in descending order. So this is okay.]
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++) // @@ [This merging loop has an off-by-one and shifting logic error. When merging terms with same exponent, it shifts elements left by overwriting `temp[j]` with `temp[j+1]`, but after decrementing `n`, the loop condition becomes `j < n - 1`. However, when `i` is decremented (`i--`), and if multiple consecutive duplicates exist, it may skip some or access out-of-bound. More critically, if the last two terms are merged, `n` becomes `n-1`, and then `i` goes to `n-1`, but the loop condition is `i < n`, which is now smaller. However, the worst issue is that after shifting, the next term to compare is not properly handled in all cases. But the most severe error is below:]
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ [When `n` is decremented, `n-1` becomes the new last index. But if `i == n-1` before decrement, then after `n--`, `n-1` becomes `i-1`, so `j < n - 1` becomes `j < i - 1`, and the loop doesn't run. That's okay. But if `i` is not the last, then we shift. However, the real critical error is that if `temp[i].factor` becomes zero after merging, the code does not remove zero-coefficient terms. The problem states: "Only terms with non-zero coefficients will appear in the input", but output must also only include non-zero terms. If merging results in zero coefficient, it should be removed. This program does not check for zero coefficients after addition, leading to incorrect output including zero terms.]
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--;
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent); // @@ [This prints even zero-coefficient terms if they resulted from cancellation (e.g., (x - x) * something). The problem requires only non-zero terms in output. So if any `temp[i].factor` is zero, it should not be printed. This is a logical error causing wrong output.]
    
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