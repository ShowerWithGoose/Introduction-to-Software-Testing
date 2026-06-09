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
            for(j = i; j < n - 1; j++)
            {
                temp[j].factor = temp[j + 1].factor;
                temp[j].exponent = temp[j + 1].exponent;
            }
            i--;
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d %d ", temp[i].factor, temp[i].exponent); // @@ [The program does not remove terms with zero coefficients after combining like terms. In the test case, some combined terms may result in zero coefficient (e.g., if there were cancellation), but more critically, the merging loop is flawed: it only merges consecutive duplicates after sorting, but due to the shifting logic, it may miss merging all same-exponent terms if more than two share the same exponent. However, in this specific test case, the real issue is that the merging loop stops too early and doesn't handle all duplicates properly. But actually, looking at expected vs actual output: the buggy output has "555 2" while expected has "285 2 54 1". The term with exponent 1 is missing entirely in the buggy output. This indicates that during the merging process, when shifting elements left after merging, the loop condition and index management cause some terms (especially at the end) to be skipped or overwritten incorrectly. Specifically, after merging term i into i-1 and shifting, the new term at position i might have the same exponent as i-1 again, but because of `i--`, it will re-check. However, the bigger flaw is that the initial product generation includes all pairs, but the merging algorithm is unstable and loses terms. In particular, the term 54x^1 comes from 18*3 (from 18x^0 * 3x^1). This term exists in `ans` but gets lost during the merging/shifting process because when n is decremented and elements are shifted, the last element is never processed correctly. The loop runs while `i < n`, but after shifting, the new `n` is smaller, and the last few terms may be truncated. Moreover, the merging only checks adjacent pairs once per pass, but due to the shifting, it's possible that non-adjacent duplicates (though shouldn't happen after sort) — but actually after sorting by exponent descending, same exponents are adjacent. However, the critical bug is that when merging, the code reduces `n` and shifts, but the loop index `i` is decremented, which can cause the next iteration to reprocess the same index. However, in this case, the term with exponent 1 is never merged with anything (it's unique), so it should appear. Why is it missing? Because during the shifting process for earlier merges, the array is compacted, but the total number of terms `n` is reduced, and the unique term at the end might get overwritten or skipped. Specifically, the initial `n = 5*3 = 15`. After sorting, the exponents are: 15,13,10,9,8,7,5,4,3,2,2,2,1,0,... Wait, actually let's compute: 
First poly: 10x^8 + 2x^6 + 7x^3 + 5x^1 + 18x^0
Second: 30x^7 + 15x^2 + 3x^1
Products:
10*30 x^(15) = 300x^15
10*15 x^10 = 150x^10
10*3 x^9 = 30x^9
2*30 x^13 = 60x^13
2*15 x^8 = 30x^8
2*3 x^7 = 6x^7
7*30 x^10 = 210x^10 → combine with 150 → 360x^10
7*15 x^5 = 105x^5
7*3 x^4 = 21x^4
5*30 x^8 = 150x^8 → combine with 30 → 180x^8
5*15 x^3 = 75x^3
5*3 x^2 = 15x^2
18*30 x^7 = 540x^7 → combine with 6 → 546x^7
18*15 x^2 = 270x^2
18*3 x^1 = 54x^1

So terms by exponent:
15:300
13:60
10:360
9:30
8:180
7:546
5:105
4:21
3:75
2:15+270=285
1:54

But the buggy output ends with "555 2", meaning it computed 15+270+270? No, 15+270=285. The buggy output has 555 for exponent 2, which is wrong. Also missing exponent 1.

Looking at the merging loop:
It starts at i=1, compares temp[i-1] and temp[i].
After sorting in descending order, the exponents should be: 15,13,10,10,9,8,8,7,7,5,4,3,2,2,1

Wait, no: the products include:
x^15, x^13, x^10 (twice), x^9, x^8 (twice), x^7 (twice), x^5, x^4, x^3, x^2 (twice: from 5*3 and 18*15), and x^1 (once).

So sorted descending: 15,13,10,10,9,8,8,7,7,5,4,3,2,2,1

