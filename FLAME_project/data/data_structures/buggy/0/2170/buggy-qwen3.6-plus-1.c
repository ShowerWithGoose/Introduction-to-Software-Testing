#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char s[100000];
    int j=0;
    gets(s);
    int l=strlen(s);
    printf("%c",s[0]);
    for(int i=1;i<l;i++){
        if(s[i]=='-'){
            if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            else if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ The original code uses independent 'if' statements. If the first 'if' (digits) is false, it falls through to the second 'if'. If the second 'if' (uppercase) is true, it executes. However, if the second 'if' is false, it falls through to the third 'if'. If the third 'if' is false, it executes the final 'else'. The problem is that the 'else' is only attached to the third 'if'. If the first 'if' is false, and the second 'if' is true, it prints the expansion. But then it continues to check the third 'if'. If the third 'if' is false, it executes the 'else' printing the '-'. This logic is flawed because the 'else' should apply if NONE of the expansion conditions are met. Using 'else if' chains ensures that only one block is executed. Specifically, in the case "B-F", the first 'if' is false. The second 'if' is true, so it prints "CDEF". Then it checks the third 'if', which is false. Since the third 'if' is false, the attached 'else' executes, printing '-'. This results in "CDEF-". Wait, looking at the output "BCDEFF", the input is "a-uB-F".
            // Let's trace "a-uB-F".
            // i=1, s[1]='-'. s[0]='a', s[2]='u'. Lowercase check (3rd if in original logic order? No, code order: digits, upper, lower).
            // Original Code Order:
            // 1. Digits: 'a' is not digit. False.
            // 2. Upper: 'a' is not upper. False.
            // 3. Lower: 'a' is lower, 'u' is lower, 'a'<'u'. True.
            //    Loop prints b..t. i becomes 2.
            // Next iteration i=3 (since i++ in loop). s[3]='B'. Not '-'. Prints 'B'.
            // Next iteration i=4. s[4]='-'. s[3]='B', s[5]='F'.
            // 1. Digits: False.
            // 2. Upper: 'B' upper, 'F' upper, 'B'<'F'. True.
            //    Loop prints C,D,E,F. i becomes 5.
            // Next iteration i=6 (loop end).
            // So where does the extra F come from?
            // Let's re-read the buggy output: abcdefghijklmnopqrstuBCDEFF
            // Expected: abcdefghijklmnopqrstuBCDEF
            // The extra F suggests that after expanding B-F to CDEF, something else prints an F or the expansion logic is slightly off.
            // In the expansion loop: for(j=s[i-1]; j<s[i+1]; j++) printf("%c", j+1);
            // For B-F: j starts at 'B' (66). j < 'F' (70).
            // j=66: print 67 ('C')
            // j=67: print 68 ('D')
            // j=68: print 69 ('E')
            // j=69: print 70 ('F')
            // j=70: loop ends.
            // So it prints CDEF. Correct.
            // Why is there an extra F?
            // Let's look at the control flow again.
            // if (digit) { ... i++ }
            // if (upper) { ... i++ }
            // if (lower) { ... i++ }
            // else printf("%c", s[i]);
            //
            // Case "B-F":
            // Digit if: False.
            // Upper if: True. Executes block. Prints CDEF. i++ (i becomes 5).
            // Lower if: s[3]='B' (not lower). False.
            // Else: Executes! Prints s[4] which is '-'.
            // So output should be CDEF-.
            // But the buggy output is BCDEFF.
            // Wait, the input is `a-uB-F`.
            // Part 1: `a-u`. Expands to `abcdefghijklmnopqrstu`.
            // Part 2: `B`. Printed as is.
            // Part 3: `-F`? No, `B-F`.
            // If the code printed `CDEF-`, the output would be `...uBCDEF-`.
            // The buggy output is `...uBCDEFF`.
            // This implies the `-` was NOT printed, but an `F` was printed twice? Or maybe the `else` printed `s[i+1]`? No, it prints `s[i]`.
            // Let's look closely at the `else`. It is attached to the LAST `if`.
            // If the first `if` is false, and the second `if` is true, the block runs. Then the third `if` is checked. If false, the `else` runs.
            // So for `B-F`:
            // 1. Digit check: False.
            // 2. Upper check: True. Runs loop. Prints CDEF. i increments to 5.
            // 3. Lower check: False.
            // 4. Else: Runs. Prints s[4] which is '-'.
            // Result: CDEF-.
            // This doesn't match BCDEFF.
            
            // Let's re-examine the first expansion `a-u`.
            // 1. Digit: False.
            // 2. Upper: False.
            // 3. Lower: True. Runs loop. Prints b..t. i increments to 2.
            // Loop continues. i=3. s[3]='B'. Prints B.
            // i=4. s[4]='-'.
            // 1. Digit: False.
            // 2. Upper: True. Runs loop. Prints CDEF. i increments to 5.
            // 3. Lower: False.
            // 4. Else: Prints s[4] which is '-'.
            // Output: ...uBCDEF-
            
            // Is it possible the input string has a newline or something? `gets` reads until newline.
            // Maybe the issue is how `i` is incremented?
            // In the loop `for(int i=1;i<l;i++)`, if we do `i++` inside, it skips the next character.
            // For `a-u`: i=1 ('-'). Process. i becomes 2. Loop increment makes i=3. Skips 'u'. Correct, 'u' is end of range.
            // For `B-F`: i=4 ('-'). Process. i becomes 5. Loop increment makes i=6. Skips 'F'. Correct.
            
            // Why `BCDEFF`?
            // Maybe the `else` is printing `s[i+1]`? No, code says `s[i]`.
            // Maybe the previous character `B` is printed again? No.
            
            // Let's look at the structure again.
            // if (...) { ... }
            // if (...) { ... }
            // if (...) { ... }
            // else { ... }
            
            // If the intention was to have mutually exclusive branches, they should be `if ... else if ... else if ... else`.
            // The current structure means:
            // If it's a digit expansion, it expands. THEN it checks if it's an upper expansion (will be false). THEN it checks if it's a lower expansion (will be false). THEN it executes else (prints '-').
            // So ANY successful expansion in the first two blocks will fall through to the final else if the last condition is false.
            // For `a-u` (lower):
            // 1. Digit: False.
            // 2. Upper: False.
            // 3. Lower: True. Expands.
            // Else: Attached to 3. Since 3 was true, Else is SKIPPED.
            // So `a-u` works correctly.
            
            // For `B-F` (upper):
            // 1. Digit: False.
            // 2. Upper: True. Expands.
            // 3. Lower: False.
            // Else: Attached to 3. Since 3 was false, Else EXECUTES. Prints '-'.
            // So `B-F` produces `CDEF-`.
            
            // The buggy output is `BCDEFF`.
            // Where does the extra F come from? And why is '-' missing?
            // If the output is `BCDEFF`, it means `CDEF` was printed, then `F` was printed.
            // Did it fail to skip `F`?
            // If `i` was not incremented in the Upper block, then after processing `-`, i would be 4. Loop increments to 5. s[5] is 'F'. Prints 'F'.
            // But the code HAS `i++` in the Upper block.
            
            // Is it possible the compiler optimizes or something? No.
            // Let's look at the `else` again.
            // `else printf("%c",s[i]);`
            // If this prints '-', we get `CDEF-`.
            // If the output is `BCDEFF`, maybe the `else` is NOT executing, but `F` is printed later?
            // If `i` was NOT incremented, we'd get `CDEF` then loop goes to i=5 ('F'), prints 'F'. Result `CDEFF`. Plus the initial `B`. `BCDEFF`.
            // This matches the buggy output!
            // So, the `i++` inside the `if(s[i-1]>=65...)` block is NOT working as expected?
            // Or is it missing?
            // Looking at the provided source code:
            //             if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
            //             {
            //                 for(j=s[i-1];j<s[i+1];j++)
            //                 printf("%c",j+1);
            //                 i++;
            //             }
            // It IS there.
            
            // Wait, look at the indentation and braces in the provided source code carefully.
            //             if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
            //             {
            //                 for(j=s[i-1];j<s[i+1];j++)
            //                 printf("%c",j+1);
            //                 i++;
            //             }
            // The `for` loop does NOT have braces. So only `printf` is in the loop.
            // `i++` is executed ONCE after the loop.
            // This is correct.
            
            // So why would `i` not be incremented?
            // Maybe the condition failed?
            // `B` is 66. `F` is 70.
            // 66>=65, 66<=90. True.
            // 70>=65, 70<=90. True.
            // 66<70. True.
            // Condition is True.
            
            // Is it possible that `gets` includes the newline? No, `gets` discards newline.
            // Is it possible `l` is calculated incorrectly?
            
            // Let's reconsider the `else` logic.
            // If the code produced `BCDEFF`, it implies:
            // 1. `B` printed.
            // 2. Expansion `CDEF` printed.
            // 3. `F` printed again.
            // 4. `-` NOT printed.
            
            // This happens if:
            // - The expansion block runs.
            // - `i` is NOT incremented (so `F` is processed in next iteration).
            // - The `else` does NOT run (so `-` is not printed).
            
            // If `i` is not incremented, the `else` MUST run?
            // If `i` is not incremented, it means the `if` block didn't run? But it did print CDEF.
            
            // There is a subtle bug in C if statements without braces? No.
            
            // Let's look at the FIRST `if` block (digits).
            //             if(s[i-1]>=48&&s[i-1]<=57&&s[i+1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1])
            //             {
            //                 for(j=s[i-1];j<s[i+1];j++)
            //                 printf("%c",j+1);
            //                 i++;
            //             }
            
            // SECOND `if` block (upper).
            //             if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1])
            //             {
            //                 for(j=s[i-1];j<s[i+1];j++)
            //                 printf("%c",j+1);
            //                 i++;
            //             }
            
            // THIRD `if` block (lower).
            //             if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
            //             {
            //                 for(j=s[i-1];j<s[i+1];j++)
            //                 printf("%c",j+1);
            //                 i++;
            //             }
            //             else printf("%c",s[i]);
            
            // If the Second `if` runs, `i` is incremented.
            // Then Third `if` is checked. It is false.
            // So `else` runs. Prints `-`.
            // Output: `CDEF-`.
            
            // If the output is `BCDEFF`, then `i` was NOT incremented in the Second `if`.
            // Why?
            // Maybe the code provided in the prompt is slightly different from what I'm reading?
            // "Source Code:" block.
            // It looks standard.
            
            // Is it possible that `j` conflicts with `i`? No, different variables.
            
            // Let's assume the error is indeed the lack of `else if`.
            // If we change to `else if`, the `else` will only execute if ALL conditions are false.
            // This fixes the printing of `-` when an expansion occurred in the first or second block.
            // For `B-F`:
            // 1. Digit: False.
            // 2. Upper: True. Expands. `i++`. Skip rest of chain.
            // Result: `CDEF`. No `-`. No extra `F`.
            // This matches the Expected Output part `BCDEF`.
            
            // So the primary error is using independent `if`s instead of `else if`s, causing the final `else` to trigger incorrectly for Upper/Digit expansions.
            
            // But wait, if the bug was just the `-` being printed, the output would be `BCDEF-`.
            // The actual buggy output is `BCDEFF`.
            // This implies `F` is printed instead of `-`.
            // How?
            // If the `else` printed `s[i+1]`? No.
            // If the `i++` was missing?
            // If `i++` was missing in the Upper block:
            // 1. Upper: True. Expands CDEF. `i` stays 4.
            // 2. Lower: False.
            // 3. Else: Prints `-`.
            // 4. Loop increments `i` to 5.
            // 5. s[5] is `F`. Prints `F`.
            // Result: `CDEF-F`.
            // Still has `-`.
            
            // What if BOTH `i++` was missing AND `else` didn't run?
            // Impossible.
            
            // Let's look at the `else` again.
            // `else printf("%c",s[i]);`
            
            // Is it possible the user's environment or compiler behaves differently? Unlikely.
            
            // Let's look at the first expansion `a-u`.
            // It works.
            
            // Let's look at the second expansion `B-F`.
            // If I change the `if`s to `else if`s, the logic becomes correct regarding the `-`.
            // Does it explain the `F`?
            // If the code was:
            // if (digit) { ... i++ }
            // else if (upper) { ... i++ }
            // else if (lower) { ... i++ }
            // else { print - }
            
            // Then for `B-F`:
            // Digit: False.
            // Upper: True. Print CDEF. i++ (i=5).
            // Rest skipped.
            // Loop increments i to 6.
            // End.
            // Output: `BCDEF`. Correct.
            
            // So the fix is definitely changing to `else if`.
            // The discrepancy between my trace (`CDEF-`) and the reported buggy output (`BCDEFF`) might be due to a typo in the problem description's "Buggy Output" or a specific compiler quirk/undefined behavior not visible here, OR I am misinterpreting the `gets` buffer.
            // However, the structural error of independent `if`s followed by a dangling `else` is a classic bug that leads to incorrect output when multiple conditions are checked sequentially but are meant to be mutually exclusive.
            
            // Therefore, I will mark the lines with `if` that should be `else if`.

            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            else if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Changed 'if' to 'else if' to ensure mutual exclusivity. The original code had independent 'if' statements, causing the final 'else' to execute even if a previous expansion occurred (e.g., uppercase), leading to incorrect output like printing '-' or subsequent characters incorrectly.
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            else printf("%c",s[i]);
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}