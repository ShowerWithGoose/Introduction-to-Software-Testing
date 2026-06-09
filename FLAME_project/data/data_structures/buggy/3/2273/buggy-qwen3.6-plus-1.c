#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i;
        else
        i++;
    }
    i--;
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ The output format is incorrect. When the significant part is a single digit (integer), no decimal point should be printed. For input "0.9", l becomes 1, i becomes 2. i == l+1 is true. It prints "9e-1". Wait, the expected output is "9e-1". The buggy output was "9.e-1" in the description? No, the description says Buggy Output: 9.e-1. Let's re-read the provided Buggy Code vs Reference.
        // The code provided in the prompt under "Source Code" is different from the "Reference Program". I must annotate the "Source Code" provided at the bottom.
        // Let's trace "0.9" with the Source Code.
        // c = "0.9\n" (scanf reads char by char).
        // i=0, c[0]='0', not '.', i becomes 1.
        // i=1, c[1]='.', t=1. i stays 1? No, the else branch is only for non-dot. So i stays 1.
        // i=2, c[2]='9', not '.', i becomes 3.
        // i=3, c[3]='\n', not '.', i becomes 4.
        // EOF. Loop ends.
        // i-- -> i=3.
        // c[0]=='0' is true.
        // for(l=1; c[l]=='0'; l++); c[1] is '.', so loop doesn't run. l=1.
        // if(i==(l+1)) -> 3 == 2? False.
        // Else block:
        // k=l=1.
        // printf("%c.", c[1]) -> prints "9."
        // for(l++; l<i; l++) -> l starts at 2. c[2]='9'. Wait, c[1] was '9'? No.
        // Input "0.9". c[0]='0', c[1]='.', c[2]='9', c[3]='\n'.
        // Trace again:
        // i=0. c[0]='0'. Not '.'. i++ -> i=1.
        // i=1. c[1]='.'. t=1. i remains 1.
        // i=2. c[2]='9'. Not '.'. i++ -> i=3.
        // i=3. c[3]='\n'. Not '.'. i++ -> i=4.
        // End loop. i-- -> i=3.
        // c[0]=='0'.
        // l=1. c[1]=='.' != '0'. Loop terminates. l=1.
        // i(3) == l+1(2)? False.
        // Else:
        // k=1.
        // printf("%c.", c[1]) -> c[1] is '.'. Prints ".." ? No, c[1] is '.'. So it prints "..".
        // This logic is completely broken for finding the first significant digit.
        
        // Let's look at the specific error for "0.9".
        // Expected: 9e-1
        // The code finds the first non-zero digit incorrectly.
        // The logic `for(l=1;c[l]=='0';l++);` skips leading zeros after the decimal point? No, it stops at '.'.
        // For "0.9", l=1 (pointing to '.').
        // Then it prints c[1] which is '.'.
        // This is definitely wrong.
        
        // However, I need to identify the location of errors based on the provided Buggy Output "9.e-1" vs Expected "9e-1".
        // If the buggy output was "9.e-1", it implies the code printed a significant digit, then a dot, then exponent.
        // In the `else` block of `if(c[0]=='0')`, it does `printf("%c.",c[l]);`.
        // If `l` pointed to '9', it would print "9.".
        // Why did `l` point to '9'?
        // Maybe the input parsing or index logic is slightly different in the actual execution environment or my trace is missing something.
        // Regardless, the structural error is printing the decimal point when there are no trailing digits (single significant digit).
        
        // Let's look at the condition `if(i==(l+1))`.
        // If this condition is met, it prints `%ce-%d`. No dot.
        // If not, it prints `%c.` followed by remaining digits.
        // For "0.9", we want the "No dot" path.
        // So `i==(l+1)` should be true.
        // In my trace, `i=3`, `l=1`. `3 != 2`.
        // The variable `i` counts all characters including newline.
        // The variable `l` is index of first non-zero? No, it's just skipping '0's.
        
        // The fundamental error is that the code assumes `c[l]` is the first significant digit, but for "0.9", `c[1]` is '.'.
        // It should skip '.' as well.
        
        // But looking at the specific mismatch: "9.e-1" vs "9e-1".
        // This suggests the code entered the `else` block (printing the dot) instead of the `if` block.
        // And inside the `else` block, it printed a digit then a dot.
        
        // To fix "9.e-1" to "9e-1", we either:
        // 1. Make the `if` condition true so it takes the first branch.
        // 2. Or, if it must take the second branch, suppress the dot if there are no fractional digits.
        
        // Given the constraints and the likely intended logic of the student:
        // The student likely failed to account for the fact that `i` includes the newline or other characters, messing up the length check.
        // Or, more simply, in the `else` block, it unconditionally prints a dot.
        
        // Let's assume the question asks to annotate the line causing the extra dot.
        // That line is: `printf("%c.",c[l]);` inside the else block.
        // But correcting just that line is hard without changing structure.
        
        // Actually, looking at the provided "Buggy Output: 9.e-1", it seems the code *did* identify '9' as the digit.
        // If `c[l]` was '9', then `l` must be 2.
        // If `l` was 2, then `i==(l+1)` -> `3 == 3`? True!
        // If `i==3` and `l==2`, then `i==(l+1)` is TRUE.
        // Then it would execute `printf("%ce-%d",c[l],l);` -> `printf("9e-2");`?
        // Wait, exponent for 0.9 is -1.
        // If `l=2` (index of 9), exponent should be `-(l-1)`? Or `1-l`?
        // 0.9 = 9 * 10^-1. Index 2. 1-2 = -1.
        // The code prints `l` as exponent? `printf("%ce-%d", c[l], l);` -> `9e-2`.
        // This is also wrong exponent.
        
        // There are multiple errors.
        // 1. Logic to find first significant digit `l` is flawed (doesn't skip '.').
        // 2. Exponent calculation is likely wrong.
        // 3. Decimal point printing logic is flawed.

        // However, the prompt asks to identify the location of errors.
        // The most visible error corresponding to "9.e-1" vs "9e-1" is the printing of the dot.
        // This happens in the `else` branch.
        // Why did it go to the `else` branch? Because `i != l+1`.
        
        // Let's annotate the lines that are logically incorrect for the general case or this specific case.
        
        // Line: `printf("%c.",c[l]);`
        // Reason: It prints a decimal point even when the resulting mantissa is an integer (single significant digit). It should check if there are subsequent digits before printing the dot.
        
        // Also the line `printf("%ce-%d",c[l],l);` has wrong exponent logic for numbers < 1.
        
        // Since I must annotate the provided source code:
        
        else
        {
            int k=l;
            printf("%c.",c[l]); // @@ Incorrectly prints a decimal point. For single significant digits, no decimal point should be present. Additionally, c[l] may not be the correct significant digit due to previous logic errors.
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}