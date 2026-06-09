#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define ll long long
char s[105];
int main()
{
    scanf("%s",s);
    int i=0,len=strlen(s),j,k=0,i1;
    if(s[0]=='0')
    {
        i++; // @@ [This skips the '0' before the decimal point, but assumes input always starts with "0."; however, it doesn't verify that the next character is '.', leading to incorrect index handling if input format deviates slightly. Also, if the number is like "0.000...", this loop may go out of bounds.]
        while(s[i+1]=='0') // @@ [Accesses s[i+1] without checking if i+1 < len, which can cause buffer over-read for inputs like "0" or "0." or very short strings.]
            i++;
        printf("%c.",s[i+1]); // @@ [Again accesses s[i+1] without ensuring i+1 is within bounds; if all digits after decimal are zero (though problem says no trailing zeros, but what if only one non-zero at end?), this may still be safe per problem constraints, but logic is fragile. More critically, if the number is exactly "0.0", but problem states no trailing zeros and at least one digit before/after, so maybe not. However, main issue: if input is "0.1", then i=1 after i++, then while condition checks s[2]=='0' — which is '1', so loop doesn't run, then prints s[2]='1' → correct. But if input is "0.0001", i becomes 1, then while runs until i=3 (since s[2],s[3],s[4]? Wait: initial i=1, check s[2]=='0' → yes, i=2; check s[3]=='0' → yes, i=3; check s[4]=='0'? If s="0.0001", len=6, indices: 0:'0',1:'.',2:'0',3:'0',4:'0',5:'1'. Then i starts at 1, while(s[2]=='0') → i=2; s[3]=='0' → i=3; s[4]=='0' → i=4; then s[5] is '1', so break. Then print s[i+1]=s[5]='1' → correct. So maybe okay? But what if input is "0.0"? Problem says "all digits are significant" and "no trailing zeros after decimal", so "0.0" is invalid input. So perhaps safe. However, the real bug is in the else branch.]
        for(j=i+2;j<len;j++)
            printf("%c",s[j]);
        printf("e-%d",i);
    }
    else
    {
        while(s[i+1]!='.'&&i<len-1) // @@ [This loop tries to find the decimal point by checking s[i+1], but starts with i=0, so checks s[1]. However, if the number has no decimal point (e.g., "123"), this loop will run until i=len-1, then exit. But problem states: "has digits before and after the decimal point", so input always contains a decimal point. So maybe okay. But logic is convoluted.]
            i++;
        if(i==len-1) // @@ [This condition means no '.' was found (since loop exited because i reached len-1 without finding '.'). But problem guarantees there is a decimal point, so this block should never execute. However, the code inside this block handles trailing zeros, which contradicts problem statement ("no trailing zeros after decimal point"). This suggests the programmer misunderstood the input spec. Since input has no trailing zeros, this entire block is unnecessary and likely buggy. For example, if input were "123." (but problem says digits after decimal, so not allowed), but given spec, this block is dead code yet causes errors when active.]
        {
        while(s[len-1-k]=='0') // @@ [Problem states no trailing zeros after decimal, so this loop is based on a false assumption. Moreover, if executed, it may access invalid memory if k grows too large.]
            k++;
        if(k==len-1)
            printf("%c",s[0]);
        else
        {
        printf("%c.",s[0]);
        for(j=1;j<i+1-k;j++)
            printf("%c",s[j]);
        }
        printf("e%d",i);
        }
        else
        {
            printf("%c.",s[0]);
            for(j=1;j<len;j++)
            {
                if(s[j]!='.')
                    printf("%c",s[j]);
            }
            printf("e%d",i); // @@ [The exponent calculation is wrong. For a number like "123.45", the decimal point is at index 3 (0-based: '1','2','3','.','4','5'), so i becomes 2 (because loop: i=0→check s[1]='2'≠'.'→i=1; i=1→s[2]='3'≠'.'→i=2; i=2→s[3]=='.'→exit loop). So i=2. Exponent should be 2 (since 1.2345e2), which matches. But for "1.23", i=0 (since s[1]=='.') → exponent 0 → 1.23e0 → correct. However, what about "12.3"? i=1 → e1 → 1.23e1 → correct. So exponent seems right. BUT: the output base always prints s[0] followed by '.', then all other digits except '.', which is correct per spec (one digit before decimal, rest after). However, the problem says: "If it’s an integer, it contains only one significant digit without a decimal point." When would the base be integer? Only if original number had only one digit total? But input has digits before and after decimal, so base must be decimal with one digit before and some after. So printing decimal point is always correct. So why test case fails? Let's consider input "10.0" — but invalid per spec (trailing zero). Valid input: "10.1". Then output: "1.01e1" → correct. But wait: the reference program handles the non-zero-leading case by printing first char, then all non-dot chars. This does same. So where is error?]

            // However, note: in the 'else' branch, the code assumes the first digit is non-zero (as per problem), which is fine.

            // The critical error is actually in the 'if(s[0]=='0')' branch: the exponent is printed as 'i', but should be 'i' (number of zeros after decimal before first non-zero) → exponent is -(i+1)? Let's check:

            // Input: "0.00123"
            // Expected: 1.23e-3
            // In code: 
            //   s = "0.00123", len=7
            //   i=0 initially
            //   enter if(s[0]=='0')
            //   i++ → i=1
            //   while(s[i+1]=='0'): i+1=2 → s[2]='0' → i=2; i+1=3 → s[3]='0'? No, s[3]='1'? Wait: 
            //      indices: 0:'0', 1:'.', 2:'0', 3:'0', 4:'1', 5:'2', 6:'3'
            //   After i=1, check s[2]=='0' → yes → i=2
            //   check s[3]=='0' → yes → i=3
            //   check s[4]=='1' → no → break
            //   Then print s[i+1] = s[4] = '1'
            //   Then print rest from j=5 to 6: '2','3'
            //   So output: "1.23"
            //   Exponent: e-%d with i=3 → e-3 → correct.

            // So that seems okay.

            // Then why compilation error? Wait, the "Error type" says "Compilation Error", but the test case output shows "/bin/sh: 1: gcc: not found", which is NOT a compilation error in the code, but an environment issue. However, the instruction says: "identify the location of the errors in the program below" based on the failed test case.

            // But looking back: the user says "Error type: Compilation Error", but the provided source code uses standard headers and syntax. However, note: the code uses 'gets' in the reference program, but the buggy code uses 'scanf("%s",s)' which is safe.

            // Wait — the actual issue might be that the code declares 'i1' but never uses it — that's not a compilation error.

            // Another possibility: the code uses variable-length array? No, s is fixed size.

            // But note: the problem says the test case input caused a compilation error, but the output is "gcc: not found", which implies the system couldn't compile because gcc wasn't installed — not a code error. However, the task is to find errors in the program logic that cause wrong output, despite the "Error type" label.

            // Re-examining the problem: the expected behavior vs actual.

            // Consider input: "0.1"
            // Buggy code:
            //   s = "0.1", len=3
            //   i=0 → enter if
            //   i++ → i=1
            //   while(s[i+1]=='0') → s[2]=='1' ≠ '0' → skip loop
            //   printf("%c.",s[i+1]) → s[2]='1' → prints "1."
            //   then j from i+2=3 to len=3 → no loop
            //   then "e-%d",i=1 → "1.e-1"
            // But expected scientific notation: "1e-1" OR "1.0e-1"? Problem says: if base is decimal, must have one digit before and after decimal point. So "1." is not valid because there's no digit after decimal. It should be just "1e-1" (integer base) only if there are no fractional digits, but here we have one significant digit after? Wait, input is "0.1" → one digit after decimal, which is significant. So base should be "1." followed by nothing? But problem says: "if it’s a decimal, it must have one significant digit before and after the decimal point". That implies there must be at least one digit after the decimal in the base. But in this case, the original number has only one non-zero digit total. So the base should be "1" (integer) or "1." with no extra digits?

            // Clarify problem statement: 
            // "If it’s a decimal, it must have one significant digit before and after the decimal point"
            // This suggests that if there are additional significant digits beyond the first, they go after the decimal. But if there's only one significant digit total, then the base should be an integer (no decimal point).

            // Example: 
            // Input "0.1" → only one significant digit → output "1e-1"
            // Input "0.10" → invalid (trailing zero)
            // Input "0.12" → two significant digits → "1.2e-1"

            // In the buggy code, for "0.1", it outputs "1.e-1", which has a decimal point but no digit after — violating the requirement.

            // Similarly, in the else branch, if input is "5.0" (invalid per spec, but say "5.1" is valid), but what about "7."? Not allowed. But consider "1.0" — invalid. So all inputs have at least one digit after decimal, and all are significant, so the base should always have at least one digit after decimal? Not necessarily: if the input is "0.1", there's only one significant digit, so after normalization, there are no additional digits to put after the decimal.

            // Therefore, the base should be printed as an integer (without decimal point) when there's only one significant digit.

            // The buggy code always prints a decimal point in the 'if' branch: printf("%c.",s[i+1]); — even when there are no more digits.

            // So for "0.1", it prints "1." which is invalid.

            // Similarly, in the else branch, it always prints "%c." — so for input "5.0" (invalid) but if input were "5" (also invalid per spec), but per spec input always has decimal and digits after. However, if input is "1.2", then two digits → "1.2e0" is correct. But if input is "9.0" — invalid. So the only time we have single significant digit is in numbers like "0.000...d" where d is single non-zero, or "d.000..." but latter is invalid due to trailing zeros.

            // Therefore, the error is: the program always prints a decimal point in the base, even when there are no fractional digits to show.

            // Specifically, in the 'if' branch: after printing the first non-zero digit, if there are no more digits (j loop runs zero times), it should not print the decimal point.

            // Same in the else branch: if the original number had only one digit before decimal and no digits after (but problem says there are digits after, so maybe not). However, consider input "1.0" — invalid. But what about "1.2"? valid, two digits → needs decimal. But if input is "5.0001", then multiple digits → needs decimal.

            // The only problematic case is when the entire number has exactly one significant digit, which only happens in the 'if' branch (like "0.0005").

            // So in the 'if' branch, after the first non-zero digit, if there are no more digits (i+2 >= len), then we should print just the digit, not with a decimal point.

            // The current code does: 
            //   printf("%c.",s[i+1]);
            //   then prints rest
            // So even if rest is empty, it prints "x." which is invalid.

            // Therefore, the error is on this line: it unconditionally prints a decimal point.

            // Similarly, in the else branch, it always prints "%c." — but according to problem, if the base is integer (only one significant digit), no decimal. But in the else branch, the input has non-zero first digit and digits after decimal, so there are at least two significant digits (the first digit and at least one after), so base should be decimal. So else branch is okay.

            // Only the 'if' branch has the issue.

            // So the line: printf("%c.",s[i+1]); is wrong because it always adds a decimal point, even when there are no following digits.

            // Additionally, the exponent calculation might be off in edge cases, but the decimal point is the main format violation.

            // Also, in the 'if' branch, the code does not handle the case where after the first non-zero digit, there are no more digits — it should omit the decimal point.

            // Therefore, the error is on the line: printf("%c.",s[i+1]);

        }
    }
    return 0; 
}