/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2024-02-27 22:28
    说明:

*********************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char a[100001];
int b[10001], c[10001], num[10001], d[10001];
int f(char a, int b, int c) {
    switch (a) {
        case '+':
            return b + c;
        case '-':
            return b - c;
        case '*':
            return b * c;
        case '/':
            return b / c;
    }
}

int main() {
    gets(a);
    int i, j;
    for (i = j = 0; a[i] != '\0'; i++)
        if (a[i] != ' ')
            a[j++] = a[i];
    a[j] = '\0';
    int m = 0, n = 0, p = 1, f1 = 0;
    for (int x = 0; x < j; x++) {
        if (a[x] == '+' || a[x] == '-') {
            m++;
            p++;
            f1++;
            b[m] = x;
            d[m] = f1;

        } else if (a[x] == '*' || a[x] == '/') {
            n++;
            p++;
            f1++;
            c[n] = x;
            d[n] = f1; // @@ [Error: The index stored in d[n] for multiplication/division operators conflicts with the index used for addition/subtraction operators in d[m]. Since both increment the same counter f1 and store it in separate arrays b/c and d, but d is shared or overloaded incorrectly. Specifically, d is used to map operator sequence to operand indices. When processing * and /, we update num[d[x]]. However, d[n] here stores the global operator count. The logic fails because d is used for both +,- and *,/ mapping to num indices, but the updates to num during * / processing shift values or overwrite incorrectly if indices overlap or are not managed distinctly for the two passes. More critically, the variable `d` is being used to store the "operand index" for both types of operators. For `+`/`-`, `d[m]` is the index of the left operand. For `*`/`/`, `d[n]` is also the index of the left operand. This part is logically okay IF the indices are unique. However, the issue lies in how `num` is updated. ]

        } else if (a[x] == '=')
            break;
        else
            num[p] = num[p] * 10 + a[x] - '0';
    }

    for (int x = 1; x <= n; x++) {
        num[d[x]] = f(a[c[x]], num[d[x]], num[d[x] + 1]); // @@ [Error: When performing integer division or multiplication sequentially, updating num[d[x]] in place affects subsequent operations if they reference the same index. However, the bigger issue is that `d[x]` refers to the position in the `num` array. If we have `24 / 4 / 3`, the first `/` is at index 1 (in c/d arrays). d[1] corresponds to the operand index. Let's trace: `24/4/3`. Ops: /, /. Nums: 24, 4, 3. d[1]=1 (for first /), d[2]=2 (for second /). First loop x=1: num[1] = 24/4 = 6. num[2] becomes 6? No, line below: num[d[x]+1] = num[d[x]]. So num[2] = 6. Next loop x=2: num[2] = num[2] / num[3] => 6 / 3 = 2. This seems correct for left-associativity. BUT, look at the test case: `24 / 4 / 3 / 2 * 2 * 3 * 4`. The code processes all * and / in one go based on their appearance order. This is correct for left associativity. The error is likely in how `d` indices are assigned relative to `num` indices when `+` and `-` are present, or simply that `d` array collision. Wait, `b` and `c` store positions in `a`. `d` stores the operand index `p`. `p` increments for EVERY operator. So `d` values are unique across all operators. The logic `num[d[x]+1] = num[d[x]]` propagates the result to the right operand's slot. This allows the next operator using that slot to see the updated value. This logic holds for pure * / chains. ]
        num[d[x] + 1] = num[d[x]];

    }
    int sum = num[1];
    for (int x = 1; x <= m; x++) {
        sum = f(a[b[x]], sum, num[d[x] + 1]); // @@ [Error: The variable `d` is shared. `d[m]` was set when processing +/-. `d[n]` was set when processing */*. They are stored in the same array `d` but accessed via different counters `m` and `n`. However, `d` indices for `+` operators might overlap with `d` indices for `*` operators if not careful? No, `f1` is global. So `d[1]` might be for a `*` and `d[2]` for a `+`. In the second loop, we iterate `x` from 1 to `m`. We access `d[x]`. If the first operator was `*`, `d[1]` holds the operand index for that `*`. But here we are iterating `+` and `-` operators stored in `b`. The index `x` here corresponds to the `m`-th addition/subtraction operator. But we are accessing `d[x]`. If the first operator in the expression was `*`, then `d[1]` belongs to that `*`. The first `+` operator might be the 2nd operator overall, so its info is in `d[2]` and `b[1]`. But the loop uses `d[x]` where `x` is 1..m. So for the first `+` (stored in `b[1]`), it accesses `d[1]`. But `d[1]` contains the operand index for the FIRST operator overall (which might be `*`). This is a mismatch. The array `d` stores operand indices for ALL operators sequentially. The arrays `b` and `c` store operator positions for specific types. The loop for `+`/`-` should use the operand index associated with THAT specific operator. Since `b` and `c` are separate, we lost the mapping between `b[k]` (the k-th plus/minus) and its corresponding operand index in `d`. We need a separate array for operand indices of +/-, e.g., `d_plus[m]`, or store the operand index in `b`'s parallel array. Currently, `d[x]` in the final loop retrieves the operand index of the x-th operator OVERALL, not the x-th +/- operator. ]
    }
    printf("%d", sum);
    return 0;
}