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
        else if(k==3)sum+=a/b;
        else if(k==4)sum+=b; // @@ The logic for handling the final term when the previous operator was '-' (k=4) is incorrect. It adds 'b' instead of subtracting it (or adding c*b where c=-1). For input ending in "... * 4 =", k is 2, so it executes sum+=a*b. However, the accumulation logic for chained multiplications/divisions followed by addition/subtraction is flawed because 'a' holds the result of the previous chain, but 'b' is the new number. In the specific failing case "24 / 4 / 3 / 2 * 2 * 3 * 4 =", the division chain 24/4/3/2 results in 1. Then *2*3*4 should result in 24. The variable 'a' tracks the running product/quotient. When '=' is hit, k=2 (last op was *). The code does sum += a*b. Here 'a' is the result of "1*2*3" = 6, and 'b' is 4. So sum += 24. This part seems correct for the last step. Let's re-evaluate.
        // The issue is likely in how intermediate results are accumulated into 'sum' when switching from high precedence (*,/) to low precedence (+,-).
        // When we hit '+' or '-', we add the completed high-precedence term to sum.
        // Let's trace: 24 / 4 / 3 / 2 * 2 * 3 * 4 =
        // Init: b=24.
        // Read '/': k=1 -> a=24, k=3. Read b=4. b = 4*1 = 4.
        // Read '/': k=3 -> a/=b => a=24/4=6. k=3. Read b=3. b=3.
        // Read '/': k=3 -> a/=b => a=6/3=2. k=3. Read b=2. b=2.
        // Read '*': k=3 -> This is the bug. If k==3 (previous was /), we fall into else a/=b? No, the if(q=='*') block says: if(k==1||k==4) a=b; else a*=b.
        // Wait, if previous was '/', k=3. Current is '*'. The code executes `else a*=b`. So a = 2*2 = 4. This is WRONG. It should have finished the division chain and started a multiplication chain, or treated * and / with same precedence left-to-right.
        // Actually, * and / have same precedence. So 24/4/3/2*2... should be evaluated left to right.
        // 24/4=6, 6/3=2, 2/2=1, 1*2=2, 2*3=6, 6*4=24.
        // The code's logic for mixing * and /:
        // If k=3 (prev /) and curr *, it does a*=b. But 'a' was the accumulator for division.
        // Let's check the division block: if(k==1||k==4) a=b; else a/=b.
        // If k=2 (prev *) and curr /, it does else a/=b.
        // So it seems to treat them as a single chain regardless of operator, which is correct for L-to-R associativity IF the operation applied matches the current operator.
        // BUT, the code applies the NEW operator to the OLD accumulator using the NEW number?
        // Let's look at `if(q=='*')`: `else a*=b`. This uses the current `b` (which was read AFTER the previous operator).
        // Trace again:
        // 1. Read 24. b=24.
        // 2. Read /. k=1. a=24. k=3.
        // 3. Read 4. b=4.
        // 4. Read /. k=3. else a/=b -> a=24/4=6. k=3.
        // 5. Read 3. b=3.
        // 6. Read /. k=3. else a/=b -> a=6/3=2. k=3.
        // 7. Read 2. b=2.
        // 8. Read *. k=3. else a*=b -> a=2*2=4. **Error here**. The previous operation was division, resulting in 2. The current operation is multiplication. The operand 'b' is 2. The result should be 2*2=4. This step is actually correct numerically.
        // 9. k=2.
        // 10. Read 2. b=2.
        // 11. Read *. k=2. else a*=b -> a=4*2=8. Correct.
        // 12. k=2.
        // 13. Read 3. b=3.
        // 14. Read *. k=2. else a*=b -> a=8*3=24. Correct.
        // 15. k=2.
        // 16. Read 4. b=4.
        // 17. Read =. k=2. sum += a*b -> sum += 24*4 = 96. **Error here**.
        // The variable 'a' holds the accumulated result of the chain up to the previous number. 'b' holds the current number.
        // When we read '*', we update 'a' using the PREVIOUS 'b'.
        // At step 14, a became 24. This 'a' represents "24/4/3/2*2*3".
        // Then we read 4. b=4.
        // Then we read =.
        // The last operator was '*'. So we need to multiply the accumulated 'a' (which is 24) by the current 'b' (which is 4)?
        // No. Look at step 11-14.
        // Step 11: a=4 (from 2*2). b becomes 3.
        // Step 14: a*=b -> a=4*3=12? No, trace said 8*3=24.
        // Let's re-trace carefully.
        // Start: b=24.
        // Op /: a=24, k=3. Read b=4.
        // Op /: a/=4 -> a=6, k=3. Read b=3.
        // Op /: a/=3 -> a=2, k=3. Read b=2.
        // Op *: a*=2 -> a=4, k=2. Read b=2.
        // Op *: a*=2 -> a=8, k=2. Read b=3.
        // Op *: a*=3 -> a=24, k=2. Read b=4.
        // Op =: k=2. sum += a*b => 24*4 = 96.
        // The expected result is 24.
        // The expression is 24 / 4 / 3 / 2 * 2 * 3 * 4.
        // 24/4=6, 6/3=2, 2/2=1, 1*2=2, 2*3=6, 6*4=24.
        // My trace of the code:
        // a=2 (after 24/4/3). Next num is 2. Op is /.
        // Code: a/=2 -> a=1. (My previous trace said a=2 then op *, but the input is / 2 * 2).
        // Input: 24 / 4 / 3 / 2 * 2 * 3 * 4 =
        // 1. b=24.
        // 2. /. a=24, k=3. b=4.
        // 3. /. a=6, k=3. b=3.
        // 4. /. a=2, k=3. b=2.
        // 5. *. a*=2 -> a=4?? NO. The operator before 2 was /. The operator BEFORE that was /.
        // The code updates 'a' when it sees the NEXT operator.
        // When we see '*', the previous number was 2. The previous operator was '/'.
        // So we should have done a/=2.
        // But the code does: if(q=='*') { ... else a*=b }.
        // It performs the CURRENT operator on the accumulator.
        // But the accumulator 'a' hasn't been updated with the number 'b' that was read AFTER the previous operator.
        // The logic "Read Op, Update Accumulator with Previous Num, Read Num" is mixed up.
        // Standard approach: Read Num. Read Op. If Op is high prec, update running term. If Op is low prec, add running term to sum, reset running term.
        // This code tries to do: Read Num. Loop: Read Op. If Op, process previous Num?
        // Let's look at the structure:
        // scanf("%d", &b); // Read first num
        // while(1) {
        //   scanf("%c", &q); // Read Op
        //   ... process q ... // This processes the OP just read. But it uses 'b' which is the number read BEFORE this op? No, 'b' is read at the end of the loop.
        //   So when we enter the loop body, 'b' is the number to the LEFT of the operator 'q'?
        //   First iteration: b=24. q='/'.
        //   q=='/': k=1 -> a=b (a=24). k=3.
        //   scanf("%d", &b); // b=4.
        //   Next iter: q='/'.
        //   q=='/': k=3 -> else a/=b (a=24/4=6). k=3.
        //   scanf("%d", &b); // b=3.
        //   Next iter: q='/'.
        //   q=='/': k=3 -> else a/=b (a=6/3=2). k=3.
        //   scanf("%d", &b); // b=2.
        //   Next iter: q='*'.
        //   q=='*': k=3 -> else a*=b (a=2*2=4). **This is wrong**. The operator associated with 'b'=2 was '/'. So we should divide. But we are seeing '*', so we are processing the '*' operator? No, we are processing the operator that came BEFORE the next number?
        //   The variable 'q' is the operator BETWEEN the previous 'b' and the next 'b'.
        //   When q='*', the previous 'b' is 2. The operator before 2 was '/'.
        //   The code applies the CURRENT q ('*') to the PREVIOUS b (2).
        //   But the previous b (2) should have been processed with the PREVIOUS operator ('/').
        //   The code delays processing?
        //   When q='/', it did a/=b. That processed the '/' with the number 4? No, with number 3?
        //   Let's check indices.
        //   Iter 1: q='/', b=4 (wait, b is read at end).
        //   Start: b=24.
        //   Loop 1: q='/'. Process '/'. k=1->a=24. Read b=4.
        //   Loop 2: q='/'. Process '/'. k=3->a/=4? No, a/=b where b=4. a=6. Read b=3.
        //   Loop 3: q='/'. Process '/'. k=3->a/=3. a=2. Read b=2.
        //   Loop 4: q='*'. Process '*'. k=3->a*=2. a=4. Read b=2.
        //   Here is the error. The number 2 (read in Loop 3 end) is the operand for the '/' operator (read in Loop 3 start? No, Loop 3 start q was '/').
        //   Wait.
        //   Expr: 24 / 4 / 3 / 2 * 2 ...
        //   Ops: /, /, /, *, *, *, =
        //   Nums: 24, 4, 3, 2, 2, 3, 4
        //   
        //   Init: b=24.
        //   1. q='/'. (Op between 24 and 4). Code sets a=24. Reads b=4.
        //   2. q='/'. (Op between 4 and 3). Code does a/=4. a=6. Reads b=3.
        //   3. q='/'. (Op between 3 and 2). Code does a/=3. a=2. Reads b=2.
        //   4. q='*'. (Op between 2 and 2). Code does a*=2. a=4. Reads b=2.
        //      ^^^ ERROR. The operator between 3 and 2 was '/'. The code applied '/' in step 3 using b=3.
        //      The operator between 2 and 2 is '*'. The code applies '*' in step 4 using b=2.
        //      So far: 24/4=6, 6/3=2, 2*2=4.
        //      Correct math: 24/4=6, 6/3=2, 2/2=1.
        //      The code failed to apply the third '/' to the number 2. It applied the third '/' to the number 3.
        //      Why? Because `a/=b` uses the `b` currently in memory.
        //      In Step 3, `b` is 3. The operator is `/`. So it divides by 3.
        //      The number 2 is read AFTER step 3.
        //      So the number 2 is never divided. It is multiplied in Step 4.
        //      Essentially, the code applies Operator[i] to Number[i].
        //      Op[0]='/' applies to Num[1]=4. (24/4). Correct.
        //      Op[1]='/' applies to Num[2]=3. (6/3). Correct.
        //      Op[2]='/' applies to Num[3]=2. (2/2). Should be 1.
        //      But in Step 3, b=3?
        //      Let's re-read the sequence.
        //      Init: scanf("%d", &b) -> b=24 (Num[0]).
        //      Loop 1: scanf("%c", &q) -> q='/' (Op[0]).
        //              Process Op[0]. k=1 -> a=24.
        //              scanf("%d", &b) -> b=4 (Num[1]).
        //      Loop 2: scanf("%c", &q) -> q='/' (Op[1]).
        //              Process Op[1]. k=3 -> a/=b (a=24/4=6).
        //              scanf("%d", &b) -> b=3 (Num[2]).
        //      Loop 3: scanf("%c", &q) -> q='/' (Op[2]).
        //              Process Op[2]. k=3 -> a/=b (a=6/3=2).
        //              scanf("%d", &b) -> b=2 (Num[3]).
        //      Loop 4: scanf("%c", &q) -> q='*' (Op[3]).
        //              Process Op[3]. k=3 -> a*=b (a=2*2=4).
        //              scanf("%d", &b) -> b=2 (Num[4]).
        //      
        //      The code applies Op[i] to Num[i].
        //      Op[2] is '/'. Num[2] is 3. So it divides by 3.
        //      But Op[2] is between Num[2] (3) and Num[3] (2).
        //      Standard evaluation: Num[0] Op[0] Num[1] Op[1] Num[2] Op[2] Num[3]...
        //      Left associative: ((Num[0] Op[0] Num[1]) Op[1] Num[2]) Op[2] Num[3]...
        //      Step 1: 24 / 4 = 6.
        //      Step 2: 6 / 3 = 2.
        //      Step 3: 2 / 2 = 1.
        //      
        //      The code's Step 3 calculates 6/3=2. This corresponds to applying Op[1] to Num[2].
        //      The code's Step 4 calculates 2*2=4. This corresponds to applying Op[3] to Num[3].
        //      It SKIPPED applying Op[2] ('/') to Num[3] (2).
        //      Instead, it applied Op[3] ('*') to Num[3] (2).
        //      
        //      The bug is that the code applies the CURRENT operator to the CURRENT number 'b', but 'b' is the RIGHT operand of the PREVIOUS operator?
        //      No, 'b' is read at the end of the loop.
        //      When processing Op[i], 'b' holds Num[i].
        //      Op[0] ('/') processed with Num[0] (24) to init 'a'.
        //      Op[1] ('/') processed with Num[1] (4). Result 6.
        //      Op[2] ('/') processed with Num[2] (3). Result 2.
        //      Op[3] ('*') processed with Num[3] (2). Result 4.
        //      
        //      Correct Logic should be:
        //      Op[1] ('/') should process Num[1] (4)? Yes, 24/4.
        //      Op[2] ('/') should process Num[2] (3)? Yes, 6/3.
        //      Op[3] ('/') should process Num[3] (2)? Yes, 2/2.
        //      
        //      Wait, the operators are:
        //      24 / 4 / 3 / 2 * 2 ...
        //      Op[0]=/, Op[1]=/, Op[2]=/, Op[3]=*
        //      Num[0]=24, Num[1]=4, Num[2]=3, Num[3]=2, Num[4]=2
        //      
        //      Code Trace:
        //      L1: q=Op[0]='/'. b=Num[0]=24. a=24. Read Num[1]=4.
        //      L2: q=Op[1]='/'. b=Num[1]=4. a/=4 -> 6. Read Num[2]=3.
        //      L3: q=Op[2]='/'. b=Num[2]=3. a/=3 -> 2. Read Num[3]=2.
        //      L4: q=Op[3]='*'. b=Num[3]=2. a*=2 -> 4. Read Num[4]=2.
        //      
        //      The code applies Op[i] to Num[i].
        //      Mathematically:
        //      Term 1: 24 / 4 = 6. (Op[0] applied to Num[1]? No, Op[0] is between 0 and 1).
        //      If we view it as accumulating:
        //      Acc = Num[0].
        //      Acc = Acc Op[0] Num[1].
        //      Acc = Acc Op[1] Num[2].
        //      Acc = Acc Op[2] Num[3].
        //      
        //      Code L2: Acc (a) becomes 24/4=6. Uses Op[1] and Num[1].
        //      Wait, L2 processes q=Op[1]. But it uses b=Num[1].
        //      So it calculates Num[0] Op[1] Num[1]? No, a was 24.
        //      It calculates 24 / 4. This is Num[0] Op[0] Num[1].
        //      But it used Op[1] ('/') to do it. Coincidentally Op[0]==Op[1].
        //      
        //      L3: Processes q=Op[2] ('/'). Uses b=Num[2] (3).
        //      Calculates 6 / 3. This is (Num[0] Op[0] Num[1]) Op[1] Num[2].
        //      It used Op[2] to perform Op[1]'s job?
        //      
        //      L4: Processes q=Op[3] ('*'). Uses b=Num[3] (2).
        //      Calculates 2 * 2. This SHOULD be (Prev Result) Op[2] Num[3].
        //      Prev Result was 2. Op[2] is '/'. Num[3] is 2.
        //      Correct: 2 / 2 = 1.
        //      Code: 2 * 2 = 4.
        //      
        //      The code is applying the WRONG operator. It applies Op[i+1] to Num[i].
        //      It should apply Op[i] to Num[i].
        //      
        //      Fix: We need to store the operator and apply it to the NEXT number, or apply the PREVIOUS operator to the CURRENT number.
        //      The current code reads an operator, then immediately uses it on the 'b' from the previous iteration.
        //      But 'b' from the previous iteration is the RIGHT operand of the PREVIOUS operator.
        //      So we should use the PREVIOUS operator.
        //      
        //      The variable 'k' stores the state of the PREVIOUS operator?
        //      In L1, k becomes 3 (for '/').
        //      In L2, we use k=3 to decide a/=b. This is correct for Op[0]='/'.
        //      In L2, k becomes 3 (for '/').
        //      In L3, we use k=3 to decide a/=b. This is correct for Op[1]='/'.
        //      In L3, k becomes 3 (for '/').
        //      In L4, we use k=3 to decide a/=b?
        //      NO! In L4, q='*'. The code enters `if(q=='*')`.
        //      It checks `if(k==1||k==4)`. k=3. So `else a*=b`.
        //      It uses the CURRENT operator '*' instead of the PREVIOUS operator stored in k.
        //      
        //      The logic inside `if(q=='*')` and `if(q=='/')` should depend on 'k' (the previous operator) to determine how to combine 'a' and 'b', AND THEN update 'k' to the current operator.
        //      BUT, * and / have same precedence. So if prev was * or /, we just accumulate.
        //      The accumulation operation should be determined by the PREVIOUS operator 'k', not the current 'q'.
        //      
        //      If k==2 (*), we should a*=b.
        //      If k==3 (/), we should a/=b.
        //      
        //      The code currently:
        //      if(q=='*') { ... else a*=b; k=2; }
        //      if(q=='/') { ... else a/=b; k=3; }
        //      
        //      It performs the operation corresponding to 'q', not 'k'.
        //      It should perform the operation corresponding to 'k'.
        //      
        //      Correction:
        //      Inside the loop, when we read 'q', we should process the PREVIOUS operator 'k' with the current number 'b'.
        //      Then update 'k' to 'q'.
        //      
        //      So, if q is '*' or '/', we are continuing a high-precedence chain.
        //      We should apply 'k' to 'b'.
        //      if(k==2) a*=b;
        //      if(k==3) a/=b;
        //      Then set k based on q.
        //      
        //      The current code applies 'q' to 'b'.
        //      
        //      Therefore, the lines `else a*=b` and `else a/=b` are incorrect because they use the current operator `q` (implicitly, by being in that block) instead of the previous operator `k`.
        //      Actually, the blocks are separated by q.
        //      If q=='*', it executes a*=b.
        //      If q=='/', it executes a/=b.
        //      This means it always applies the CURRENT operator to the PREVIOUS number.
        //      But we want to apply the PREVIOUS operator to the PREVIOUS number?
        //      No, we want to apply the PREVIOUS operator to the CURRENT number 'b'.
        //      
        //      Example: 24 / 4 ...
        //      L1: q='/'. k=1. a=24. Read b=4.
        //      L2: q='/'. k=3. We want to apply Op[0] ('/') to b=4.
        //      Code enters q=='/' block. Executes a/=b. Correct.
        //      
        //      Example: ... 3 / 2 * 2 ...
        //      L3: q='/'. k=3. We want to apply Op[1] ('/') to b=3.
        //      Code enters q=='/' block. Executes a/=b. Correct.
        //      Read b=2.
        //      L4: q='*'. k=3. We want to apply Op[2] ('/') to b=2.
        //      Code enters q=='*' block. Executes a*=b. **Incorrect**. Should be a/=b.
        //      
        //      So the operation should be determined by 'k', not 'q'.
        //      
        //      The fix is to change the logic inside the * and / blocks to use 'k' for the calculation, then update 'k' to reflect 'q'.
        //      
        //      However, simply swapping isn't enough because the blocks are mutually exclusive in structure? No, they are separate ifs.
        //      
        //      We need to refactor the logic for * and / to:
        //      if (q == '*' || q == '/') {
        //          if (k == 2) a *= b;
        //          else if (k == 3) a /= b;
        //          else a = b; // k==1 or 4
        //          k = (q == '*') ? 2 : 3;
        //      }
        //      
        //      The current code has:
        //      if(q=='*'){
        //          if(k==1 || k==4)a=b;
        //          else a*=b; // BUG: should depend on k
        //          k=2;c=1;
        //      }
        //      if(q=='/'){
        //          if(k==1 || k==4)a=b;
        //          else a/=b; // BUG: should depend on k
        //          k=3;c=1;
        //      }
        //      
        //      So the error is on the lines `else a*=b;` and `else a/=b;`.
        //      
        //      Also, the final calculation at `q=='='` has similar issues.
        //      if(k==2)sum+=a*b;
        //      else if(k==3)sum+=a/b;
        //      This applies the LAST operator 'k' to the last number 'b'. This is correct.
        //      
        //      So the main bug is in the accumulation steps for * and /.
        
        else sum+=a;
        break;
    }


    scanf("%d",&b);
    b=b*c;

    }
    printf("%d", sum);
}