#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p1, const void *p2)
{
    int *a = (int *)p1;
    int *b = (int *)p2;
    return b[1] - a[1];
}

int main()
{
    int a[20][2];
    int b[20][2];
    int ans[50][2];
    char c = '0';
    int i, j, k = 0;
    int num_fst = 0, num_scd = 0;
    while(c != '\n')
    {
        scanf("%d%d%c",&a[num_fst][0], &a[num_fst][1], &c);
        num_fst++;
    }
    c = '0';
    while(c != '\n')
    {
        scanf("%d%d%c",&b[num_scd][0], &b[num_scd][1], &c);
        num_scd++;
    }
    for(i = 0; i < num_fst; i++)
    {
        for(j = 0; j < num_scd; j++)
        {
            ans[k][0] = a[i][0] * b[j][0];
            ans[k++][1] = a[i][1] + b[j][1]; 
        }
    }
    qsort(ans, k, sizeof(ans[0]), cmp);

    for(i = 0; i < k - 1; i++)
    {
        if(ans[i][1] == ans[i + 1][1])
        {
            ans[i][0] += ans[i + 1][0];
            ans[i + 1][0] = 0;
        }
    }
    for(i = 0; i < k; i++)
    {
        if(ans[i][0] != 0) // @@ The logic for merging terms with the same exponent is flawed. When multiple terms share the same exponent (e.g., 3 terms), this single pass only merges adjacent pairs sequentially but doesn't guarantee all like terms are combined into a single term before zeroing out. Specifically, if ans[i] accumulates from ans[i+1], and ans[i+1] was already accumulated from ans[i+2] in a previous iteration or vice-versa, the logic holds for adjacent sorted items. However, the critical error is that after merging ans[i] += ans[i+1] and setting ans[i+1]=0, if there is a third term ans[i+2] with the same exponent, it will not be merged into ans[i] because the loop moves to i+1 next. The standard approach is to merge all identical exponents into the first occurrence and zero out the rest, which requires a nested loop or a different strategy. In this specific case, `142 26` vs `157 26` suggests missing accumulation. The term `7 13` * `26 15` = `182 28` (ok). `18 9` * `3 21` = `54 30`. `5 5` * `26 15` = `130 20`. Let's look at exponent 26. Terms contributing to 26: `2 26` * `6 0` = `12 26`. `7 13` * `3 21` is exp 34. `18 9` * `?`. `5 5` * `?`. Wait, `10 38`... `2 26` * `6 0` = 12. `7 13` * `?` no. `18 9` * `?` no. `5 5` * `?` no. What about `2 26` from poly A and `6 0` from poly B? Yes. Are there others? Poly A: `2 26`. Poly B: `6 0`. Product: 12. Poly A: `7 13`. Poly B: `?` to get 26? Need exp 13. Poly B has `26 15`, `6 0`, `3 21`, `15 32`, `30 47`. No exp 13. Poly A: `18 9`. Need exp 17. No. Poly A: `5 5`. Need exp 21. Poly B has `3 21`. Product `5*3=15`, exp `5+21=26`. So we have `12 26` and `15 26`. Sum = 27. Still not 142 or 157. Let's re-read carefully. `142` vs `157`. Difference is 15. This matches the `15` coefficient from `5*3`. So `142` is missing the `15` contribution? Or `157` includes it? If the code produced `142`, it missed adding `15`. If it produced `157`, it added it. The expected is `157`. The buggy output is `142`. This implies the term `15 26` was not added to `12 26` (or whatever the base was). Actually, `18 9` * `?` no. `10 38`... `2 26` * `15 32`? No. Let's check `157`. `157 - 15 = 142`. So there is a term with coeff 142 and exp 26? `7 13` * `26 15` = `182 28`. `2 26` * `30 47`... no. `2 26` * `15 32`... no. `2 26` * `3 21`... no. `2 26` * `6 0` = `12 26`. `5 5` * `3 21` = `15 26`. Sum = 27. Where does 142 come from? Maybe `18 9` * `?` No. `10 38`... Ah, `7 13` * `?` No. Is there a term `142 26` in input? No. Wait, `18 9` * `?` No. Let's look at `15 26` in Poly B. `2 26` (A) * `15 32` (B) -> Exp 58. `7 13` (A) * `26 15` (B) -> Exp 28. `18 9` (A) * `?` (B) -> Exp 26? Need B exp 17. None. `5 5` (A) * `?` (B) -> Exp 26? Need B exp 21. `3 21` (B). Coeff `5*3=15`. So `15 26`. `2 26` (A) * `6 0` (B) -> `12 26`. Total `27 26`. Why expected `157`? Maybe I misread input. `10 38 2 26 7 13 5 11 18 9 5 5`. `30 47 15 32 3 21 26 15 6 0`. Term `26 15` in B means coeff 26, exp 15. Term `2 26` in A means coeff 2, exp 26. Product: `52 41`. Term `7 13` in A. Term `?` in B for exp 26? Need exp 13. None. Term `18 9` in A. Need exp 17. None. Term `5 11` in A. Need exp 15. `26 15` in B. Product `5*26=130`, exp `11+15=26`. So `130 26`. Term `5 5` in A. Need exp 21. `3 21` in B. Product `15 26`. Term `2 26` in A. Need exp 0. `6 0` in B. Product `12 26`. Sum: `130 + 15 + 12 = 157`. Correct. The code outputs `142`. `157 - 142 = 15`. So the term `15 26` is missing from the sum. This confirms the merging logic failed to combine all three terms (`130`, `15`, `12`) correctly. The simple adjacent merge fails if more than 2 terms share the exponent or if the order of operations leaves one out. For example, if sorted as `130, 15, 12`. i=0: `130==15`? No. i=1: `15==12`? No. They are not equal? Wait, `qsort` sorts by exponent descending. All have exp 26. So they are adjacent. But `cmp` returns `b[1]-a[1]`. If equal, it returns 0. Stability is not guaranteed. If they are adjacent, `ans[i][1] == ans[i+1][1]` is true. i=0: `130` and `15`. Exp 26==26. `ans[0][0]` becomes `145`. `ans[1][0]` becomes 0. Array: `145, 0, 12`. i=1: `ans[1][1]` (0) vs `ans[2][1]` (12)? No, `ans[1]` is `{0, 26}`. Exp is still 26. So `ans[1][1] == ans[2][1]` is true. `ans[1][0]` (0) += `ans[2][0]` (12) -> 12. `ans[2][0]` -> 0. Array: `145, 12, 0`. Loop ends. Output: `145` and `12`. Both non-zero. So output would be `145 26 12 26`. This is wrong format (duplicate exponents). The problem requires combining them. The code prints `142`? Maybe the sort order or values were different. Regardless, the logic `ans[i][0] += ans[i+1][0]; ans[i+1][0]=0;` inside a single forward loop is insufficient for grouping >2 items or handling the resulting non-zero items that shift. It should accumulate into one and zero out all others, typically requiring a while loop or second pass.
        printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}