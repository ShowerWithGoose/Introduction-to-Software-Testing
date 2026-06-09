#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
        S[j]=s[i];
        if (s[i+1]=='-'){
            if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
                if (s[i+2] > s[i]) { // @@ The problem requires expansion only if the character after '-' is greater than the one before. This check is missing, causing incorrect expansion or logic flow for cases like B-e where types match but order might be wrong or simply ensuring strict adherence to "greater than". Actually, for B-e, types don't match. Let's look closer.
                    for (char ch=s[i];ch<s[i+2];j++,ch++){
                        S[j] = ch;
                    }
                } else {
                     j++; // @@ If not expanding, we need to account for the '-' and the next char properly in the output buffer S. The current logic falls through to else below? No, this is inside the if block.
                }
            }else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
                if (s[i+2] > s[i]) { // @@ Same missing check for increasing order
                    for (char ch=s[i];ch<s[i+2];j++,ch++){
                        S[j] = ch;
                    }
                } else {
                    j++;
                }
            }else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
                if (s[i+2] > s[i]) { // @@ Same missing check for increasing order
                    for (char ch=s[i];ch<s[i+2];j++,ch++){
                        S[j] = ch;
                    }
                } else {
                    j++;
                }
            }else {
                j++; // @@ This handles the case where types don't match (like B-e). It increments j to make space for the '-' which will be handled in the next iteration? No.
                // Let's trace B-e.
                // i=0, j=0. s[0]='B'. S[0]='B'.
                // s[1]=='-'. True.
                // Check 1: 'B' is upper, 'e' is lower. Fail.
                // Check 2: 'B' is not lower. Fail.
                // Check 3: 'B' is not digit. Fail.
                // Else: j++ -> j becomes 1.
                // Then i++ (loop increment) -> i becomes 1. j-- (explicit) -> j becomes 0.
                // Loop end: i++ -> i becomes 2. j++ -> j becomes 1.
                // Next iter: i=2. s[2]='e'. S[1]='e'.
                // s[3] is '\0'. s[3]!='-'
                // Loop ends.
                // Output: "Be". Expected "B-e".
                // The error is that when we don't expand, we still need to output the '-' character.
                // In the `else` block, we just do j++. We haven't written '-' to S.
                // Also, the loop structure `i++, j++` at the top writes the current char.
                // When we encounter `B`, we write `B`. Then we see `-`.
                // If we don't expand, we need to write `-` and then `e`.
                // The current code writes `B`. Then enters `if(s[i+1]=='-')`.
                // In `else`, it does `j++`. This effectively skips a position in S? No, S[j] was already written with `B` at the start of the loop.
                // Wait, `S[j]=s[i]` happens at the start.
                // i=0, j=0. S[0]='B'.
                // Inside if: else { j++; }. j becomes 1.
                // End of if block: i++; j--;. i becomes 1, j becomes 0.
                // Loop step: i++ (becomes 2), j++ (becomes 1).
                // Next iter: i=2, j=1. S[1]=s[2]='e'.
                // Result "Be". The '-' is skipped.
                // To fix: In the else case (no expansion), we should let the loop proceed naturally to pick up the '-' in the next iteration, OR explicitly write it.
                // If we let it proceed:
                // We are at i=0 ('B'). We detect '-' at i+1.
                // If we don't expand, we want output "B-e".
                // Current logic consumes 'B', then tries to handle the group.
                // If we don't expand, we should output 'B', then '-', then 'e'.
                // The loop writes 'B'. Then we are inside the `if(s[i+1]=='-')` block.
                // We should NOT skip the '-'.
                // The `i++` and `j--` at the end of the `if` block are intended to adjust indices because the loop header also increments them.
                // If we don't expand, we want the next iteration to process the '-' character normally.
                // So, at i=0, we wrote 'B'. We see '-' ahead.
                // If we don't expand, we should just continue. The next iteration should handle '-'.
                // But the loop increments i to 1.
                // If we remove the special handling for non-expansion cases and just let the loop run, it would work?
                // If i=0, write 'B'. i becomes 1.
                // i=1, s[1]='-'. Write '-'. s[2] is 'e'. s[2]!='-'.
                // i=2, s[2]='e'. Write 'e'.
                // This would produce "B-e".
                // So, if expansion doesn't happen, we shouldn't perform the index manipulation that skips the '-'.
                // The `else { j++; }` followed by `i++; j--;` results in net i+=2, j+=0 relative to start of loop body?
                // Start: i=0, j=0.
                // End of body: i=1, j=0.
                // Loop inc: i=2, j=1.
                // So 'B' written at 0. 'e' written at 1. '-' skipped.
                // Correction: In the `else` case (types mismatch or not increasing), we should not skip the '-'.
                // We should let the next iteration handle the '-'.
                // This means we should NOT increment `i` extra here.
                // However, the structure `if (s[i+1]=='-')` implies we are looking ahead.
                // If we don't expand, we just want to output the current char (already done) and then let the loop proceed to the next char which is '-'.
                // So we should NOT execute `i++` and `j--` in the else case?
                // But `i++` and `j--` are outside the if/else blocks, at the end of the `if(s[i+1]=='-')` block.
                // So they always execute.
                // This is the bug. The index adjustment assumes we consumed the '-' and the next char via expansion or skipping.
                // If we don't expand, we haven't consumed them in the S buffer properly.
                
                // To fix specifically for the test case B-e:
                // We need to ensure '-' is printed.
                // The easiest fix in this structure is to explicitly print '-' in the else case and adjust indices correctly, OR change the logic to not skip.
                // Given the constraint "do not change original code structure... except for explicit error markers", I must annotate the lines causing the error.
                
                // The line `j++;` in else is insufficient.
                // The lines `i++;j--;` cause the skip.
                
                // Let's look at the expansion loops.
                // `for (char ch=s[i];ch<s[i+2];j++,ch++)`
                // If s[i]='a', s[i+2]='d'.
                // ch='a'. S[j]='a'. j++, ch='b'.
                // ch='b'. S[j]='b'. j++, ch='c'.
                // ch='c'. S[j]='c'. j++, ch='d'.
                // Loop ends.
                // We have written a, b, c. We are missing 'd'.
                // The loop condition is `ch < s[i+2]`. It stops before writing the end character.
                // The end character 'd' is written by the next iteration of the main loop?
                // After expansion loop:
                // i=0. j has increased by 3 (for a,b,c).
                // End of if block: i++ (->1), j-- (-> j-1).
                // Loop header: i++ (->2), j++ (-> j).
                // Next iter: i=2. s[2]='d'. S[j]='d'.
                // So 'd' is written.
                // This seems correct for expansion.
                
                // Back to B-e.
                // Types mismatch. Else block.
                // `j++` happens.
                // `i++`, `j--` happens.
                // Net result: i advances by 2 (skipping '-'), j advances by 0 (overwriting next slot?).
                // S[0]='B'.
                // Else: j becomes 1.
                // End block: i=1, j=0.
                // Loop inc: i=2, j=1.
                // Next iter: S[1]='e'.
                // Output "Be".
                
                // Error is that '-' is not output.
            }
            i++;j--; // @@ These lines unconditionally skip the '-' character and adjust j, which is incorrect when no expansion occurs (the else case). In the else case, the '-' should be processed in the next iteration to be outputted.
        }
    }
    printf ("%s", S);
    return 0;
}