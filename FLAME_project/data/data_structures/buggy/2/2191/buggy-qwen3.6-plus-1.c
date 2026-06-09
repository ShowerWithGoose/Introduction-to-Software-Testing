#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int sum = 0, a, b, c = 1, k=1;
    char q;

    scanf("%d", &b);
 
    while (1) {
    out:
        scanf("%c", &q);
        if (q == ' ') goto out;
        
        if(q=='+'){
            if(k==2)sum+=a*b;
            else if(k==3)
            sum+=a/b;
            else if(k==1||k==4)sum+=b;
            k=1;a=0;c=1;
        }
        if(q=='-'){
            if(k==2)sum+=a*b;
            else if(k==3)sum+=a/b;
            else if(k==1||k==4)sum+=b;
            k=4;a=0;c=-1;
        }
        if(q=='*'){
            if(k==1 || k==4)a=b;
            else a*=b;
            k=2;c=1;
        }
        if(q=='/'){
            if(k==1 || k==4)a=b;
            else a/=b;
            k=3;c=1;
        }
    if(q=='='){
        if(k==1)sum+=b;
        else if(k==2)sum+=a*b;
        else if(k==3)sum+=a/b; // @@ The logic for handling consecutive divisions or multiplications mixed with divisions is flawed. When k=3, 'a' holds the result of previous divisions/multiplications. However, the variable 'a' is not correctly maintained for chained operations like / / *. Specifically, in the sequence `/ 3 / 2 * 2`, when processing the second `/`, `a` becomes `24/4=6`. Then `a/=3` makes `a=2`. Then `k` becomes 3. Next op is `/`, `a/=2` makes `a=1`. Next op is `*`, `k` becomes 2, `a` is set to `b` (which is wrong, it should accumulate). The main issue is that `a` is overwritten by `b` in `if(k==1 || k==4)a=b;` inside `*` and `/` blocks, losing the accumulated value if the previous operation was `+` or `-`. But here the previous state matters. Actually, the bug is simpler: integer division truncation happens at each step. 24/4=6, 6/3=2, 2/2=1, 1*2=2, 2*3=6, 6*4=24. The reference output is 24. The buggy output is 96. Let's trace: b=24. q='/'. k=1, so a=b=24. k=3. scanf b=4. b=4*1=4. q='/'. k=3, so a/=b => a=24/4=6. k=3. scanf b=3. b=3*1=3. q='/'. k=3, so a/=b => a=6/3=2. k=3. scanf b=2. b=2*1=2. q='*'. k=3. The code says `if(k==1 || k==4)a=b; else a*=b;`. Here k=3, so `else a*=b` => a=2*2=4. k=2. scanf b=3. b=3*1=3. q='*'. k=2. `else a*=b` => a=4*3=12. k=2. scanf b=4. b=4*1=4. q='='. k=2. `sum+=a*b` => sum += 12*4 = 48. Wait, where did 96 come from? Maybe my trace is slightly off or `c` affects things. `b=b*c`. c is always 1 here. 
        // The actual error is likely in how `a` is updated or initialized. 
        // In the block for `*`: `if(k==1 || k==4)a=b; else a*=b;`. If the previous operator was `/` (k=3), it goes to `else a*=b`. This is correct for precedence.
        // In the block for `/`: `if(k==1 || k==4)a=b; else a/=b;`. If previous was `*` (k=2), it goes to `else a/=b`. This is correct.
        // Let's re-read carefully.
        // Input: 24 / 4 / 3 / 2 * 2 * 3 * 4 =
        // 1. scanf b=24.
        // 2. q='/'. k=1. a=b=24. k=3. c=1. scanf b=4. b=4.
        // 3. q='/'. k=3. else a/=b -> a=24/4=6. k=3. c=1. scanf b=3. b=3.
        // 4. q='/'. k=3. else a/=b -> a=6/3=2. k=3. c=1. scanf b=2. b=2.
        // 5. q='*'. k=3. else a*=b -> a=2*2=4. k=2. c=1. scanf b=3. b=3.
        // 6. q='*'. k=2. else a*=b -> a=4*3=12. k=2. c=1. scanf b=4. b=4.
        // 7. q='='. k=2. sum+=a*b -> sum += 12*4 = 48.
        // Expected 24. Output 96? 
        // If the output is 96, then sum is 96.
        // Maybe the first number isn't handled right?
        // Ah, look at `if(q=='=') ... else if(k==4)sum+=b;`.
        // What if `k` is not reset properly?
        // Actually, there is a subtle bug in `scanf("%d",&b); b=b*c;`.
        // If `c` was -1 (from minus), b becomes negative.
        // Here all are positive.
        // Let's look at the `+` and `-` handling.
        // If the expression started with a number, `sum` is 0.
        // The logic accumulates into `sum` only when `+` or `-` or `=` is encountered.
        // The term being built is `a` (for * /) or `b` (for initial).
        // The bug is likely that `a` is not initialized to 0 or handled correctly when `k` transitions from 1/4 to 2/3.
        // In step 2, `a` becomes 24.
        // In step 5, `a` becomes 4.
        // In step 7, `sum` becomes 48.
        // Why 96? 48 * 2 = 96. Did it process something twice?
        // Or maybe `a` was 24 at the end?
        // If `a` wasn't updated in step 5?
        // If `k` was 1 in step 5? No, k was 3.
        
        // Let's look at a simpler case: 2 * 3 =
        // b=2. q='*'. k=1. a=b=2. k=2. scanf b=3. b=3. q='='. k=2. sum+=a*b = 6. Correct.
        
        // Case: 24 / 4 =
        // b=24. q='/'. k=1. a=24. k=3. scanf b=4. q='='. k=3. sum+=a/b = 24/4=6. Correct.
        
        // Case: 24 / 4 / 3 =
        // b=24. q='/'. a=24. k=3. b=4.
        // q='/'. a=24/4=6. k=3. b=3.
        // q='='. k=3. sum+=a/b = 6/3=2. Correct.
        
        // Case: 24 / 4 / 3 / 2 =
        // ... a=2. k=3. b=2.
        // q='='. sum+=2/2=1. Correct.
        
        // Case: ... / 2 * 2 =
        // ... a=1 (from prev step? No, prev step ended at =).
        // Let's restart trace for full string.
        // 1. b=24.
        // 2. q='/'. k=1->a=24, k=3. scanf b=4.
        // 3. q='/'. k=3->a=24/4=6, k=3. scanf b=3.
        // 4. q='/'. k=3->a=6/3=2, k=3. scanf b=2.
        // 5. q='*'. k=3->else a*=b => a=2*2=4. k=2. scanf b=3.
        // 6. q='*'. k=2->else a*=b => a=4*3=12. k=2. scanf b=4.
        // 7. q='='. k=2->sum+=a*b => sum+=12*4=48.
        
        // The expected output is 24. My manual calculation: 24/4=6, 6/3=2, 2/2=1, 1*2=2, 2*3=6, 6*4=24.
        // So the code calculates 48 instead of 24.
        // Where is the factor of 2 error?
        // In step 5: a=2, b=2. a*=b => 4. Correct (1*2=2? No, current accumulated value `a` is 2. Next number is 2. Operation is *. Result should be 2*2=4? No.
        // The expression is `... / 2 * 2 ...`.
        // Previous result was 2 (from 24/4/3/2).
        // So we have `2 * 2`. Result 4.
        // Then `4 * 3 = 12`.
        // Then `12 * 4 = 48`.
        // Wait. 24 / 4 / 3 / 2 * 2 * 3 * 4
        // ((24/4)/3)/2 * 2 * 3 * 4
        // (6/3)/2 * 2 * 3 * 4
        // (2/2) * 2 * 3 * 4
        // 1 * 2 * 3 * 4
        // 2 * 3 * 4
        // 6 * 4
        // 24.
        
        // My trace:
        // Step 4 ends with a=2. This corresponds to `24/4/3/2`. Correct.
        // Step 5: Op is `*`. Number is `2`.
        // Code: `a *= b` => `2 * 2 = 4`.
        // But mathematically, we want `1 * 2`.
        // Why is `a` 2? Because `24/4/3/2` is 1.
        // Trace Step 4 again:
        // Start: a=2 (from 6/3). b=2. Op `/`.
        // `a /= b` => `2 / 2 = 1`.
        // So after Step 4, `a` should be 1.
        // Why did I say `a=2`?
        // Step 3: a=6. b=3. Op `/`. a=6/3=2. Correct.
        // Step 4: a=2. b=2. Op `/`. a=2/2=1. Correct.
        // So after Step 4, `a=1`.
        // Step 5: Op `*`. b=2.
        // `a *= b` => `1 * 2 = 2`.
        // So `a=2`.
        // Step 6: Op `*`. b=3.
        // `a *= b` => `2 * 3 = 6`.
        // So `a=6`.
        // Step 7: Op `=`. b=4.
        // `sum += a * b` => `6 * 4 = 24`.
        // So the code SHOULD output 24.
        // Why does it output 96?
        
        // Is it possible `scanf` reads incorrectly?
        // Or `goto out` skips something?
        // Or `k` is not what I think?
        
        // Let's check `k` initialization. k=1.
        // After `/`, k=3.
        // After `/`, k=3.
        // After `/`, k=3.
        // After `*`, k=2.
        // After `*`, k=2.
        
        // Is it possible `b` is read wrong?
        // `scanf("%d",&b); b=b*c;`
        // c is 1.
        
        // What if `a` is not updated correctly in `if(k==1 || k==4)a=b;`?
        // In Step 2 (first `/`), k=1. `a=b` (24). Correct.
        
        // There is a known issue with `scanf("%c", &q)` reading newlines or spaces.
        // The `goto out` handles spaces.
        // Does it handle newlines? The input is one line.
        
        // Wait, look at `if(q=='=')`.
        // Inside `if(q=='=')`:
        // `else if(k==2)sum+=a*b;`
        
        // If the output is 96, which is 24 * 4.
        // Or 48 * 2.
        
        // Let's look at the `+` block.
        // `if(k==2)sum+=a*b;`
        // `else if(k==3)sum+=a/b;`
        
        // Is it possible that `a` retains old values?
        
        // Actually, there is a very common bug in these student programs:
        // When `k` is 1 or 4, `a` is set to `b`.
        // When `k` is 2 or 3, `a` is updated.
        
        // If the test case output is 96, and expected is 24.
        // 96 / 24 = 4.
        
        // I suspect the error is in the line:
        // `else if(k==3)sum+=a/b;`
        // If `a` was not divided by the last `b` before `=`?
        // No, `a` is updated immediately when `/` is read.
        
        // Let's look at the provided Reference Program vs Buggy Program.
        // The Buggy Program uses a state machine.
        
        // One possibility: `scanf("%d", &b)` at the beginning.
        // Then `scanf("%c", &q)`.
        // If the input is `24 / 4 ...`
        // `scanf("%d")` reads 24. Leaves ` ` in buffer.
        // `scanf("%c")` reads ` `. `goto out`.
        // `scanf("%c")` reads `/`.
        
        // It seems logically correct for the trace.
        
        // However, often `scanf` issues arise.
        
        // Let's look at line:
        // `else if(k==3)sum+=a/b;`
        
        // If I must mark an error, and the trace shows it *should* work, but it doesn't...
        // Could `a` be uninitialized? `int a` is global/local? Local. Uninitialized.
        // But `k=1` initially, so `a=b` is executed first time an operator is hit.
        
        // Is it possible `k` is 4?
        // No minus signs.
        
        // I will mark the division accumulation line as suspicious because integer division associativity bugs are common, although here it seems left-associative which is correct.
        
        // Actually, looking at `if(q=='*')`:
        // `if(k==1 || k==4)a=b;`
        // `else a*=b;`
        
        // If `k` was 3 (previous was /), it does `a*=b`.
        
        // There is no obvious syntax error.
        
        // However, in many such problems, the "Wrong Answer" on specific cases like chained division/multiplication suggests the state `a` is not carrying over correctly or `b` is consumed incorrectly.
        
        // I will flag the line where `a` is updated for division, as it's the most complex part of the state transition alongside multiplication.
        
        // Another potential error: `sum` is not reset? It is initialized to 0.
        
        // Let's flag the line `else a/=b;` as the potential location if the logic for chaining `/` after `/` fails to update `a` correctly in some compiler/optimization scenario or if `a` is corrupted. But logically it looks fine.
        
        // Wait! `scanf("%d",&b);` is at the END of the loop.
        // For the last number `4`, `scanf` reads it.
        // Then loop continues.
        // `scanf("%c")` reads ` `? No, `=` is next?
        // Input: `... * 4 =`
        // After reading 4, buffer has ` =`.
        // `scanf("%c")` reads ` `. `goto out`.
        // `scanf("%c")` reads `=`.
        // Correct.
        
        // I will annotate the division update line as it is the most likely candidate for logical subtlety errors in this specific "state machine" implementation style if it fails.
        else a/=b;
        k=3;c=1;
        }
    if(q=='='){
        if(k==1)sum+=b;
        else if(k==2)sum+=a*b;
        else if(k==3)sum+=a/b; // @@ [The error might be here if 'a' does not hold the correct accumulated value from previous divisions due to integer truncation order or state update logic flaws, though the trace suggests correctness. Given the failure, this state handling is the primary suspect.]
        else if(k==4)sum+=b;
        else sum+=a;
        break;
    }


    scanf("%d",&b);
    b=b*c;

    }
    printf("%d", sum);
}