Now the merging loop:
i=1: 15 vs 13 → no merge
i=2: 13 vs 10 → no
i=3: 10 vs 10 → merge: temp[2].factor += temp[3].factor → becomes 360, then n=14, shift elements from i=3 onward left by one. Now array up to index 13.
Then i-- → i=2, next i++ → i=3
Now at i=3: compare temp[2] (360,10) and temp[3] (9,...) → no merge
Continue until i=5: temp[4]=9, temp[5]=8 → no
i=6: temp[5]=8, temp[6]=8 → merge: add, n=13, shift, i=5
Then i=6: now temp[5]=180 (8), temp[6]=7 → no
Similarly for 7s: merge at some point → 546
Then later for 2s: when i reaches the first 2 (say at position k), then i=k+1: compare temp[k] and temp[k+1] (both 2) → merge to 285, n decreases by 1, shift, so the x^1 term moves from position k+2 to k+1.
But then i is decremented to k, then i increments to k+1, and now temp[k] is 285 (exponent 2), temp[k+1] is 54 (exponent 1) → no merge, so it should print.

But the buggy output has "555 2" and no x^1. 555 = 285 + 270? That suggests that the 18*15=270 was added twice. Or perhaps the initial product generation is correct, but during the shifting, an extra term is included.

Wait, the real issue is in the merging loop: when it merges two terms, it shifts all elements from i to n-2, but the loop condition is `for(j = i; j < n - 1; j++)`, which is correct. However, after merging, `n` is decremented, and `i` is decremented so that the next iteration rechecks the same `i` (now pointing to the next term). This should work.

But why is the output showing 555 for exponent 2? 15 (from 5*3) + 270 (from 18*15) = 285. 555 is 285 + 270, meaning 270 was added twice.

Looking back at the product generation: 
a1 has 5 terms: indices 0 to 4
a2 has 3 terms: indices 0 to 2
So ans[0] = a1[0]*a2[0] = 10*30 x^15
ans[1] = 10*15 x^10
ans[2] = 10*3 x^9
ans[3] = 2*30 x^13
ans[4] = 2*15 x^8
ans[5] = 2*3 x^7
ans[6] = 7*30 x^10
ans[7] = 7*15 x^5
ans[8] = 7*3 x^4
ans[9] = 5*30 x^8
ans[10] = 5*15 x^3
ans[11] = 5*3 x^2  → 15x^2
ans[12] = 18*30 x^7
ans[13] = 18*15 x^2 → 270x^2
ans[14] = 18*3 x^1 → 54x^1

So two terms for x^2: ans[11] and ans[13]

After sorting by exponent descending, the order of exponents should be:
15,13,10,10,9,8,8,7,7,5,4,3,2,2,1

So the two x^2 terms are at positions 12 and 13 (0-indexed in temp after sorting).

In the merging loop:
When i=13 (since n=15 initially), temp[12] and temp[13] both exponent 2 → merge: temp[12].factor = 15+270=285, then n=14, and shift: temp[13] becomes what was temp[14] (54x^1). Then i is set to 12, then i increments to 13. Now i=13, and n=14, so loop condition i < n → 13<14 true. Compare temp[12] (285,2) and temp[13] (54,1) → no merge. Then i=14, loop ends.

So it should output 285 2 and 54 1.

But the buggy output has "555 2" and no 54 1. This suggests that the term 54x^1 was lost.

How? Let's simulate the merging step by step for the last few terms.

Assume after sorting, temp has:
index: 0:15, 1:13, 2:10, 3:10, 4:9, 5:8, 6:8, 7:7, 8:7, 9:5, 10:4, 11:3, 12:2, 13:2, 14:1

n=15

i=1: no
...
i=3: merge 10s → n=14, shift indices 3..13 to 2..12? Wait no:

When i=3 (so comparing temp[2] and temp[3]), after merge:
temp[2] = 360 (10)
then shift: for j from 3 to n-2 (13-1=12? n was 15, so n-1=14, j<14 → j=3 to 13)
temp[3] = temp[4] (9)
temp[4] = temp[5] (8)
...
temp[13] = temp[14] (1)
n becomes 14

Now the array has 14 elements: indices 0..13
exponents: 15,13,10,9,8,8,7,7,5,4,3,2,2,1

Then i=2 (after i--), then i=3 next.

Continue until i=5: temp[4]=9, temp[5]=8 → no
i=6: temp[5]=8, temp[6]=8 → merge
temp[5] = 30+150=180
n=13
shift j=6 to 12: temp[6]=temp[7] (7), ..., temp[12]=temp[13] (1)
Now array: 15,13,10,9,8,7,7,5,4,3,2,2,1 (13 elements)

i=5, then i=6
i=6: temp[5]=7, temp[6]=7 → merge to 546
n=12
shift: temp[6]=5, ..., temp[11]=1
Array: 15,13,10,9,8,7,5,4,3,2,2,1

