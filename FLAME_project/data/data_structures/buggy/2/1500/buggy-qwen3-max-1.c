#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1};
    char ch2[20]={'0'};
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i);
        if(ch1[i]!=-1){
            i++;
        }
        scanf(" %c",ch2+j);
        if(ch2[j]!='0'){
            j++;
        }
        if(ch2[j-1]=='='){
            break;
        }
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){
            if(ch2[i]=='/'){
                x1/=ch1[i+1];
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1); // @@ [This debug print affects output format and is not part of required output; more critically, multiplication/division are processed left-to-right but without respecting operator precedence relative to upcoming + or - that may follow later in the expression. However, the core logic flaw is below.]
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [The condition `ch2[i]=='='` is incorrect here because '=' is only at the end and should not trigger storing a new term. Also, this block runs even after processing * or / on the same operator, leading to double-processing or incorrect grouping.]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1];
            }
            if(ch2[i]=='-'){ // @@ [Similar to '+', this processes subtraction immediately without ensuring that any following * or / have been handled first. The algorithm fails to respect operator precedence: it processes * and / as they appear, but then immediately breaks the term on encountering + or -, even if the next term starts with * or /. However, the real issue is that the loop processes operators sequentially without lookahead, so expressions like "10 + 20 * 30" get broken into terms too early. Specifically, when i=0 (operator '+'), it stores x1=10 as a term and resets x1 to 20, then later when i=1 (operator '*'), it multiplies x1 (20) by 30 → 600, which is correct for that term. But the problem arises in how the final summation is done. However, the actual bug causing wrong answer is in the final summation loop range.]
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1];
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [The loop should run for `i < j`, not `i < j-1`. Because `j` terms were stored (indices 0 to j-1), and there are `j-1` operators between them, but the loop condition `i < j-1` skips the last operator. For example, if j=2 (two terms: ch1[0], ch1[1]), then operators are at ch2[0], and we need to process i=0 only → condition i < 1 is correct. Wait, let's check: after parsing "10 + 20 * 30 - 40 / 5 =", the terms become [10, 600, 8] and operators ['+', '-'], so j=3? Actually, let's trace:

Input: 10 + 20 * 30 - 40 / 5 =

After reading:
ch1 = [10, 20, 30, 40, 5]
ch2 = ['+', '*', '-', '/', '=']

Then in the for(i=0; i<len=5; i++) loop:

i=0: ch2[0]='+' → store x1=10 into ch1[0], ch2[0]='+', j=1, x1=ch1[1]=20
i=1: ch2[1]='*' → x1 = 20 * 30 = 600
i=2: ch2[2]='-' → store x1=600 into ch1[1], ch2[1]='-', j=2, x1=ch1[3]=40
i=3: ch2[3]='/' → x1 = 40 / 5 = 8
i=4: ch2[4]='=' → store x1=8 into ch1[2], ch2[2]='+', j=3, x1=ch1[5] (out of bounds, but unused)

So ch1[0]=10, ch1[1]=600, ch1[2]=8
ch2[0]='+', ch2[1]='-', ch2[2]='+'

Then sum = ch1[0] = 10
Loop: for(i=0; i < j-1 = 2; i++)
i=0: ch2[0]='+' → sum += ch1[1] → 610
i=1: ch2[1]='-' → sum -= ch1[2] → 602 → correct.

But wait, the buggy output is "600\n602", meaning the printf inside * case printed 600, and then final output 602. But expected is just 602. So the extra "600" is from the debug printf. However, the problem says "Wrong Answer", and the output is "600\n602", which is two numbers, but expected is one number "602". So the presence of the debug printf is actually causing the wrong output format.

But the problem states: "Buggy Output: 600\n602", "Expected Output: 602". So the extra line is the issue.

However, looking back, the problem says "identify the location of the errors in the program below" based on WA. The primary functional error is the debug print, but also the logic has issues.

But note: the reference program does not have such prints.

However, the bigger issue is that the algorithm does not correctly handle operator precedence in all cases because it processes * and / as it goes, but then breaks terms at + and -, which is actually correct for left-to-right with precedence. But the real bug that causes WA in general (beyond the debug print) is the handling of the '='.

But in this specific test case, the logic actually computes the correct value (602), but outputs an extra "600" due to the printf.

So the immediate cause of WA is the debug printf.

Additionally, the condition `if(ch2[i]=='+'||ch2[i]=='=')` is problematic because when ch2[i] is '=', it triggers storing a term, but then x1=ch1[i+1] accesses beyond the array (since i = len-1, i+1 = len, which is uninitialized). However, in practice, ch1[len] might be 0 or garbage, but in this test case, it didn't crash.

But the most direct error causing the wrong output (extra 600) is the printf inside the '*' case.

Also, note that the division case doesn't have a printf, so only multiplication prints intermediate results.

Therefore, the key errors are:

1. The debug printf in the '*' block causes extra output.
2. The loop condition in the final summation might be off, but in this case it worked.
3. The handling of '=' as an operator that triggers term storage is incorrect.

But the problem says the output is "600\n602", so the printf is the direct cause.

However, the instruction says: "If you think an error may occur on a particular line, add @@ symbol directly after that line and explain the reason for the error."

So we mark the printf line.

Also, the condition with '=' is wrong.

And the final loop condition might be okay, but let's see: j is the number of terms stored. After the loop, we have j terms (indices 0 to j-1), and j-1 operators (indices 0 to j-2). But in the code, when we hit '=', we do:
   ch1[j]=x1;
   ch2[j]='+';
   j++;
So for the test case, j becomes 3, and we have 3 terms. Then the final loop runs i from 0 to j-2 (i < j-1 → i<2), so i=0,1 → processes two operators, which is correct.

But the '=' handling is still logically wrong because it shouldn't be treated as a '+'.

However, the immediate cause of the WA (extra output) is the printf.

So we mark:

- The printf line: causes extra output.
- The condition with '=': incorrect logic.
- Also, the initialization of arrays: ch1[20]={-1} only sets first element to -1, rest to 0; similarly ch2[20]={'0'} sets first to '0', rest to '\0'. This might interfere with the condition checks.

Specifically, in the input loop:
   scanf(" %d",ch1+i);
   if(ch1[i]!=-1){ ... }

But if the first number is -1, this would break. However, the problem says expression is valid and starts with a number, which could be negative? But the problem says "The expression may contain spaces", and "does not contain parentheses", but doesn't say the first number can't be negative. However, the test case starts with positive.

But more critically, the condition `if(ch1[i]!=-1)` is flawed because if the user inputs -1, it would skip incrementing i. But the test case doesn't have -1.

However, the main issue for this test case is the printf.

Also, the input loop uses:
   scanf(" %c",ch2+j);
   if(ch2[j]!='0'){ ... }

But ch2 was initialized with '0' in first element, but subsequent elements are '\0'. So when reading the first operator, ch2[0] gets set, and since it's not '0', j increments. But if an operator were '0' (which it can't be, since operators are +-*/=), so it's safe. But the initialization is odd.

