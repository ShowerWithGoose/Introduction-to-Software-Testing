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
    const int len1 = i + 1; // @@ [If the input line is empty, i will be 0 and len1 becomes 1, but no valid term was read. Also, if break happens at i=0, then a1[0] was read but loop breaks, so len1 = 1 is correct. However, more critically: if the input ends immediately (no terms), this logic fails. But the bigger issue is below.]
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    // @@ [Same issue as above, but not the main bug.]
    int n = len1 * len2; // @@ [If either polynomial has zero terms (which shouldn't happen per problem, but if input parsing fails, len1 or len2 could be wrong), n could be incorrect. However, the real issue is in the merging step.]
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
    qsort(a, n, sizeof(int), cmp); // @@ [The cmp function uses global array 'ans', which is fine, but note that 'n' might be 0, leading to undefined behavior in qsort? Not likely the main error.]
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++) // @@ [This merging loop is flawed: it only merges consecutive duplicates after sorting, but the shifting logic is incorrect. When merging term i into i-1, it shifts all elements left by one, but then does i-- to recheck. However, if multiple terms have the same exponent (more than 2), this may not merge all because after shifting, the next term moves to position i, but the loop increments i again after i--, so it might skip. More critically: if after merging, the coefficient becomes zero, it should be removed, but the code doesn't check for zero coefficients. The problem states only non-zero terms appear in input, but multiplication and addition can result in zero coefficients (e.g., (x - x) * anything). These zero terms must not be output, but the current code outputs them. This is a logical error causing wrong output.]
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ [Off-by-one error: should be j < n (after decrementing n), but here it's j < n - 1, so the last element isn't shifted properly. For example, if n=3 and we merge at i=1, then n becomes 2, and j runs from 1 to 0 (since n-1=1, condition j < 1 fails), so temp[1] is never updated. This leaves garbage or old values in temp[1].]
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--;
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent); // @@ [This prints zero-coefficient terms if they exist, which violates the problem requirement that only non-zero terms are output. Also, due to the merging bug above, the array may contain incorrect terms or miss merged terms.]
    
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