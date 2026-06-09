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
    for(i = 1; i < n; i++) // @@ The loop condition and logic for merging terms are flawed. When terms are merged and shifted, the array size `n` decreases, but the loop bound `n` is updated inside the loop while `i` might skip checks or go out of bounds relative to the new logical size. More critically, if the last term has a unique exponent, it is never checked against a previous one if it's the only one left, but the main issue is that terms with coefficient 0 are not filtered out, and the shifting logic is inefficient and prone to errors if multiple consecutive merges happen. However, the specific error causing the missing terms in the output is likely due to the fact that the merging loop `for(i = 1; i < n; i++)` combined with `i--` and `n--` can lead to incorrect indexing or skipping elements if not handled perfectly. A more robust standard approach is needed. But looking closely at the provided buggy output vs expected: `285 2 54 1` are missing. This suggests terms with exponents 2 and 1 were either merged incorrectly into zero (if coefficients cancelled out, which they don't here) or lost. Let's re-examine the merging logic. If `temp[i-1].exponent == temp[i].exponent`, we merge. The problem description says input has non-zero coefficients. The multiplication results might have same exponents. The `qsort` sorts by exponent descending. The merging loop combines adjacent terms with same exponent. If the result of addition is 0, it should ideally be removed, but the problem doesn't explicitly say to remove zero coefficients in output, though standard polynomial representation does. However, the missing terms `285 2` and `54 1` in the buggy output suggest they were completely lost. Wait, looking at the expected output: `... 75 3 285 2 54 1`. The buggy output ends at `... 75 3 555 2`. It seems `555 2` is present in buggy but `285 2` and `54 1` are expected. This implies the buggy code calculated `555` for exponent 2? Let's check the math.
    // Term 1: 10x^8, 2x^6, 7x^3, 5x^1, 18x^0
    // Term 2: 30x^7, 15x^2, 3x^1
    // Exp 2 terms:
    // 2x^6 * ? No.
    // 7x^3 * ? No.
    // 5x^1 * 3x^1 = 15x^2.
    // 18x^0 * 15x^2 = 270x^2.
    // Total coeff for x^2 = 15 + 270 = 285.
    // Exp 1 terms:
    // 5x^1 * ? No other x^0 in poly2? Wait, poly2 has no x^0 term.
    // 18x^0 * 3x^1 = 54x^1.
    // Total coeff for x^1 = 54.
    
    // Why did the buggy code output 555 for exp 2?
    // And miss exp 1?
    // The merging logic `temp[i - 1].factor += temp[i].factor;` is correct for accumulation.
    // The shift logic:
    // for(j = i; j < n - 1; j++) temp[j] = temp[j+1];
    // n--;
    // i--;
    // This effectively removes temp[i] (the second one) and keeps temp[i-1] (the merged one).
    // Then i-- makes the next iteration check the new temp[i] (which was temp[i+1]) against temp[i-1] again.
    // This logic seems theoretically sound for merging adjacent duplicates in a sorted list.
    
    // However, there is a subtle bug in `qsort` comparator or the merging if `n` becomes 0 or 1.
    // Actually, the most likely error in such student code is often related to how `getchar()` consumes newlines or spaces, leading to incorrect parsing of the second polynomial.
    // In the input loop:
    // scanf("%d%d", ...); getchar();
    // If the input is "10 8 2 6 ... 18 0\n", scanf reads 18 and 0. getchar() reads '\n'. Break.
    // Next loop: scanf("%d%d", ...); reads 30 and 7. getchar() reads ' '. Not '\n'. Continue.
    // Reads 15 and 2. getchar() reads ' '. Continue.
    // Reads 3 and 1. getchar() reads '\n'. Break.
    // This parsing seems correct for the given format.
    
    // Let's look at the `cmp` function.
    // It uses global `ans`. `qsort` sorts indices `a` based on `ans` exponents.
    // This is correct.
    
    // Is it possible that `temp` array initialization or size is an issue? No, 50000 is large enough.
    
    // Let's re-read the buggy output: `... 75 3 555 2`.
    // Expected: `... 75 3 285 2 54 1`.
    // Where does 555 come from?
    // 555 = 285 + 270? No.
    // 555 = 54 + 501?
    // Maybe the term `54 1` was merged into `285 2`? No, exponents are different.
    // Maybe the term `54 1` was not generated?
    // If `len2` was parsed incorrectly, e.g., missing the last term `3 1`?
    // If poly2 was just `30 7 15 2`, then:
    // Exp 2: 18*15 = 270.
    // Exp 1: None.
    // Exp 3: 5*15=75, 18*? No. 7*? No.
    // This doesn't match 555.
    
    // What if poly1 was parsed incorrectly?
    
    // Actually, there is a known issue with `scanf` and `getchar` mixing.
    // But the specific error location requested is usually a logical one.
    
    // Let's look at the merging loop again.
    // for(i = 1; i < n; i++)
    // If n changes, the loop condition `i < n` updates.
    // If we merge at i=1, n becomes n-1, i becomes 0. Next iter i=1.
    // This checks temp[0] and temp[1]. Correct.
    
    // One possibility: The `qsort` is unstable? No, doesn't matter for grouping.
    
    // Let's look at the `cmp` function again.
    // if(ans[x].exponent > ans[y].exponent) return -1;
    // if(ans[x].exponent < ans[y].exponent) return 1;
    // return 0;
    // This sorts in descending order of exponent. Correct.
    
    // Is it possible that `ans` contains garbage for indices >= len1*len2?
    // `n = len1 * len2`. `qsort(a, n, ...)` sorts exactly n elements.
    // `temp` is filled from `ans` using sorted indices.
    
    // The error might be in the input parsing if the newline detection fails or consumes too much.
    // However, without being able to run it, the most suspicious part in similar problems is often the handling of the last element or the merging logic boundary.
    
    // But wait! Look at the Buggy Output again: `... 555 2`.
    // Expected `285 2` and `54 1`.
    // 285 + 54 = 339. Not 555.
    // 555 - 285 = 270.
    // 270 is 18 * 15.
    // It seems the term `18x^0 * 15x^2 = 270x^2` was added TWICE?
    // Or `54` was added to `285`? 285+54=339.
    // Where does 555 come from?
    // 10*30=300 (15)
    // 10*15=150 (10) -> 2*30=60 (13)? No. 10x^8 * 15x^2 = 150x^10. 2x^6 * 30x^7 = 60x^13.
    // Let's check the terms in Buggy Output:
    // 300 15 (10*30, 8+7) OK
    // 60 13 (2*30, 6+7) OK
    // 360 10 (10*15? No 10*15=150. 2*? No. 7*? No. 5*? No. 18*? No.)
    // Wait. 10x^8 * 15x^2 = 150x^10.
    // 2x^6 * ? 
    // 7x^3 * 30x^7 = 210x^10.
    // 150 + 210 = 360. OK.
    // 30 9 (2*15=30, 6+2=8? No. 7*? 7x^3*15x^2=105x^5. 5x^1*30x^7=150x^8.)
    // Let's re-calculate 30 9.
    // 2x^6 * ? No.
    // 7x^3 * ? No.
    // 5x^1 * ? No.
    // 18x^0 * ? No.
    // Who gives exponent 9?
    // 2x^6 * 15x^2 = 30x^8.
    // 7x^3 * 3x^1 = 21x^4.
    // 5x^1 * 15x^2 = 75x^3.
    // 18x^0 * 3x^1 = 54x^1.
    
    // Where is 30 9 coming from in Buggy Output?
    // 2x^6 * ? 
    // Maybe 2x^6 * something with exp 3? Poly2 has no exp 3.
    // Maybe 7x^3 * something with exp 6? Poly2 has no exp 6.
    // Maybe 10x^8 * something with exp 1? 10*3=30. Exp 8+1=9. YES.
    // So 30 9 is 10x^8 * 3x^1. OK.
    
    // 180 8:
    // 2x^6 * 15x^2 = 30x^8.
    // 5x^1 * 30x^7 = 150x^8.
    // 30+150=180. OK.
    
    // 546 7:
    // 7x^3 * 15x^2 = 105x^5.
    // 7x^3 * 30x^7 = 210x^10.
    // 2x^6 * 3x^1 = 6x^7.
    // 18x^0 * ? 
    // 5x^1 * ? 
    // 10x^8 * ?
    // Who gives exp 7?
    // 2x^6 * 3x^1 = 6x^7.
    // 7x^3 * ? 
    // 18x^0 * ? 
    // 5x^1 * ? 
    // 10x^8 * ?
    // Wait, 7x^3 * 15x^2 = 105x^5.
    // Is there another term for exp 7?
    // 18x^0 * ? No.
    // Maybe 546 is wrong?
    // 7x^3 * 30x^7 = 210x^10.
    // 2x^6 * 15x^2 = 30x^8.
    // 2x^6 * 3x^1 = 6x^7.
    // 18x^0 * ? 
    // 5x^1 * 30x^7 = 150x^8.
    // 5x^1 * 15x^2 = 75x^3.
    // 5x^1 * 3x^1 = 15x^2.
    // 18x^0 * 30x^7 = 540x^7.
    // 540 + 6 = 546. OK.
    
    // 105 5:
    // 7x^3 * 15x^2 = 105x^5. OK.
    
    // 21 4:
    // 7x^3 * 3x^1 = 21x^4. OK.
    
    // 75 3:
    // 5x^1 * 15x^2 = 75x^3. OK.
    
    // 555 2:
    // Expected 285 2.
    // 5x^1 * 3x^1 = 15x^2.
    // 18x^0 * 15x^2 = 270x^2.
    // Sum = 285.
    // Buggy has 555.
    // 555 - 285 = 270.
    // It seems 270 was added twice.
    // This implies the term `18x^0 * 15x^2` was processed twice?
    // Or `temp` array had duplicate entries that weren't merged correctly?
    // If `qsort` put them adjacent, the merge loop should catch it.
    // Unless... the merge loop failed to merge them?
    // If they were NOT adjacent?
    // But `qsort` sorts by exponent. All x^2 terms should be adjacent.
    
    // 54 1 is missing.
    // 18x^0 * 3x^1 = 54x^1.
    // If this term was lost, maybe it wasn't generated?
    // Or maybe it was merged into something else?
    
    // If the input parsing for the second polynomial failed to read the last term `3 1`?
    // If poly2 was `30 7 15 2`, then:
    // No `3 1` term.
    // Then `54 1` would not exist.
    // And `30 9` (10*3) would not exist.
    // But `30 9` IS in the buggy output. So `3 1` WAS read.
    
    // If `3 1` was read, why is `54 1` missing?
    // And why is `285 2` becoming `555 2`?
    
    // Hypothesis: The term `18x^0 * 15x^2` (270x^2) is appearing twice in `ans`.
    // Why?
    // `len1` = 5. `len2` = 3. `n` = 15.
    // Loops: i=0..4, j=0..2.
    // Each pair is generated once.
    // So `ans` has unique pairs.
    // `qsort` sorts them.
    // Merging combines them.
    
    // Is it possible that `temp` array was not cleared or contained garbage from previous runs? No, it's local/global but overwritten.
    
    // Let's look at the `cmp` function again.
    // It accesses `ans[x]`. `x` is an index in `a`.
    // `a` contains 0..14.
    // `ans` contains 15 elements.
    // This is fine.
    
    // There is a subtle bug in the merging loop:
    // for(i = 1; i < n; i++)
    // {
    //   if(temp[i - 1].exponent == temp[i]. exponent)
    //   {
    //     temp[i - 1].factor += temp[i].factor;
    //     n--;
    //     for(j = i; j < n - 1; j++) // @@ Error: The loop bound `n - 1` is incorrect for shifting. It should be `j < n` after decrement, or `j <= n` before? 
    //     // When n is decremented, the new valid range is 0..n-1.
    //     // We want to shift elements from i+1..n-1 (old n) to i..n-2 (new n).
    //     // Old n was N. New n is N-1.
    //     // Elements at indices i+1 to N-1 need to move to i to N-2.
    //     // Loop j from i to N-2.
    //     // Condition `j < n - 1` where n is now N-1 means `j < N - 2`.
    //     // So j goes up to N-3.
    //     // The element at old index N-1 (last one) is NOT copied.
    //     // The element at old index N-2 is copied to N-3?
    //     // Let's trace:
    //     // n=5. Merge at i=2.
    //     // n becomes 4.
    //     // Loop j=2; j < 3. j=2.
    //     // temp[2] = temp[3].
    //     // Element at old index 4 is lost. Element at old index 3 is moved to 2.
    //     // Element at old index 2 (merged) stays at 2? No, it stays at 1 (i-1).
    //     // We are shifting the "tail" to cover the gap at i.
    //     // The gap is at i. The elements to shift are i+1 ... n_old-1.
    //     // They should go to i ... n_new-1.
    //     // n_new = n_old - 1.
    //     // So dest range is i ... n_old-2.
    //     // Source range is i+1 ... n_old-1.
    //     // Loop j from i to n_old-2.
    //     // temp[j] = temp[j+1].
    //     // Current code: `for(j = i; j < n - 1; j++)` where n is already decremented.
    //     // So `j < (n_old - 1) - 1` => `j < n_old - 2`.
    //     // So j goes up to `n_old - 3`.
    //     // It misses the last element transfer.
    //     // It should be `j < n` (where n is the new size) ?
    //     // If j < n (new n = 4), j goes 2, 3.
    //     // j=2: temp[2]=temp[3].
    //     // j=3: temp[3]=temp[4].
    //     // This copies old 3->2, old 4->3.
    //     // This is correct.
    //     // So the condition should be `j < n`.
    //     temp[j].factor = temp[j + 1].factor;
    //     temp[j].exponent = temp[j + 1].exponent;
    //     }
    //     i--;
    //   }
    // }
    
    // Because of `j < n - 1`, the last element in the array is dropped during every merge operation.
    // This explains why terms are missing (like `54 1`) and why counts might be wrong.
    // If `54 1` was the last element, it gets dropped.
    // If `270 2` was duplicated, and one was dropped, maybe the other remained?
    // Actually, if elements are dropped, the array shrinks faster than it should, losing valid terms.
    
    // So the error is in the shifting loop bound.
    
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