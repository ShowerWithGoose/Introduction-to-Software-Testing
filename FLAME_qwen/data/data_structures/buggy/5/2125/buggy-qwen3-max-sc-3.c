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
    const int len1 = i + 1; // @@ [If the input line is empty, i will be 0 and len1 becomes 1, but no term was actually read. Also, if break happens at i=0, then a1[0] was read, so len1=i+1 is correct only if loop breaks after reading one pair. However, more critically: if the input ends immediately (e.g., blank line), scanf may fail, leading to undefined behavior. But the main error is elsewhere.]
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    // @@ [Same issue as above, but not the primary bug causing wrong output.]
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
    qsort(a, n, sizeof(int), cmp); // @@ [The cmp function uses global array 'ans', but during sorting, the indices in 'a' refer to positions in 'ans'. However, after this sort, the code copies ans[a[i]] into temp, which is okay. BUT: the real problem is that the merging loop assumes terms are sorted in descending order, but the merging logic is flawed. However, the critical error is in the merging loop below.]
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++) // @@ [This merging loop only merges consecutive duplicate exponents. However, due to the way shifting is done (copying next elements left), it may skip checking newly adjacent duplicates after a merge. More importantly, if multiple terms have the same exponent, they might not all be merged because after shifting, the next term moves into position i, but then i is decremented, so it gets checked again — this part is actually okay. The bigger issue: if a merged term becomes zero coefficient, it should be removed, but the code doesn't handle zero coefficients. However, the test case likely fails due to incorrect merging logic when non-consecutive duplicates exist — but wait: the array is sorted by exponent (descending), so duplicates must be consecutive. So why failure? Let's look deeper.]
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ [This loop shifts elements left by one, but it runs from j=i to j < n-1, meaning it copies temp[j+1] to temp[j]. However, after decrementing n, the last valid index is n-1, so we need to shift up to j = n-1 (old n-2). But the loop condition j < n - 1 uses the new n, so it stops one short. For example, if n was 5 and becomes 4, then j goes from i to 2 (if i=1), but we need to shift element at old index 4 (now beyond new n) — actually, the element at old index n-1 (which is now beyond new n) is not needed. However, the real bug: after merging, if the resulting coefficient becomes zero, the term should be removed, but the code doesn't check for zero coefficients. This causes output of zero-coefficient terms, which violates the problem requirement (only non-zero terms should be output). Additionally, the shifting loop does not handle the case where multiple merges are needed correctly, but the main issue is zero coefficients not being removed.]
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--;
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent); // @@ [This prints even zero-coefficient terms, which is invalid per problem statement (only non-zero terms should appear). Also, if all terms cancel out, it should print nothing, but this would print zeros.]
    
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