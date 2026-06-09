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
    const int len1 = i + 1; // @@ [This sets len1 to one more than the actual number of terms read. If the loop breaks at i=0 (first term), then len1 becomes 1, which is correct, but note that i is the index of the last successfully read term, so number of terms is i+1. However, this is actually correct logic. The real issue is elsewhere.]
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    // @@ [Same as above: this is actually correct. The real bug is in the merging/combining step and sorting logic.]
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
    qsort(a, n, sizeof(int), cmp); // @@ [The cmp function uses global array 'ans', which is fine, but note that after sorting indices, the next loop copies into 'temp' in sorted order. However, the merging loop that follows assumes the array is sorted in descending order, but the cmp function sorts in descending order by returning -1 when ans[x].exponent > ans[y].exponent, which is correct for descending. So sorting is okay.]
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++) // @@ [This merging loop has a critical flaw: it only merges consecutive duplicate exponents. However, due to the way elements are shifted left after merging, it may skip checking some duplicates if there are more than two terms with the same exponent. Also, the shifting logic is inefficient and error-prone. More importantly, if after merging, the new term (at i-1) now has the same exponent as the next one (i+1 originally, now at i after shift), the i-- causes rechecking, which seems okay, BUT the initial sort must be stable and complete. However, the bigger issue is that the loop condition uses 'n' which is being decremented, and the shifting is done manually, which can lead to missing merges or out-of-bound access. But the most critical error is that zero-coefficient terms are not removed. If two terms cancel out (e.g., +5x^2 and -5x^2), the resulting coefficient becomes 0, but the program still outputs it, which violates the problem requirement that only non-zero terms should be output.]
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ [This loop shifts elements left to fill the gap, but note: after decrementing n, the valid indices are 0 to n-1. The loop runs from j=i to j < n-1, so it copies from j+1 to j, which is correct. However, if the merged coefficient becomes zero, it's still kept in the array and will be printed, which is wrong.]
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--;
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent); // @@ [This prints all terms, including those with zero coefficients, which violates the problem statement that only non-zero terms should appear in the output. This is a major logical error.]
    
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