i=5, then i=6: 7 vs 5 → no
...
i=10: temp[9]=3, temp[10]=2 → no
i=11: temp[10]=2, temp[11]=2 → merge to 285
n=11
shift: j=11 to 10 (n-2=10), so j<11 → j=11 not executed? Wait n=12 before merge, so n-1=11, j from 11 to 10 → loop doesn't run because 11<11 false.
So after merge, temp[10]=285, and n=11, but the x^1 term was at temp[11] before merge, and since no shift happened (because j starts at i=11 and n-1=11, so j < 11 is false), the x^1 term is lost!

Ah! Here's the bug: when merging the last two terms (at positions n-2 and n-1), after merging into position n-2, the code does:
n--;
for(j = i; j < n - 1; j++) { ... }

At the time of merge, i = n-1 (because we're at the last pair). For example, when n=12, the indices are 0..11. The two 2s are at 10 and 11, so i=11.
After merging, n becomes 11.
Then the loop: j from 11 to n-2 = 11-1-1 = 9? No: n is now 11, so n-1 = 10, so j < 10.
j starts at 11, which is not less than 10, so the loop doesn't run.
Thus, the term that was at position 11 (the x^1) is not shifted down, and is effectively lost because n is now 11, so only indices 0..10 are considered, and index 10 now holds the merged 285, but the x^1 was at 11 and is outside the new n.

Therefore, the error is in the merging loop: when merging the last two elements, the subsequent elements (if any) are not shifted because the loop condition fails. But in this case, after the two 2s, there is a x^1 term, which is at position i+1 = 12 when n=13? Let's re-express with correct indices.

Actually, before merging the two 2s, the array has:
indices: 0 1 2 3 4 5 6 7 8 9 10 11 12
exponents:15,13,10,9,8,7,5,4,3,2,2,1  → wait, that's 13 elements? No, after previous merges, let's say we have 13 elements including the x^1 at the end.

Suppose before merging the 2s, n=13, and the array is:
index: 0:15, 1:13, 2:10, 3:9, 4:8, 5:7, 6:5, 7:4, 8:3, 9:2, 10:2, 11:1  → that's 12 elements? I'm getting confused.

Better: initial n=15.
After merging the two 10s: n=14
After merging the two 8s: n=13
After merging the two 7s: n=12
Now the array has 12 terms: the exponents are 15,13,10,9,8,7,5,4,3,2,2,1

So indices 0 to 11.
The two 2s are at index 9 and 10, and the 1 is at index 11.

Now in the loop, i starts from 1 to 11 (since n=12).
When i=10: compare temp[9] and temp[10] (both 2) → merge.
Set temp[9].factor += temp[10].factor → 285
n = 12 - 1 = 11
Then shift: for j = i (10) to n-2 (11-1-1=9)? n is now 11, so n-1=10, so j < 10.
j starts at 10, which is not < 10, so no shift.
Thus, the term at index 11 (x^1) is not moved to index 10, and since n is now 11, the loop will only consider indices 0..10, and index 10 still has the old value (which was the second 2, but we don't care because we merged it), but the x^1 at index 11 is now beyond n-1=10, so it's excluded.

Hence, the x^1 term is lost.

The fix would be to shift from i to n-1 (old n), but the current code uses the new n.

The error is in the merging loop's shifting logic: it uses the decremented `n` in the loop condition, but should use the old `n`.

However, the problem asks to mark the line with @@.

The line where the error manifests is the shifting loop, but actually the root cause is that after merging, the code reduces `n` and then shifts using the new `n`, causing the last elements to be dropped.

But the immediate line that causes the loss is the for-loop condition in the shifting part.

However, looking at the code, the line that is most directly responsible is:

            for(j = i; j < n - 1; j++)

Because after `n--`, `n-1` is one less than it should be for the shift.

But the problem says: "If you think an error may occur on a particular line, add @@ symbol directly after that line"

So the line:

            for(j = i; j < n - 1; j++)

is where the error occurs.

But also, the line `n--;` is part of it.

However, the shifting loop is the one that fails to move the trailing elements.

Alternatively, the entire merging approach is flawed, but the specific line that causes the data loss is the for loop condition.

But note: the expected output has "285 2 54 1", but the buggy output has "555 2" — wait, 555? How did they get 555?

Wait, maybe there's another error: in the product generation, is there a miscalculation?

18*15 = 270, 5*3=15, so 285. But 555 = 285 + 270, which suggests that 270 was added twice.

Perhaps during the merging, because of the shifting error, the 270 term is not removed and gets merged again.

But in our simulation, the x^1 is lost, but the coefficient for x^2 is correct (285). However, the buggy output says "555 2", so maybe there's an additional error.

Wait, let's look at the buggy output: "300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 555 2"

It has 75 3, which is correct (5*15=75), then 555 2.

But 555 = 15 (5*3) + 270 (18*15) + 270? Where would the extra 270 come from?

Unless the term 18*15 is being added twice in the product generation.

But the product generation loops are:

for(i = 0; i < len1; i++)
    for(j = 0; j < len2; j++)

len1=5, len2=3, so 15 terms, which is correct.

Another possibility: the sorting is not stable or incorrect.

But the cmp function sorts by exponent descending, which is correct.

Wait, the real issue might be that the merging loop does not account for the fact that after shifting, there might be more than two terms with the same exponent. But in this case, only two terms per exponent.

But the output shows 555 for exponent 2, which is 15+270+270=555? 15+270=285, 285+270=555. So maybe the 270 term appears three times.

How? If the input parsing is wrong.

Look at the input parsing:

    for(i = 0; i < 50000; i++)
    {
        scanf("%d%d", &a1[i].factor, &a1[i].exponent);
        if(getchar() == 10)
            break;
    }
    const int len1 = i + 1;

For the first polynomial: "10 8 2 6 7 3 5 1 18 0"
This is 5 pairs, so i will be 4 when it breaks (because after reading the 5th pair, getchar() returns '\n').
So len1 = 4+1 = 5, which is correct.

Similarly for the second: "30 7 15 2 3 1" → 3 pairs, len2=3.

So product generation is correct.

Then why 555?

Perhaps during the merging, because of the shifting error, the 270 term is not removed and later gets merged again with something else.

But in our earlier simulation, the x^1 is lost, but the x^2 should be 285.

Unless the sorting is not grouping all same exponents together.

Let's check the cmp function:

int cmp(const void *p, const void *q)
{
    int x = *(int*)p, y = *(int*)q;
    if(ans[x].exponent > ans[y].exponent)
        return -1;
    if(ans[x].exponent < ans[y].exponent)
        return 1;
    return 0;
}

This sorts in descending order, and for equal exponents, it returns 0, so the order of equal exponents is preserved (stable sort in terms of original order, but qsort is not necessarily stable, but for merging, we only care that equals are adjacent).

So it should be fine.

Another possibility: the array `a` is used to sort indices, but `ans` is not changed, so when we do `temp[i] = ans[a[i]]`, it's correct.

But then the merging is done on `temp`.

Given the complexity, and since the expected output includes a term with exponent 1 that is missing in the buggy output, and the coefficient for exponent 2 is wrong, the primary error is in the merging loop's shifting logic, which drops terms at the end.

The line that is most directly responsible for the data loss is the for-loop that shifts elements, because it uses the decremented `n`.

So we mark that line.

Additionally, the final printing loop prints all `n` terms, but because of the shifting error, some terms are lost.

So the error is on the line:

            for(j = i; j < n - 1; j++)

But to be precise, the error is that after `n--`, the loop condition `j < n - 1` uses the new `n`, but it should use the old `n` (before decrement) for the upper bound.

However, the problem asks to mark the line with @@.

So:

            for(j = i; j < n - 1; j++) // @@ [After decrementing n, the loop condition uses the new n, causing the shift to not move all necessary elements, which results in loss of terms (like the x^1 term) and potential miscalculation of coefficients (like x^2 becoming 555 instead of 285 due to incomplete merging or double-counting from residual data).]

But wait, why 555? Let's calculate what the program might have done.

Suppose during the merging of the two 2s, the shift doesn't happen, so the array after merge at i=10 (with n=12) becomes:
- temp[9] = 285 (2)
- temp[10] = 270 (2) [old value, not overwritten]
- temp[11] = 54 (1)

Then n is set to 11.

Next, i is decremented to 9, then i becomes 10.

Now i=10, and n=11, so compare temp[9] (285,2) and temp[10] (270,2) → merge again!
So temp[9] = 285+270 = 555, n=10, and shift: but again, shift may not happen properly.

Then the x^1 term is at temp[11], which is beyond n=10, so lost.

This explains 555 and missing x^1.

So the error is that after merging and not shifting, the next iteration sees another duplicate because the old value is still there.

Hence, the shifting loop is critical.

Therefore, the line with the for loop is where the error occurs.