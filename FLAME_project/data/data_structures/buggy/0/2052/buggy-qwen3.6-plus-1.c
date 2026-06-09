#include <stdio.h>

void squeez(char s[],char c);

int main()
{
  int i=0,j=0;
  char s[512],s2[512];//两个字符串数组，一个放原来的，一个放补充的 
  gets(s);
  for(i=0;s[i]!='\0';i++){
    //把s[]传给s2[] 
    s2[j]=s[i];
    if(s[i+1]=='-'&&s[i]<s[i+2]&&((s[i]>='a'&&s[i]-1<'z'&&s[i+2]>'a'&&s[i+2]<='z')||(s[i]>='A'&&s[i]<'Z'&&s[i+2]>'A'&&s[i+2]<='Z') ||(s[i]>='0'&&s[i]<'9'&&s[i+2]>'0'&&s[i+2]<='9'))){ // @@ The boundary checks are incorrect. For example, s[i]-'1'<'z' allows 'z' as a start character but the loop condition temp<s[i+2] might not expand correctly if end is also 'z'. More importantly, the condition s[i]<'Z' excludes 'Y'->'Z' expansion because 'Y'<'Z' is true, but wait. The condition is s[i] < s[i+2]. If input is Y-Z, s[i]='Y', s[i+2]='Z'. 'Y'<'Z' is true. The type check: 'A'<='Y' && 'Y'<'Z' (True) && ... This logic seems okay for strict inequality. However, the problem requires same type. The current check `(s[i]>='a'&&s[i]-1<'z'...)` is weird. `s[i]-1 < 'z'` means `s[i] <= 'z'`. So it allows 'z'. But if start is 'z', and end is > 'z', it's not a lowercase letter. The range check should be `s[i] >= 'a' && s[i] <= 'z'` and `s[i+2] >= 'a' && s[i+2] <= 'z'`. The current code has logical errors in range validation. Specifically, `s[i]-1<'z'` is equivalent to `s[i]<='z'`. `s[i+2]>'a'` excludes 'a' as an endpoint? No, `s[i+2] > 'a'` means endpoint must be at least 'b'. But `a-a` or `a-b`? If `a-b`, `s[i]='a'`, `s[i+2]='b'`. `s[i+2]>'a'` is true. If `a-a`, `s[i]<s[i+2]` fails. So `a-b` works. What about `y-z`? `s[i]='y'`, `s[i+2]='z'`. `s[i]<'z'` is true. `s[i+2]<='z'` is true. `s[i+2]>'a'` is true. So `y-z` works. What about `z-...`? `s[i]='z'`. `s[i]<'z'` is false. So `z` cannot be a start. This is correct because there is no lowercase letter after `z`.
    // However, the main error causing the Wrong Answer on `a-c-g0-A` is likely how the loop index `i` is updated.
    // Let's trace `a-c-g`.
    // i=0, s[0]='a'. s[1]='-', s[2]='c'. 'a'<'c'. Type match.
    // Enter if. temp='a'.
    // while('a'<'c'): temp='b', j=1, s2[1]='b'.
    // while('b'<'c'): temp='c', j=2, s2[2]='c'.
    // while('c'<'c'): False.
    // i=i+2 => i=2.
    // j++ => j=3.
    // Loop increment i++ => i=3.
    // s[3] is '-'.
    // s2[3] = s[3] = '-'.
    // Check if s[4]=='-'? No, s[4]='g'.
    // j++ => j=4.
    // Loop increment i++ => i=4.
    // s[4]='g'.
    // s2[4]=s[4]='g'.
    // Check if s[5]=='-'? No.
    // ...
    // The issue is that when we expand `a-c`, we consume `a`, `-`, `c`.
    // The code sets `s2[j] = s[i]` (which is 'a') at the beginning of the loop.
    // Then it appends 'b', 'c' to s2.
    // Then it skips `i` by 2 (`i=i+2`), so `i` becomes 2 (pointing to 'c').
    // Then `j` is incremented.
    // Then the `for` loop increments `i` to 3.
    // So at `i=3`, we process `-`. This is correct so far.
    // But wait, the expansion of `a-c` should result in `abc`.
    // s2[0]='a'.
    // Inside while: s2[1]='b', s2[2]='c'.
    // j becomes 2 inside while, then j++ makes it 3.
    // So next char goes to s2[3].
    // i becomes 2, then i++ makes it 3.
    // s[3] is '-'.
    // s2[3] = '-'.
    // This results in `abc-...`.
    // Now consider `c-g`.
    // The input is `a-c-g`.
    // When i=2 (char 'c'), it was skipped by the previous expansion logic?
    // No, i became 3. So 'c' at index 2 is NOT processed as a start of a new expansion.
    // But 'c' is already part of the expansion of `a-c`.
    // The next potential expansion is `c-g`? No, the string is `a-c-g`.
    // The `-` at index 3 is between `c` (index 2) and `g` (index 4).
    // When i=3, s[3]='-'. s2[3]='-'.
    // Condition: s[4]=='-'? No.
    // So it just copies '-'.
    // Then i=4. s[4]='g'. s2[4]='g'.
    // Result: `abc-g`.
    // Expected: `abcdefg`.
    // The problem is that the expansion of `a-c` produces `abc`. The `c` is included.
    // The next part is `-g`.
    // The code treats the `-` at index 3 as a literal character because the check `s[i+1]=='-'` at `i=3` looks at `s[4]` which is `g`.
    // Wait, the check is `if(s[i+1]=='-' ...)`.
    // At `i=2` (char 'c'), `s[3]` is `-`. `s[4]` is `g`.
    // Did we process `i=2`?
    // In the first iteration: i=0. Expanded. i becomes 2. Loop increments i to 3.
    // So `i=2` ('c') is SKIPPED by the for loop increment.
    // This means the potential expansion starting with 'c' (i.e., `c-g`) is NEVER checked.
    // The code only checks for expansion starting at the current character `s[i]`.
    // Because `i` jumps over the end character of the previous expansion (`c`), it fails to detect that `c` is the start of the next range `c-g`.
    
    // To fix this, when an expansion occurs, the index `i` should be positioned such that the next iteration checks the character AFTER the expanded range.
    // The expanded range is `s[i]` to `s[i+2]`.
    // We copied `s[i]`. We generated up to `s[i+2]`.
    // The next character to process in `s` is `s[i+3]`.
    // Currently `i` is set to `i+2`, then `for` loop makes it `i+3`.
    // So `i` points to `s[i+3]`.
    // But we need to check if `s[i+2]` (which is 'c') starts a new expansion with `s[i+3]` ('-') and `s[i+4]` ('g').
    // By skipping `s[i+2]`, we miss this.
    // Therefore, `i` should be decremented by 1 after the expansion block, or adjusted so that the next loop iteration processes `s[i+2]`.
    // If we set `i = i + 1` instead of `i = i + 2`, then `for` loop makes it `i + 2`.
    // Let's trace: i=0. Expand. i becomes 1. Loop makes i=2.
    // At i=2 ('c'): s2[2] is already 'c' from previous expansion?
    // No, s2 is built sequentially.
    // If we restart processing at 'c', we will copy 'c' again to s2?
    // s2[j] = s[i].
    // In the previous step, j ended at 3. s2[0]='a', s2[1]='b', s2[2]='c'.
    // If we process i=2 ('c') again:
    // s2[3] = 'c'. Duplicate!
    
    // The logic needs to be: if expansion happens, do NOT copy the start character again (it's already copied before the if? No, it's copied at the start of the loop).
    // Actually, the structure is:
    // 1. Copy s[i] to s2[j].
    // 2. Check if expansion possible.
    // 3. If yes, generate rest of expansion. Skip i.
    
    // If we skip i, we don't re-copy.
    // But we missed checking if the END of the current expansion is the START of the next.
    
    // Correct approach:
    // When `a-c` is expanded, `s2` has `abc`. `j` is at 3.
    // The next char in `s` to consider is `c` (index 2)? No, `c` is already in `s2`.
    // But `c` is followed by `-g`.
    // We need to check if `c` starts an expansion.
    // Since `c` is already in `s2`, we shouldn't add it again.
    // But we need to consume `-g` and expand to `defg`.
    // So, if we detect that `s[i]` (current) starts an expansion, we handle it.
    // The problem is overlapping ranges: `a-c` and `c-g`.
    // The prompt says `a-c-g`.
    // Usually, expansion is non-overlapping in simple parsers, but here `c` is shared.
    // `a-c` -> `abc`.
    // `c-g` -> `cdefg`.
    // Combined: `abcdefg`.
    
    // If we process `a-c`, we output `abc`.
    // We are now at `i` corresponding to `c`.
    // If we check `c` for expansion, we see `c-g`.
    // We should output `defg` (since `c` is already output).
    
    // The current code fails because it skips `c`.
    
    // Fix: Adjust `i` so that the next iteration processes the character at `i+2` (the end of the current expansion).
    // But we must prevent re-copying that character.
    
    // Alternatively, change the logic to look ahead without consuming, or handle the overlap.
    
    // Simplest fix for this specific bug:
    // Change `i=i+2` to `i=i+1`.
    // Trace:
    // i=0 ('a'). Copy 'a' to s2[0].
    // Expand `a-c`. s2[1]='b', s2[2]='c'. j=3.
    // Set `i = 0 + 1 = 1`.
    // Loop increments `i` to 2.
    // i=2 ('c').
    // Copy 'c' to s2[3]. DUPLICATE.
    
    // So we need to avoid copying if it was part of previous expansion.
    
    // This requires a flag or restructuring.
    
    // Given the constraint "do not change original code structure", adding a flag might be acceptable if minimal.
    // Or, we can modify the index jump and manually adjust j?
    
    // Let's look at the condition again.
    // The error is definitely the skipping of the intermediate character which acts as a bridge.
    
    // If I change `i=i+2` to `i=i+1`, and accept the duplicate? No, output is wrong.
    
    // How about `i` stays at `i+1` (the '-'), and we let the loop process it?
    // If i=1 ('-'). Copy '-' to s2. No expansion.
    // This doesn't help.
    
    // The robust fix is:
    // When expanding, we have consumed `s[i]`, `s[i+1]`, `s[i+2]`.
    // We produced `s[i]...s[i+2]`.
    // The next character to process is `s[i+3]`.
    // BUT, `s[i+2]` might be the start of another expansion.
    // Since `s[i+2]` is already in `s2`, we should check if `s[i+2]` starts an expansion, and if so, append the NEW characters.
    
    // This is complex to patch inline.
    
    // However, looking at the test case `a-c-g`, standard expansion usually implies `a-c` becomes `abc`, and `c-g` becomes `cdefg`.
    // If the intention is `abcdefg`, then the `c` is shared.
    
    // Let's try changing `i=i+2` to `i=i+2-1`? i.e., `i=i+1`.
    // And prevent the copy?
    
    // Actually, there is a simpler interpretation. Maybe the input `a-c-g` is treated as two separate expansions `a-c` and `c-g`.
    
    // If I simply remove the `i=i+2` line?
    // i=0. Expand. i becomes 0. Loop -> i=1.
    // i=1 ('-'). Copy '-'.
    // This breaks it.
    
    // The correct logic for overlapping expansions:
    // 1. Copy s[i].
    // 2. If expansion exists:
    //    - Generate chars from s[i]+1 to s[i+2].
    //    - Advance i by 2 (so loop makes it i+3).
    //    - BUT, before advancing, check if s[i+2] starts a new expansion?
    
    // Due to the complexity and strict constraints, the most likely intended "bug" is just the skipping.
    // If I change `i=i+2` to `i=i+1`, I get duplicates.
    
    // Is it possible the condition `s[i]<s[i+2]` is too strict? No.
    
    // Let's look at the provided Reference Program. It uses a different approach (finding links first).
    
    // For the Buggy Code, the error is logically skipping the bridge character.
    // I will mark the line `i=i+2;` as the error.
    // Reason: It skips the character that may be the start of the next expansion sequence, causing chained expansions like a-c-g to fail.
    
    // To make it pass `a-c-g` -> `abcdefg`:
    // We need to process 'c' again.
    // If we change `i=i+2` to `i=i+1`, we process 'c' again.
    // To avoid duplicate 'c', we can decrement `j` before the next copy? No, `j` is incremented at the end of the loop.
    
    // If I change `i=i+2` to `i=i+1`, and also `j--`?
    // Trace:
    // i=0. s2[0]='a'. Expand. s2[1]='b', s2[2]='c'. j=2 (inside while) -> j=3 (after while? No, j++ is after if).
    // Wait, `j++` is outside the `if`.
    // Inside `if`:
    // `while` loop increments `j`.
    // After `while`, `j` is at index of last written char.
    // Then `i=i+2`.
    // Then `j++` executes.
    
    // If I add `j--` before `i=i+2`?
    // No, `j` is correct for the next write.
    
    // If I change `i=i+2` to `i=i+1`:
    // Next iter i=2 ('c').
    // s2[3] = 'c'. (Duplicate).
    // Then check expansion `c-g`.
    // Expand. s2[4]='d'...
    
    // So `abccdefg`. Wrong.
    
    // There is no simple one-line fix that preserves structure perfectly without adding variables.
    // However, often in these problems, `a-c-g` might be interpreted as `a-c` and `g` is separate? No, expected is `abcdefg`.
    
    // I will annotate the line `i=i+2;` as the primary error source.
    }
    j++; 
    
  } 
  s2[j]='\0';
  puts(s2);
  
    return 0;
}