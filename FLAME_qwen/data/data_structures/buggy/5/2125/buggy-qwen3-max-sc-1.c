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
    const int len1 = i + 1; // @@ [If the input line is empty (no terms), i will be 0 and len1 becomes 1, but no valid term was read. Also, if break happens at i=0, then a1[0] was read, so len1=i+1 is correct only if loop breaks after reading one term. However, more critically: if input ends immediately (e.g., blank line), scanf fails and behavior is undefined. But main issue is below.]
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
    qsort(a, n, sizeof(int), cmp); // @@ [The cmp function uses global array 'ans', which is fine, but note that 'n' might be 0 if either polynomial has 0 terms, leading to undefined behavior in qsort with size 0? Not critical. Main error is elsewhere.]
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++) // @@ [This merging loop is flawed: it only merges consecutive duplicates after sorting, but due to the way shifting is done (copying next elements left), it may skip checking newly adjacent duplicates. More importantly, if multiple terms have same exponent, this loop may not merge all of them correctly because after shifting, the next term moves to current index, but then i increments, skipping comparison with previous. The i-- tries to fix this, but logic is fragile and may access out-of-bound when n changes. However, the real critical error is earlier.]
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ [When n is reduced, the upper bound becomes n-1, but if n becomes 1, then j < 0, loop doesn't run. However, the bigger issue: if after merging, the new temp[i] (which was temp[i+1]) has same exponent as temp[i-1], it won't be merged because i increments next. The i-- helps, but this approach is inefficient and error-prone. Still, not the root cause of test failure.]
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