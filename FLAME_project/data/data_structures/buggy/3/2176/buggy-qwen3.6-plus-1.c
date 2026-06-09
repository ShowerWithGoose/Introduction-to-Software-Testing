#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[105];
char h[105];
char b[105];

int main()
{
    //把输入分成小数点前后
    gets(s);
    int len = strlen(s);
    int i=0,j=0;
    while(s[i] != '.')
    {
        h[j++] = s[i++];
    }
    h[j] = '\0';
    i++;
    j = 0;
    while(s[i] != '\0')
    {
        b[j++] = s[i++];
    }
    b[j] = '\0';

    int k;
    //0.xxxxx
    if(h[0]=='0')
    {
        i=0;
        while(b[i++]=='0'); // @@ The post-increment operator causes `i` to be one greater than the index of the first non-zero digit. For input "0.9", `b` is "9". `b[0]` is '9' (not '0'), so the loop condition fails immediately, but `i` becomes 1.
        k = -(i--); // @@ `i` is decremented after assignment. If `i` was 1, `k` becomes -1, then `i` becomes 0. This part logic is actually okay for calculating exponent if `i` points to the correct digit later, but let's look at the print statement.
        if(strlen(b)==(i+1)) // @@ For "0.9", `b` is "9" (len 1). `i` is 0. `i+1` is 1. Condition `1==1` is true.
            printf("%ce%d",b+i,k); // @@ `b+i` points to `b[0]` which is '9'. `k` is -1. Output: "9e-1". Wait, the buggy output provided in the prompt is "@e-1". Let's re-evaluate.
            
            // Re-evaluating the loop: `while(b[i++]=='0');`
            // Input: 0.9 -> b = "9".
            // i=0. Check b[0]=='0'? '9'=='0' is False. Loop terminates.
            // However, due to post-increment `i++`, `i` becomes 1 AFTER the check.
            // So `i` is 1.
            // `k = -(i--)`. `k` gets -1. `i` becomes 0.
            // `strlen(b)` is 1. `i+1` is 1. Condition true.
            // `printf("%ce%d", b+0, -1)` -> prints "9e-1".
            
            // Why did the prompt say Buggy Output is "@e-1"?
            // Let's look at another case. Maybe the input was different or my analysis of `gets` vs `scanf` matters? No, `gets` reads "0.9".
            // Let's look at `else if(strlen(h)==1)`.
            // If input is 0.9, h="0". h[0]=='0' is true. Enters first block.
            
            // Is it possible the error is in how `i` is handled if there ARE leading zeros?
            // Example: 0.009. b="009".
            // i=0. b[0]=='0' True. i becomes 1.
            // i=1. b[1]=='0' True. i becomes 2.
            // i=2. b[2]=='0' False ('9'!='0'). Loop terminates. i becomes 3.
            // k = -(3--) -> k=-3, i=2.
            // strlen(b)=3. i+1=3. Condition true.
            // printf("%ce%d", b+2, -3) -> b[2] is '9'. Output "9e-3". Correct.
            
            // What if the number is 0.0? Problem says "digits before and after... all digits significant". So 0.0 is likely not input or treated specially.
            
            // Let's look at the provided Buggy Output: `@e-1`.
            // The character `@` is ASCII 64. '9' is 57. '0' is 48.
            // This suggests memory corruption or reading from wrong index.
            
            // Let's look closely at: `while(b[i++]=='0');`
            // If `b` is empty? No, problem says digits after decimal.
            
            // Actually, there is a subtle bug in `while(b[i++]=='0');` if the string `b` contains ONLY zeros? But problem says significant digits.
            
            // Let's look at the `else if` branch:
            // `else if(strlen(h)==1)`
            // If input is `5.2`, h="5", b="2".
            // h[0]!='0'. strlen(h)==1.
            // printf("%c.%se0", h, b) -> "5.2e0". Correct.
            
            // If input is `0.9`, h="0", b="9".
            // h[0]=='0'.
            // i=0. b[0]=='0' is false. i becomes 1.
            // k = -(1--) => k=-1, i=0.
            // strlen(b)=1. i+1=1. Match.
            // printf("%ce%d", b+0, -1) => "9e-1".
            
            // Why does the prompt claim output is `@e-1`?
            // Perhaps the compiler/environment handles `gets` differently or `b` is not null terminated?
            // `b[j] = '\0'` is present.
            
            // Wait, look at `h` and `b` declaration. Global variables are zero-initialized.
            
            // Is it possible the error is in the `else` branch logic interfering? No.
            
            // Let's look at the `@` character.
            // If `b+i` pointed to an uninitialized memory or wrong place?
            
            // There is a known issue with `gets` being deprecated, but functionally it reads the string.
            
            // Let's reconsider the loop `while(b[i++]=='0');`.
            // If `b` is "9", `b[0]` is '9'.
            // Comparison `'9' == '0'` is false.
            // `i` increments to 1.
            
            // If the code was `while(b[i]=='0') i++;`, then `i` would be 0.
            // Then `k = -i`? No, code is `k=-(i--)`.
            
            // If the intention was to find the first non-zero digit index:
            // With `while(b[i++]=='0');`, `i` ends up being `index_of_first_non_zero + 1`.
            // Then `i--` restores it to `index_of_first_non_zero`.
            // So `b+i` points to the first non-zero digit.
            
            // If the output is `@e-1`, `@` is printed instead of `9`.
            // This implies `b[i]` is `@`.
            // `b` contains "9". `b[0]` is '9'.
            
            // Could it be that `b` is not correctly populated?
            // `while(s[i] != '\0') { b[j++] = s[i++]; }`
            // s = "0.9".
            // i starts at index of '.' + 1 = 2.
            // s[2] = '9'. b[0] = '9'. j=1, i=3.
            // s[3] = '\0'. Loop ends.
            // b[1] = '\0'.
            // b is "9".
            
            // There is no obvious reason for `@` unless `b` is corrupted.
            
            // However, looking at typical student errors:
            // In the line `printf("%ce%d",b+i,k);`, if `i` was somehow large or negative?
            
            // Let's look at the `else` branch for standard numbers.
            // `printf("%c.%s%se%d",h,h+1,b,strlen(h)-1);`
            // Format string has 4 specifiers: %c, %s, %s, %d.
            // Arguments: h (char*), h+1 (char*), b (char*), strlen(h)-1 (int).
            // First specifier is %c, but argument `h` is a char* (pointer).
            // This is a type mismatch. printf expects an int/char for %c, gets a pointer.
            // This will print garbage (often the low byte of the address, or crash).
            // For input "12.34", h="12".
            // This branch is NOT taken for "0.9".
            
            // BUT, wait. The prompt asks to identify errors based on the failed test case "0.9".
            // My analysis shows "0.9" should produce "9e-1" with the current code logic in the `if(h[0]=='0')` block.
            
            // Is it possible `h` is not "0"?
            // `while(s[i] != '.') { h[j++] = s[i++]; }`
            // s="0.9". s[0]='0'. h[0]='0'. j=1, i=1.
            // s[1]='.'. Loop ends.
            // h[1]='\0'.
            // h is "0".
            
            // There is a possibility that the "Buggy Output" provided in the prompt description corresponds to a DIFFERENT version of the code or I am missing a very subtle UB.
            // However, there is a clear error in the `else` block (last line) regarding `%c` vs `char*`.
            // And there is a potential error in the `if` block if `b` consists entirely of zeros? No, significant digits.
            
            // Let's look at the `@` again.
            // If `i` became -1?
            // `while(b[i++]=='0');`
            // If `b` was empty? `b[0]` is `\0`. `\0` != `0`. Loop doesn't run. `i` becomes 1.
            
            // Actually, if the input was just `.5`? Problem says "digits before...".
            
            // Let's assume the question implies the code IS buggy for 0.9.
            // Where could `@` come from?
            // If `b+i` points to `h`? No.
            
            // Let's look at the variable `k`.
            // `k = -(i--);`
            
            // Maybe the error is simpler.
            // In `printf("%ce%d",b+i,k);`, `b+i` is a string. `%c` prints a single character.
            // It prints `*(b+i)`.
            
            // If the code provided in the "Source Code" section is slightly different from what I'm analyzing?
            // No, I must analyze the provided source code.
            
            // Let's look at the `else if(strlen(h)==1)` block.
            // `printf("%c.%se0",h,b);`
            // Here `h` is passed to `%c`. `h` is `char*`. This is also UB.
            // If the input was `5.0`? h="5".
            // `%c` gets address of h. Prints garbage.
            
            // Although the test case is `0.9`, the presence of UB in other branches suggests the programmer misunderstands `%c` vs `%s` or pointer dereferencing.
            
            // However, for `0.9`, we enter the first `if`.
            
            // Is it possible `gets` includes the newline?
            // `gets` removes newline.
            
            // Let's look at `b[i++]` in the while loop again.
            // If `b` is "9", `b[0]` is '9'.
            
            // There is one edge case: What if `b` has trailing garbage?
            // `b` is global, so initialized to 0.
            
            // I will flag the line with `printf` in the `else` block as it is definitely wrong (Type Mismatch), and potentially the `else if` block too.
            // But for the specific failure of `0.9` resulting in `@e-1`, I suspect the environment or a hidden memory overwrite.
            // Wait! Look at `h` and `b` size. 105.
            
            // Let's look at the `else` block format string again:
            // `printf("%c.%s%se%d",h,h+1,b,strlen(h)-1);`
            // If this line was executed, it would fail. But it's not for 0.9.
            
            // Let's look at the `else if` block:
            // `printf("%c.%se0",h,b);`
            // If input was `0.9`, h="0".
            // Does `h[0]=='0'` catch it? Yes.
            
            // Is it possible the code compiled behaves differently?
            
            // I will annotate the lines with Type Mismatches in printf as they are critical errors, even if the specific trace for 0.9 seems logically correct in isolation (it might be that `@` comes from stack corruption caused by previous UB or compiler optimization assumptions).
            
            // Actually, looking closer at `while(b[i++]=='0');`
            // If `b` is "0...0X", it works.
            // If `b` is "X", it works.
            
            // One more check: `k = -(i--);`
            // If `i` is 1, `k` is -1. `i` becomes 0.
            // `printf("%ce%d", b+0, -1)`.
            
            // I will mark the printf lines that pass `char*` to `%c`.
            
            else if(strlen(h)==1)
            {
                printf("%c.%se0",h,b); // @@ [Error: Type mismatch. '%c' expects a char, but 'h' is a char*. Should be h[0].]
            }
            else
            {
                printf("%c.%s%se%d",h,h+1,b,strlen(h)-1); // @@ [Error: Type mismatch. '%c' expects a char, but 'h' is a char*. Should be h[0].]
            }
            return 0;
}