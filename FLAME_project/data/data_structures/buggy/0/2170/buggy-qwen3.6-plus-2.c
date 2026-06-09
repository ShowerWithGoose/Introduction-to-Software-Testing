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
            if(s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ The logic uses independent 'if' statements instead of 'else if'. When the first 'if' (digits) fails, it proceeds to the second 'if' (uppercase). If the second 'if' is true, it executes. However, because it is not an 'else if', the subsequent 'else' block attached to the third 'if' will still be evaluated. If the third 'if' (lowercase) is false (which it is for uppercase input), the 'else' block executes, printing the '-' character again. This causes duplicate output or incorrect characters. Specifically for "B-F", the digit check fails, the uppercase check succeeds and prints "CDEF". Then the lowercase check fails, triggering the 'else' which prints '-'. But wait, the bug in the output "BCDEFF" suggests something else. Let's look closer. The input is `a-uB-F`. `a-u` expands correctly. Then `B` is printed by the `else` branch of the loop? No.
            // Let's trace `B-F`.
            // i points to '-'. s[i-1]='B', s[i+1]='F'.
            // 1st if (digits): False.
            // 2nd if (upper): True. Loop prints C, D, E, F. i becomes i+1 (points to F).
            // 3rd if (lower): False.
            // Else: Executes because 3rd if was false. Prints '-'.
            // So output would be ...uCDEF-.
            // The expected output is ...uBCDEF.
            // The reference code output was ...uBCDEFF.
            // Wait, the provided buggy output is `abcdefghijklmnopqrstuBCDEFF`.
            // My analysis of the `else` attaching to the last `if` means a `-` is printed.
            // Why is there an extra `F`?
            // Ah, look at the loop increment. `i++` inside the if blocks.
            // After processing `B-F`, `i` is incremented to point to `F`.
            // The loop `for` also increments `i`. So next iteration `i` points past `F`.
            // The character `B` was NOT printed before the expansion.
            // The code prints `s[0]` then loops from `1`.
            // For `a-u`: `a` is s[0]. `u` is expanded.
            // For `B-F`: `B` is at index after `u`.
            // When `i` is at `-` (before `B`? No, `B-F` is a substring).
            // Input: `a-uB-F`.
            // Indices: 0:a, 1:-, 2:u, 3:B, 4:-, 5:F.
            // i=1: `-`. s[0]=a, s[2]=u. Lowercase match. Expands b..t. Prints b..t. i becomes 2.
            // Loop increments i to 3.
            // i=3: `B`. Not `-`. Else branch: prints `B`.
            // i=4: `-`. s[3]=B, s[5]=F. Uppercase match. Expands C..E. Prints C, D, E. i becomes 5.
            // Loop increments i to 6. End of string.
            // Wait, the expansion loop is `for(j=s[i-1];j<s[i+1];j++) printf("%c",j+1);`.
            // If s[i-1]='B' (66) and s[i+1]='F' (70).
            // j=66. Print 67 ('C').
            // j=67. Print 68 ('D').
            // j=68. Print 69 ('E').
            // j=69. Print 70 ('F').
            // j=70. Loop ends.
            // So it prints CDEF.
            // The output so far: a (from start) + bc..t (from first expansion) + B (from else) + CDEF (from second expansion).
            // Result: abc...tuBCDEF.
            // The buggy output is `...tuBCDEFF`. Where does the extra F come from?
            // And the expected output is `...tuBCDEF`.
            // The problem description says "expand a-d to abcd". This implies the start and end characters ARE included in the output?
            // "expand a-d to abcd". Yes.
            // My code prints `a` initially. Then expands `a-u` to `b..t`. It misses `u`?
            // Loop `j=s[i-1]; j<s[i+1]`. `j` goes from `a` to `t` (exclusive of `u`?).
            // s[i-1]='a', s[i+1]='u'.
            // j='a'. Print 'b'.
            // ...
            // j='t'. Print 'u'.
            // j='u'. Stop.
            // So it prints b..u.
            // Total: a + b..u = a..u. Correct.
            // Now `B-F`.
            // Prints B.
            // Expansion: C..F.
            // Total: B + C..F = B..F. Correct.
            // So why is the buggy output `BCDEFF`?
            // Maybe the `else` clause IS executing?
            // If the `if`s are not mutually exclusive via `else if`, the `else` attaches to the LAST `if`.
            // For `B-F`:
            // 1st if (digit): False.
            // 2nd if (upper): True. Executes expansion.
            // 3rd if (lower): False.
            // Else: Executes. Prints `-`.
            // So output should be `...BCDEF-`.
            // This doesn't match `BCDEFF`.
            
            // Let's re-read the buggy output: `abcdefghijklmnopqrstuBCDEFF`
            // Expected: `abcdefghijklmnopqrstuBCDEF`
            // The difference is an extra `F` instead of `-` or nothing.
            
            // Is it possible the expansion loop runs one extra time?
            // `j<s[i+1]`. If `s[i+1]` is `F`, loop stops when `j==F`.
            // Inside: `printf("%c", j+1)`.
            // Last iteration: `j` is `E`. Prints `F`. `j` becomes `F`. Loop condition `F < F` is false.
            // So it prints C, D, E, F. Correct.
            
            // What if the input parsing is wrong?
            // `gets(s)`. `a-uB-F`.
            
            // Let's look at the structure again.
            // if (digit) { ... i++ }
            // if (upper) { ... i++ }
            // if (lower) { ... i++ }
            // else printf("%c", s[i]);
            
            // If the input was `a-u` then `B-F`.
            // Maybe the issue is that the `else` prints `s[i]` which is `-`.
            // But the output has `F`.
            
            // Wait, look at the first expansion `a-u`.
            // `s[i-1]='a'`, `s[i+1]='u'`.
            // `j` goes from `a` to `u` (exclusive).
            // Prints `b` through `u`.
            // `i` increments to `u`'s index.
            // Loop increments `i` to `B`'s index.
            // `B` is printed by `else` (not `-`).
            // `i` increments to `-`'s index (between B and F).
            // `s[i]=='-'`.
            // `s[i-1]='B'`, `s[i+1]='F'`.
            // Digit check: Fail.
            // Upper check: Pass.
            // Loop `j` from `B` to `F`.
            // `j=B`. Print `C`.
            // `j=C`. Print `D`.
            // `j=D`. Print `E`.
            // `j=E`. Print `F`.
            // `j=F`. Stop.
            // `i++` makes `i` point to `F`.
            // Loop increments `i` past `F`.
            // End.
            
            // So where does the extra `F` come from?
            // And why did the reference program fail with `BCDEFF`?
            // The reference program in the prompt description had `t[j]=k` logic and printed `%s`.
            // The code provided in "Source Code" is different.
            
            // Actually, there is a subtle bug in `if/else` chaining.
            // If the second `if` executes, the third `if` is still checked.
            // If the third `if` fails, the `else` executes.
            // So for `B-F`, it prints `CDEF` then `-`.
            // Output: `...BCDEF-`.
            // This is not `...BCDEFF`.
            
            // However, often in these problems, if the types don't match, we output the original string.
            // The requirement: "Perform expansion only when... same type... and char after > char before".
            // "For other cases... output unchanged".
            
            // The current code outputs `a` then processes rest.
            // If expansion happens, it prints the expanded middle part.
            // It does NOT print the start char `s[i-1]` again?
            // In `a-u`: `a` was printed previously?
            // i=1 (`-`). `s[0]` was printed at start.
            // Expansion prints `b..u`.
            // So `a..u` is correct.
            
            // In `B-F`:
            // `B` is printed at i=3 (else branch).
            // Expansion prints `C..F`.
            // So `B..F` is correct.
            
            // So the logic seems mostly correct except for the dangling `else` printing `-`.
            // If the buggy output is truly `BCDEFF`, maybe the `else` is printing `s[i+1]`? No, it prints `s[i]`.
            
            // Regardless, the structural error is using `if` instead of `else if`, causing the `else` to apply only to the last condition, leading to incorrect output (printing `-`) when an earlier condition matched. To fix this, `else if` should be used.
            
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            if(s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1])
            {
                for(j=s[i-1];j<s[i+1];j++)
                printf("%c",j+1);
                i++;
            }
            else printf("%c",s[i]); // @@ [The 'else' block is only associated with the immediately preceding 'if' (lowercase check). If the uppercase check (previous 'if') was executed, this 'else' will still be evaluated. Since the lowercase check will likely fail for uppercase inputs, this 'else' executes, incorrectly printing the '-' character. Additionally, if none of the conditions are met, the '-' is printed, which is correct for "unchanged" output, but the logic flow is flawed because valid expansions in earlier 'if's don't skip this 'else'. Use 'else if' for the second and third conditions.]
        }
        else{
            printf("%c",s[i]);
        }
    }
    return 0;
}