But the critical errors for this WA are:

1. The debug printf in the multiplication block.
2. The incorrect handling of '=' as triggering a new term with '+'.

So we annotate accordingly.
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){
            if(ch2[i]=='/'){
                x1/=ch1[i+1];
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1); // @@ [This debug print outputs intermediate results, causing extra output lines which leads to Wrong Answer as the expected output is only the final result.]
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [The '=' character should not be treated as a '+' operator. When '=' is encountered, it marks the end of the expression and should not trigger storing a new term or resetting x1, as there is no following operand. This leads to accessing ch1[i+1] beyond the valid input numbers (undefined behavior) and incorrectly appending a '+' operator.]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1];
            }
            if(ch2[i]=='-'){ // @@ [While '-' is handled similarly to '+', the fundamental issue is that the algorithm processes operators strictly left-to-right without proper precedence handling in the term accumulation phase. However, the more critical flaw is that after processing * or / for a term, encountering '+' or '-' correctly finalizes the current term. But combined with the '=' bug above, this can cause errors. In this specific test case, the '-' is handled correctly, but the '=' handling corrupts the term list.]
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1];
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [The loop condition should be `i < j` to process all stored operators, but note that `j` terms imply `j-1` operators. However, due to the erroneous handling of '=', an extra operator (as '+') is appended, making the operator count equal to `j`. Thus, this loop misses the last operator. In the test case, j becomes 3 (terms: 10,600,8) and operators stored as ['+','-','+'], so 3 operators, but the loop runs only for i=0,1 (j-1=2), missing the last '+'. However, in the test case, the last term (8) is subtracted because the '-' was stored at index 1, and the extra '+' at index 2 is not processed, but since the last term is already included via the '-' at index 1, it accidentally works. But this is fragile and incorrect in general. The root cause is the '=' misinterpretation.]
       //   printf("%d,%c\n",ch1[i],ch2[i]);
            if(ch2[i]=='+'){
                sum+=ch1[i+1];
            }
            if(ch2[i]=='-'){
                sum-=ch1[i+1];
            }
            
        }
        printf("%d",sum);
        return 0;

}