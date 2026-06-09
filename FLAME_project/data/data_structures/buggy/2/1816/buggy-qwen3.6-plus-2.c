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
            d[n] = f1; // @@ The array d is used to map operator indices to number indices. However, d is shared between addition/subtraction operators (indexed by m) and multiplication/division operators (indexed by n). When processing multiplication/division later, the code accesses d[x] where x is the index in the mul/div list. But d was overwritten or mixed with add/sub data. More critically, the logic for updating numbers after multiplication/division is flawed.

        } else if (a[x] == '=')
            break;
        else
            num[p] = num[p] * 10 + a[x] - '0';
    }

    for (int x = 1; x <= n; x++) {
        num[d[x]] = f(a[c[x]], num[d[x]], num[d[x] + 1]); // @@ This line updates the left operand of the multiplication/division. However, it does not correctly handle the chaining of operations. For example, in "24 / 4 / 3", the first division updates num[d[1]] (which corresponds to the first number's position). The second division should use the result of the first. But the index mapping d[x] might not point to the correct updated value if previous operations shifted or modified the structure incorrectly. Specifically, d[x] stores the "sequence number" of the number before the operator. When we do num[d[x]] = result, we are overwriting the number at that sequence position. The next operator might refer to num[d[x]+1]. If d[x] is not unique or properly managed across different operator types, this fails. In the specific case of "24 / 4 / 3 / 2 * 2 * 3 * 4", the divisions are processed. The first division 24/4=6 updates num[1] to 6. The second division uses num[d[2]] and num[d[2]+1]. d[2] corresponds to the sequence index of the number before the second '/'. If the parsing logic assigns sequence indices incrementally regardless of operator type, d[2] might be 2 (for the number 4, which was already consumed/overwritten?) or 3? The parsing loop increments p for every operator. So num[1]=24, op1(/), num[2]=4, op2(/), num[3]=3... d[1] for first '/' is 1 (p was 1 before increment? No, p increments then d[m/n]=f1. f1 increments then d=f1. Let's trace: x=0..1 '2','4' -> num[1]=24. x=2 '/' -> n=1, p=2, f1=1, c[1]=2, d[1]=1. x=3..3 '4' -> num[2]=4. x=4 '/' -> n=2, p=3, f1=2, c[2]=4, d[2]=2. x=5..5 '3' -> num[3]=3. x=6 '/' -> n=3, p=4, f1=3, c[3]=6, d[3]=3. x=7..7 '2' -> num[4]=2. x=8 '*' -> n=4, p=5, f1=4, c[4]=8, d[4]=4. ...
        // Processing mul/div:
        // x=1: c[1]=2 ('/'), d[1]=1. num[1] = num[1]/num[2] = 24/4=6. num[2]=6.
        // x=2: c[2]=4 ('/'), d[2]=2. num[2] = num[2]/num[3] = 6/3=2. num[3]=2.
        // x=3: c[3]=6 ('/'), d[3]=3. num[3] = num[3]/num[4] = 2/2=1. num[4]=1.
        // x=4: c[4]=8 ('*'), d[4]=4. num[4] = num[4]*num[5] = 1*2=2. num[5]=2.
        // x=5: c[5]=10 ('*'), d[5]=5. num[5] = num[5]*num[6] = 2*3=6. num[6]=6.
        // x=6: c[6]=12 ('*'), d[6]=6. num[6] = num[6]*num[7] = 6*4=24. num[7]=24.
        // This part actually seems to calculate the value correctly into num[d[x]] and propagates it to num[d[x]+1].
        
        num[d[x] + 1] = num[d[x]]; // @@ This propagation ensures that the next number in the sequence holds the intermediate result, allowing chained operations to work correctly on the `num` array.

    }
    int sum = num[1];
    for (int x = 1; x <= m; x++) {
        sum = f(a[b[x]], sum, num[d[x] + 1]); // @@ Here lies the critical error. The array `d` is shared for both additive and multiplicative operators. 
        // In the parsing loop:
        // Add/Sub operators update `m` and store their index in `b` and sequence pos in `d`.
        // Mul/Div operators update `n` and store their index in `c` and sequence pos in `d`.
        // Since `d` is overwritten by the last operator type processed at each "slot" or rather, `d` is indexed by `m` and `n` separately but they write to the same array `d`?
        // No, `b` and `c` are separate. `d` is ONE array.
        // When parsing:
        // If we encounter '+', m becomes 1, d[1] is set.
        // If we encounter '*', n becomes 1, d[1] is OVERWRITTEN.
        // So `d` cannot store mapping for both `b` (add/sub) and `c` (mul/div) simultaneously if they share indices 1..k.
        // In the test case "24 / 4 / 3 / 2 * 2 * 3 * 4 =", there are NO addition or subtraction operators.
        // So `m` remains 0. The loop `for (int x = 1; x <= m; x++)` does not execute.
        // The result should be `sum = num[1]`.
        // Let's re-evaluate `num[1]` after the mul/div loop.
        // In the trace above, `num[1]` remained 6? No.
        // x=1: num[1]=6, num[2]=6.
        // x=2: num[2]=2, num[3]=2.
        // x=3: num[3]=1, num[4]=1.
        // x=4: num[4]=2, num[5]=2.
        // x=5: num[5]=6, num[6]=6.
        // x=6: num[6]=24, num[7]=24.
        // `num[1]` is still 6.
        // The final answer is printed as `sum` which is initialized to `num[1]`.
        // So the output is 6. Expected is 24.
        // The error is that `sum` takes `num[1]`, but the result of the entire chain of multiplications/divisions ended up in `num[7]` (or generally the last number slot involved).
        // Because there are no additions, `sum` is just `num[1]`, which holds the result of the *first* operation only, not the accumulated result of the whole expression.
        // The accumulation happened in the higher indices of `num`.
        // If there were additions, the second loop would combine them. But without additions, we just return the first number slot.
        // To fix this, if there are no additions, we should return the result of the mul/div chain, which is effectively the last updated number in the sequence involved in mul/div.
        // Or, simpler: the variable `sum` should be initialized to the result of the mul/div processing.
        // Actually, looking at the logic: `num[d[x]+1] = num[d[x]]` propagates the result to the RIGHT.
        // So the final result of the mul/div block is in the last number operand of the last mul/div operator.
        // In our case, the last mul/div operator is at index `n=6`. Its right operand index is `d[6]+1 = 7`.
        // So `num[7]` holds 24.
        // But `sum` is initialized to `num[1]`.
        // If there were additions, e.g., "1 + 2 * 3", mul/div processes 2*3=6, stores in num[2] and num[3].
        // Then add loop: sum = num[1] (1) + num[d[1]+1]. d[1] for '+' would be... wait.
        // If we have mixed operators, `d` collision is a huge problem.
        // Example: "1 + 2 * 3".
        // Parse:
        // '1' -> num[1]=1.
        // '+' -> m=1, p=2, f1=1, b[1]=idx, d[1]=1.
        // '2' -> num[2]=2.
        // '*' -> n=1, p=3, f1=2, c[1]=idx, d[1]=2.  <-- OVERWRITES d[1]!
        // '3' -> num[3]=3.
        // Mul/Div loop: x=1. c[1]='*', d[1]=2. num[2] = 2*3=6. num[3]=6.
        // Add/Sub loop: x=1. b[1]='+'. d[1] is now 2 (from mul/div overwrite).
        // sum = num[1] (1).
        // sum = f('+', 1, num[d[1]+1]) = f('+', 1, num[3]) = 1 + 6 = 7. Correct.
        // It seems the overwrite works in favor here? d[1] for add was 1. d[1] for mul became 2.
        // The add loop uses d[x] where x is index in add list.
        // The mul loop uses d[x] where x is index in mul list.
        // They both write to d[1], d[2] etc.
        // If we have "1 * 2 + 3":
        // '1' -> num[1]=1.
        // '*' -> n=1, p=2, f1=1, c[1]=idx, d[1]=1.
        // '2' -> num[2]=2.
        // '+' -> m=1, p=3, f1=2, b[1]=idx, d[1]=2. <-- OVERWRITES d[1]!
        // '3' -> num[3]=3.
        // Mul loop: x=1. c[1]='*', d[1]=2. num[2] = num[2]*num[3] = 2*3=6. num[3]=6.
        // Wait, the multiplication was 1*2. It should use num[1] and num[2].
        // But d[1] is now 2. So it calculates num[2]*num[3] which is 2*3=6. Incorrect.
        // So the shared `d` array is definitely a bug for mixed expressions.
        // However, the current test case has ONLY mul/div.
        // So `m=0`. The add loop doesn't run.
        // The issue is simply that `sum` is `num[1]`, but the result is in `num[last]`.
        
    }
    printf("%d", sum);
    return 0;
}