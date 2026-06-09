#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char s[1009];
int main()
{
    gets(s);
    int l,wc,wd; // @@ [Variables wc and wd are uninitialized. If the input format is unexpected or logic flows incorrectly, using them leads to undefined behavior. Specifically, wc is used in conditions before being guaranteed a value if no '.' is found, though problem states there is one.]
    l=strlen(s);
    for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i;
    if(wc>1) 
    {
        printf("%c.",s[0]);
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]);
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]!='0') 
    {
        printf("%c.",s[0]); // @@ [The problem states: "If it’s an integer, it contains only one significant digit without a decimal point." Here, for input like "5.0" (though problem says no trailing zeros, so maybe "5.123"), if the number is effectively an integer or just has one digit before decimal, the output format might be wrong. However, looking at the specific failure: Input 0.00000009123456789012. This branch is not taken. The issue is in the next branch.]
        for (int i=1;i<=l-1;i++)if(s[i]!='.')printf("%c",s[i]);
        printf("e%d",wc-1);
        
    }
    if(wc==1&&s[0]=='0') 
    {
            for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i; // @@ [Variable wd is uninitialized if all digits after '0.' are '0', but problem says no trailing zeros and digits are significant. More importantly, this loop finds the first non-zero digit. For "0.0000000912...", wd will be the index of '9'.]
            
            if(wd==l-1)    printf("%ce-%d",s[wd],wd-1); // @@ [Logic Error: If the last digit is the first non-zero one (e.g. 0.009), it prints "9e-2". But standard scientific notation usually requires a decimal point if there are following digits, or just the digit if it's the only one. The bigger issue is the else block below.]
            else    {printf("%c.",s[wd]);for (int i=wd+1;i<=l-1;i++) printf("%c",s[i]);printf("e-%d",wd-1);} // @@ [Logic Error: The exponent calculation is wrong. For input "0.0000000912...", the first non-zero digit '9' is at index 8 (0-indexed: s[0]='0', s[1]='.', s[2]..s[7]='0', s[8]='9'). The exponent should be -8. The code calculates wd-1. If wd=8, it prints e-7. Wait, let's trace carefully.
// Input: 0.00000009123456789012
// Indices: 0:0, 1:., 2:0, 3:0, 4:0, 5:0, 6:0, 7:0, 8:0, 9:9 ...
// Wait, count zeros: 0.00000009...
// s[0]='0'
// s[1]='.'
// s[2]='0'
// s[3]='0'
// s[4]='0'
// s[5]='0'
// s[6]='0'
// s[7]='0'
// s[8]='0'
// s[9]='9'
// So wd becomes 9.
// Exponent printed: e-(9-1) = e-8. This part seems correct for the exponent value.
// Output generated: 9.123456789012e-8.
// Why did it fail?
// Let's look at the "Buggy Output": 2e-20.
// This suggests the code didn't even enter this block correctly or printed garbage.
// Ah, look at the variable initialization. `int l,wc,wd;`
// `wc` is set in the loop.
// `wd` is NOT initialized.
// In the branch `if(wc==1&&s[0]=='0')`, we enter the loop `for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i;`.
// If the input was `0.00000009123456789012`, `wd` gets set to 9.
// Then `else` branch executes: `printf("%c.",s[9])` -> '9.'. Then prints rest. Then `e-8`.
// This matches Expected Output.
// Why did the test case fail with `2e-20`?
// Perhaps the previous `if` blocks fell through?
// No, `wc` is 1. `s[0]` is '0'. Only the last block runs.
// Is it possible `gets` read something else? Or `wc` wasn't set?
// If `wc` was uninitialized garbage, it might skip all blocks or enter wrong one.
// But `for (int i=1;i<=l-1;i++)if(s[i]=='.')wc=i;` sets wc.
// Let's re-read the buggy output: `2e-20`.
// This looks like it printed a digit '2', then 'e-20'.
// Where could '2' come from? The last digit of the input is '2'.
// Where could '-20' come from? Length of string is ~22.
// It seems like it might have executed `if(wd==l-1)` branch?
// If `wd` happened to be `l-1` due to uninitialized memory or logic error?
// Actually, there is a subtle bug: `wd` is not initialized. If the loop `for (int i=2;i<=l-1;i++) if(s[i]!='0')wd=i;` does NOT run (impossible here as there are non-zeros), or if it relies on previous stack garbage.
// BUT, look at the first two `if` statements. They do not have `else`.
// If `wc > 1`, it prints.
// If `wc == 1 && s[0] != '0'`, it prints.
// If `wc == 1 && s[0] == '0'`, it prints.
// These are mutually exclusive for valid inputs.
// However, the variables `wc` and `wd` are local and uninitialized.
// The primary error leading to unpredictable behavior (like the specific wrong answer in some environments or compilers) is the lack of initialization for `wc` and `wd`. If the compiler optimizes or stack contains garbage, and if the loop for `wc` somehow fails (it shouldn't), `wc` is garbage.
// But specifically for the provided test case, the logic seems correct IF variables are clean.
// Wait, look at `if(wd==l-1)`.
// If the number was `0.00000000000000000002` (20 zeros?), then `wd` would be `l-1`.
// The input is `0.00000009123456789012`.
// Maybe the issue is `gets` is deprecated/unsafe? No, that doesn't change logic.
// Let's look at the Buggy Output again: `2e-20`.
// This implies `s[wd]` was '2'. And `wd-1` was 20? So `wd`=21?
// String: `0.00000009123456789012`
// Length: 1 (0) + 1 (.) + 7 (0s) + 1 (9) + 12 (digits) = 22 chars?
// Indices 0..21.
// Last char is '2' at index 21.
// If `wd` became 21, it means the loop `if(s[i]!='0')wd=i` updated `wd` all the way to the last character?
// NO, it breaks? No, it doesn't break. It continues updating `wd` every time it finds a non-zero digit.
// So `wd` will hold the index of the LAST non-zero digit, not the FIRST.
// The problem requires scientific notation starting with the FIRST significant digit.
// The code finds the LAST significant digit because it lacks a `break` statement.
// Therefore, `wd` becomes the index of the last digit '2'.
// Then it prints `2` (or `2.`...) and exponent based on last digit.
// This explains the error perfectly.]
    }




return 0;
}