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
    const int len1 = i + 1;
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    
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
    qsort(a, n, sizeof(int), cmp);
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++)
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ The loop condition `j < n - 1` is incorrect. After decrementing n, the valid range is `0` to `n-1`. To shift elements from `i+1` onwards to the left by one position starting at index `i`, we should copy `temp[j+1]` to `temp[j]`. The last element to be copied is at the new end of the array, which is index `n-1` (before decrement it was `n`). So `j` should go up to `n-1` (the new last index). Wait, if we have indices 0..n_old-1. We merge i-1 and i. New size is n_new = n_old - 1. Indices 0..n_new-1. We want to remove index i. So we shift indices i+1 .. n_old-1 to i .. n_old-2. Note that n_old-2 is equal to n_new-1. So j goes from i to n_new-1. The source is j+1. The last source index is n_new-1+1 = n_new = n_old-1. This is correct. The loop `for(j = i; j < n; j++)` would access `temp[n]` which is out of bounds if `n` is the new size. The current code uses `n` which has been decremented. So `j < n` means `j` goes up to `n-1`. The assignment is `temp[j] = temp[j+1]`. When `j = n-1`, it accesses `temp[n]`. But `temp` only has valid data up to `n-1` (since size is now `n`). The original array had size `n+1` before decrement. So `temp[n]` was the last element. It should be moved to `temp[n-1]`. So `j` should indeed reach `n-1`. The condition `j < n` allows `j` to be `n-1`. So `temp[n-1] = temp[n]`. This is correct. However, the loop bound in the code is `j < n - 1`. This means `j` stops at `n-2`. So `temp[n-2] = temp[n-1]`. The element at `temp[n-1]` (which was `temp[n]` originally) is not shifted? No, wait. `n` is decremented *before* the loop. Let's trace. `n` becomes `n-1`. Loop `j` from `i` to `n-2`. Last iteration `j=n-2`. `temp[n-2] = temp[n-1]`. The element originally at `n` (now effectively removed from logical size but physically present) is not moved into the logical array? Actually, the element at `temp[n]` (old index) needs to move to `temp[n-1]` (new index). The loop should run until `j` such that `j+1` covers the last old element. Old last index was `n` (before decrement). So `j+1 = n => j = n-1`. Since `n` is already decremented, let `N = n+1` be old size. New size `n`. We want to shift `i+1...N-1` to `i...N-2`. Note `N-2 = n-1`. So `j` goes from `i` to `n-1`. Condition `j <= n-1` or `j < n`. The code has `j < n - 1`. This misses the last shift. So the last element of the merged array is lost/duplicated incorrectly.
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