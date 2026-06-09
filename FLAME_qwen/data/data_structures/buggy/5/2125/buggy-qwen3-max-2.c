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
    const int len1 = i + 1; // @@ [This sets len1 to one more than the actual number of terms read. If the loop breaks at i=0 (first term), then len1 becomes 1, which is correct, but note that i is the index of the last successfully read term, so number of terms is i+1 — this part is actually correct. However, the real issue lies elsewhere.]
    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a2[i].factor, &a2[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len2 = i + 1;    // @@ [Same as above: logically correct for counting, but potential issue if input has no terms — though problem states non-zero terms exist. Not the main bug.]
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
    qsort(a, n, sizeof(int), cmp); // @@ [The cmp function uses global array 'ans', but during sorting, 'ans' is not modified. However, the bigger issue is that 'cmp' compares based on 'ans[x].exponent', but after combining like terms later, the indices in 'a' become stale. But more critically: the 'cmp' function signature expects to compare elements of the array being sorted — here, 'a' contains indices, so cmp is written correctly for that. However, there's a deeper flaw in term combination logic.]
    for(i = 0; i < n; i++)
    {
        temp[i].factor = ans[a[i]].factor;
        temp[i].exponent = ans[a[i]].exponent;
    }
    for(i = 1; i < n; i++) // @@ [This loop attempts to combine like terms, but it only checks consecutive terms after sorting. However, due to the way shifting is done (copying from j+1 to j), it may skip terms or fail to merge all duplicates if more than two terms share the same exponent. Also, if a combined term becomes zero coefficient, it is not removed — but problem says input has non-zero coefficients, and multiplication of non-zero ints can be non-zero, but sum could be zero! The program does not handle zero-coefficient terms, which should be omitted in output. This is a critical logical error.]
    {
        if(temp[i - 1].exponent == temp[i]. exponent)
        {
            temp[i - 1].factor += temp[i].factor;
            n--;
            for(j = i; j < n - 1; j++) // @@ [Off-by-one error: when n is decremented, the loop condition should be j < n (not n-1) to copy the last element. As written, the last valid element at index n (before decrement) is not copied down, causing data loss or incomplete merging. Also, after shifting, the next term to compare is now at position i, but the loop increments i, so it may miss merging a chain of three or more same exponents.]
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--; // @@ [This tries to re-check the current position after shift, but due to flawed shifting logic above, it may not work correctly for multiple merges.]
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent); // @@ [Does not check for zero coefficients. If temp[i].factor becomes zero after merging (e.g., 3x^2 + (-3)x^2), it will still be printed, violating the requirement that only non-zero terms appear in output.]
    
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