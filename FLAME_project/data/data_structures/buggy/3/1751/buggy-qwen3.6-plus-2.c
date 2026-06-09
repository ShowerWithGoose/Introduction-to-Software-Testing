#include<stdio.h>
#include<string.h>
int main()
{
    char num[105];
    char num1[105],num2[105];
    gets(num);
    int i=0,j=0;
    for(i=0,j=0;num[i]!='\0';i++)
    {
        if(num[i]!='.')
        {
            num1[j++]=num[i];
        }
        else
        {
            break;
        }
    }
    for(i+=1,j=0;num[i]!='\0';i++)
    {
        num2[j++]=num[i];
    }
    
    int a=(int)strlen(num1);
    if(a==1)
    {
        if(num1[0]!='0')
        {
            for(i=0;num[i]!='\0';i++)
            {
                printf("%c",num[i]);
            }
            printf("e0");
        }
        else if(num1[0]=='0')
        {
            for(i=0;num2[i]!='\0';i++)
            {
                if(num2[i]!='0')
                {
                    break;
                }
            }
            int k=i;
            printf("%c",num2[k]);
            if(num2[k+1]!='\0')
            {
                printf(".");
            }
            for(i+=1;num2[i]!='\0';i++)
            {
                printf("%c",num2[i]);
            }
            printf("e-%d",k+1); // @@ The format specifier "e-%d" incorrectly outputs a literal '-' followed by the positive value of k+1. For input 0.9, k=0, so it prints "e-1". However, the problem states that if the exponent is negative, it should be prefixed with a '-'. The calculation k+1 is correct for the magnitude (1), but the manual '-' combined with %d which prints positive numbers works for this specific case "e-1". Wait, let's re-read the expected output. Expected: 9e-1. My code prints: 9.e-1? No. 
            // Let's trace 0.9.
            // num1 = "0", num2 = "9".
            // a=1. num1[0]=='0'.
            // Loop for i: num2[0]='9' != '0', breaks. i=0. k=0.
            // printf("%c", num2[0]) -> prints '9'.
            // num2[1] is '\0', so if(num2[k+1]!='\0') is false. No decimal point.
            // Loop for i+=1 (i becomes 1). num2[1] is '\0'. Loop doesn't run.
            // printf("e-%d", k+1) -> prints "e-1".
            // Total output: "9e-1". This matches the expected output.
            
            // Why did the prompt say the buggy output was wrong?
            // The prompt provided a "Reference Program" which was buggy, and a "Source Code" which is the one I need to annotate.
            // The "Test Case Input" and "Buggy Output" likely refer to the *Reference Program* or a previous version, OR they refer to the current Source Code if it is indeed buggy.
            // Let's check another case. 0.09.
            // num1="0", num2="09".
            // i=0, num2[0]='0' == '0', continue.
            // i=1, num2[1]='9' != '0', break. k=1.
            // printf("%c", num2[1]) -> '9'.
            // num2[2] is '\0'. No decimal.
            // Loop i=2. End.
            // printf("e-%d", 1+1) -> "e-2".
            // Output: "9e-2". Correct.
            
            // Let's check 0.00102.
            // num1="0", num2="00102".
            // i=0, '0'. i=1, '0'. i=2, '1'. Break. k=2.
            // printf("%c", '1').
            // num2[3] is '0' != '\0'. Print ".".
            // Loop i=3. Print '0', '2'.
            // printf("e-%d", 3). -> "e-3".
            // Output: "1.02e-3". Correct.

            // Is there an error in the `else` block (a > 1)?
            // Input 12.34.
            // num1="12", num2="34". a=2.
            // printf("%c.", '1') -> "1."
            // Loop i=1. num1[1]='2'. Print '2'. -> "1.2"
            // Loop i=0. num2[0]='3', num2[1]='4'. Print "34". -> "1.234"
            // printf("e%d", 2-1) -> "e1".
            // Output: "1.234e1". Correct.

            // Input 10.0. Note: "all digits are significant... no trailing zeros". So 10.0 won't happen. 10.1 maybe.
            // Input 10.1
            // num1="10", num2="1". a=2.
            // printf "1."
            // Loop i=1. num1[1]='0'. Print '0'. -> "1.0"
            // Loop num2. Print '1'. -> "1.01"
            // printf "e1".
            // Output: "1.01e1". Correct.

            // What about 0.0? Problem says "digits before and after decimal point". "If there’s only one digit before... it can be 0". "first digit before... cannot be 0" otherwise.
            // Does 0.0 exist? "no trailing zeros after decimal point". If input is 0.0, the zero after decimal is trailing? Or significant? Usually 0.0 implies value 0. Scientific notation 0e0?
            // If input is 0.1, output 1e-1.
            
            // Let's look closely at the "Buggy Output" provided in the prompt: `0.Уід■9e5`. This looks like memory garbage / undefined behavior.
            // The "Source Code" provided below seems logically correct for the standard cases.
            // However, `gets` is deprecated and dangerous, but usually not the cause of WA in these online judges unless buffer overflow.
            
            // Is there a subtle error?
            // `printf("e-%d",k+1);`
            // The problem says: "If it’s negative, it is prefixed with a - sign".
            // My code prints `e-1`. This is correct.
            
            // Wait, look at the first `if` block: `if(num1[0]!='0')`.
            // Input: 5.2
            // num1="5", num2="2". a=1.
            // Prints "5.2e0".
            // Problem: "If it’s an integer, it contains only one significant digit without a decimal point."
            // But 5.2 is not an integer. The base is 5.2.
            // Format: "The base is either a decimal or an integer... If it’s a decimal, it must have one significant digit before and after the decimal point".
            // So 5.2e0 is correct.
            
            // What if the number is 5.0? "no trailing zeros". So 5.0 is likely represented as 5. or just 5?
            // Input format: "digits before and after the decimal point". So 5.0 is valid input?
            // If input is 5.0, num1="5", num2="0".
            // Output: 5.0e0.
            // Base: 5.0. One digit before (5), one after (0). Is 0 significant? "all digits are significant".
            // So 5.0e0 is likely correct.

            // Let's re-read the error description carefully.
            // "Test Case Input: 0.9"
            // "Buggy Output: 0.Уід■9e5"
            // "Expected Output: 9e-1"
            
            // The buggy output `0.Уід■9e5` strongly suggests that the code printing the result is reading from uninitialized memory or incorrect indices.
            // In the provided Source Code, for 0.9:
            // num1="0", num2="9".
            // It goes to `else if(num1[0]=='0')`.
            // It prints `num2[k]` which is `num2[0]` = '9'.
            // It does NOT print '.' because `num2[1]` is '\0'.
            // It does NOT print remaining decimals.
            // It prints `e-1`.
            // Result: `9e-1`.
            
            // This matches the Expected Output.
            // Why is this marked as Wrong Answer / Buggy?
            
            // Perhaps the "Source Code" provided IS the buggy code, but the bug only manifests on other inputs, or the "Buggy Output" shown corresponds to the *Reference Program* in the prompt description, not the *Source Code* at the bottom?
            // The prompt asks: "identify the location of the errors in the program below."
            // The program below is the one starting with `#include<stdio.h>`.
            
            // If the code below produces correct output for 0.9, maybe it fails elsewhere?
            // Or maybe I am missing a detail.
            
            // Let's look at `printf("e-%d",k+1);`.
            // If k=0, prints e-1.
            // If k=1, prints e-2.
            
            // Is it possible the issue is `gets`? No.
            
            // Let's look at the `else` branch (a > 1).
            // `printf("%c.",num1[0]);`
            // `for(i=1;num1[i]!='\0';i++) printf("%c",num1[i]);`
            // `for(i=0;num2[i]!='\0';i++) printf("%c",num2[i]);`
            // `printf("e%d",a-1);`
            
            // Consider input `100.5`.
            // num1="100", num2="5". a=3.
            // Output: `1.005e2`.
            // Base: 1.005. Decimal. One digit before (1). Digits after (005).
            // Problem: "no trailing zeros after the decimal point". Input has none. Output has none.
            // Correct.

            // Consider input `0.0001`.
            // num1="0", num2="0001".
            // k=3.
            // Print `num2[3]` -> '1'.
            // `num2[4]` is '\0'. No dot.
            // Print `e-4`.
            // Output: `1e-4`.
            // Correct.

            // Consider input `0.101`.
            // num1="0", num2="101".
            // k=0.
            // Print `1`.
            // `num2[1]` is '0' != '\0'. Print `.`.
            // Loop i=1. Print `0`, `1`.
            // Print `e-1`.
            // Output: `1.01e-1`.
            // Correct.

            // There seems to be no logical error in the provided Source Code for the standard cases.
            // HOWEVER, looking at the `Buggy Output` again: `0.Уід■9e5`.
            // This looks like the output of the *Reference Program* provided in the text above the Source Code.
            // The Reference Program uses `gets(num)` and complex logic with `num2` shifting.
            // The Source Code provided at the bottom is a *different* implementation.
            
            // Is it possible the Source Code at the bottom ALSO has an error?
            // Let's check `if(num2[k+1]!='\0')`.
            // If `num2` is "9", `k=0`. `num2[1]` is `\0`. Condition false.
            // If `num2` is "09", `k=1`. `num2[2]` is `\0`. Condition false.
            // If `num2` is "009", `k=2`. `num2[3]` is `\0`. Condition false.
            // If `num2` is "12", `k=0`. `num2[1]` is '2'. Condition true. Prints dot.
            
            // Wait! What if `num2` is empty?
            // Input `5.`? Problem says "digits before and after". So `num2` is not empty.
            
            // I will scrutinize the `else` part of `a==1` again.
            // `printf("e-%d",k+1);`
            // The problem says: "If it’s negative, it is prefixed with a - sign".
            // It does NOT say "print e-<positive>". It says "prefixed with a - sign".
            // Standard scientific notation: `1.23e-4`.
            // My code: `e-4`. This is standard.
            
            // Is there a case where `k+1` is 0?
            // If input is `0.1`, k=0. Exp -1.
            // If input is `0.0...01`, k >= 0. Exp >= -1.
            // Exponent is always negative for 0.xxxx where x starts with zeros.
            
            // Actually, there is one potential issue.
            // `gets` is unsafe. But typically not WA.
            
            // Let's look at the headers.
            // `#include<stdio.h>`
            // `#include<string.h>`
            
            // I suspect the error might be related to how `num2` is handled if it contains only zeros?
            // But problem says "all digits are significant", so `0.0` is unlikely or treated specifically.
            // If input is `0.0`, `num2`="0".
            // Loop `for(i=0;num2[i]!='\0';i++)` -> `num2[0]='0'`. `if!='0'` is false.
            // Loop finishes. `i` becomes 1.
            // `k=1`.
            // `printf("%c", num2[1])` -> `num2[1]` is `\0`. Prints nothing or garbage?
            // Accessing `num2[k]` where `k` is index of first non-zero.
            // If all are zero, loop terminates when `num2[i]=='\0'`.
            // Then `k=i`.
            // If `num2` is "0", `i` becomes 1. `k=1`.
            // `num2[1]` is out of bounds (null terminator).
            // This would print garbage.
            // However, `0.0` violates "no trailing zeros" if interpreted strictly, or implies value 0.
            // If the test case `0.9` is failing, my analysis says it passes.
            
            // Let's assume the question implies the provided Source Code IS the buggy one corresponding to the Buggy Output.
            // But the Buggy Output `0.Уід■9e5` is wildly different from `9e-1`.
            // The provided Source Code produces `9e-1` for `0.9`.
            
            // Could the error be in the `else` block of `a!=1`?
            // No, `0.9` has `a=1`.
            
            // I will mark the line with `gets` as potentially dangerous, but logically the code seems fine for `0.9`.
            // However, often in these problems, if `num2` is large, `strlen` inside loop is bad, but here it's not used in loop condition.
            
            // Wait, look at this line:
            // `for(i+=1;num2[i]!='\0';i++)`
            // If `k` was the index of the first non-zero digit.
            // We printed `num2[k]`.
            // We want to print the rest.
            // The loop starts at `i+=1`.
            // In the previous loop `for(i=0...break)`, `i` is the index of the first non-zero.
            // So `k=i`.
            // Then `i+=1` makes `i` the next character.
            // This is correct.

            // I will provide the code with no annotations if I truly believe it is correct for the given case, BUT the prompt insists on identifying errors.
            // Is it possible `num1` or `num2` are not null-terminated?
            // `num1[j++]=num[i]`. `j` increments.
            // When loop breaks, `num1` is NOT null-terminated explicitly.
            // `strlen(num1)` relies on `num1` having a `\0`.
            // `char num1[105]` is global/local? Local. Uninitialized.
            // If `num1` does not get a `\0`, `strlen` will read garbage.
            
            // Line 13: `num1[j++]=num[i];`
            // After the loop, `num1` needs `\0`.
            // Same for `num2`.
            
            // Line 19: `num2[j++]=num[i];`
            // After this loop, `num2` needs `\0`.
            
            // If `num1` is not null-terminated, `strlen(num1)` is undefined behavior.
            // For `0.9`:
            // `num1` gets '0'. `j`=1. Loop breaks.
            // `num1` is `{'0', ?, ?, ...}`.
            // `strlen(num1)` scans until `\0`. If `num1[1]` happens to be 0, it works. If not, it crashes/garbage.
            // This is the error!
            
            // Annotations needed:
            // 1. After copying to `num1`, add `\0`.
            // 2. After copying to `num2`, add `\0`.
}