#include <stdio.h>
#include <string.h>

int main()  {           
    char s[100000]={"0"};
    gets(s);
    
    for(int i=0; i<strlen(s); i++){
        if(s[i+1]=='-'&& s[i]<s[i+2]){
            
            if(s[i]>='A' && s[i+2]<='Z'){ // @@ The condition checks if start is uppercase and end is within 'Z', but fails to verify they are BOTH uppercase (e.g., 'a' < 'Z' is true, but types differ). It should also ensure s[i] <= 'Z'. More importantly, the logic structure below uses independent 'if's instead of 'else if', causing multiple blocks to potentially execute or fall through incorrectly.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){ // @@ Modifying s[i] directly changes the original string, which might affect subsequent checks if not handled carefully, but the main issue here is that this loop modifies the loop variable 'i' in the outer loop context unexpectedly if not reset, though here 'i' is not modified by the for-loop update expression. However, the critical error is that after this block, it falls through to the next 'if' because there is no 'else'.
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='0' && s[i+2]<='9'){ // @@ This is an independent 'if'. If the previous block executed, this one is checked again. Also, the condition is insufficient: it doesn't check if s[i] is actually a digit (>= '0'). It only checks if s[i+2] <= '9'. If s[i] was 'A' (from previous block logic failure or just bad input), this might behave unexpectedly. But specifically for the bug: if the first 'if' (uppercase) was true, it executed. Then this 'if' is checked. If it's false, it goes to the next 'if'. If that's false, it goes to 'else'. The 'else' belongs only to the last 'if'.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            if(s[i]>='a' && s[i+2]<='z'){ // @@ Same issue: independent 'if'. The 'else' below only applies to this specific 'if'. If the input is 'B-F', the first 'if' ('A'-'Z' check) is true. It prints BCDEF. Then it checks this 'if'. 'B' >= 'a' is false. So it goes to the 'else'.
                for(i;s[i]<s[i+2];s[i]=s[i]+1){
                    printf("%c",s[i]);}i=i+1;
            }
            else{ // @@ This 'else' is paired only with the immediately preceding 'if' (lowercase check). If the input was 'B-F', the first 'if' (uppercase) executed correctly. The second 'if' (digits) was false. The third 'if' (lowercase) was false. So this 'else' executes, printing s[i] ('B') again? No, wait. In the trace for 'B-F': s[i]='B'. First if: 'B'>='A' (T) and 'F'<='Z' (T). Enters. Prints B,C,D,E,F. Increments i by 1 (so i points to '-'). Loop ends. Next statement: Second if. s[i] is now '-' (because i was incremented? No, the inner for loop didn't change i, but `i=i+1` did). Wait, the code says `i=i+1` after the for loop. So if i was index of 'B', it becomes index of '-'. Then `s[i]` is '-'. Second if: '-' >= '0' is False. Third if: '-' >= 'a' is False. Else executes: printf("%c", s[i]) which prints '-'. This explains the extra '-' in output if the logic was slightly different. 
            // Let's re-evaluate 'a-uB-F'.
            // 1. i=0 ('a'). s[1]='-'. s[0]<'u'.
            // First if: 'a'>='A' (T). 'u'<='Z' (F). Skips.
            // Second if: 'a'>='0' (T). 'u'<='9' (F). Skips.
            // Third if: 'a'>='a' (T). 'u'<='z' (T). Enters.
            // Prints a..u. i becomes 1 (index of '-').
            // Loop increments i to 2 ('u').
            // 2. i=2 ('u'). s[3]='B'. s[3]!='-'. Else branch: prints 'u'.
            // Loop increments i to 3 ('B').
            // 3. i=3 ('B'). s[4]='-'. s[3]<'F'.
            // First if: 'B'>='A' (T). 'F'<='Z' (T). Enters.
            // Prints B,C,D,E,F. i becomes 4 (index of '-').
            // Loop increments i to 5 ('F').
            // 4. i=5 ('F'). End of string? No, strlen is 6. s[6] is null.
            // s[6] is '\0'. s[5+1] is '\0'. s[5+2] is out of bounds?
            // Wait, the input is "a-uB-F". Length 6. Indices 0-5.
            // When i=3 ('B'), s[4]='-', s[5]='F'.
            // After processing, i becomes 4. Outer loop increments i to 5.
            // i=5 ('F'). s[6] is '\0'. s[6]!='-'. Else branch: prints 'F'.
            // Output so far: abcdefghijklmnopqrstuBCDEF.
            // Why did the buggy output have a hyphen? "abcdefghijklmnopqrstuBCDE-F"
            // Ah, look at the first block again.
            // Input: a-u.
            // i=0. 'a'-'u'.
            // 1st if (A-Z): 'a'>='A' T, 'u'<='Z' F. Skip.
            // 2nd if (0-9): 'a'>='0' T, 'u'<='9' F. Skip.
            // 3rd if (a-z): 'a'>='a' T, 'u'<='z' T. Enter.
            // Prints a...u. i becomes 1.
            // Outer loop increments i to 2.
            // i=2 is 'u'. s[3] is 'B'. s[3] is not '-'.
            // Else: printf("%c", s[2]) -> prints 'u'.
            // So we have ...tu. Correct.
            
            // Now B-F.
            // i=3 is 'B'. s[4] is '-'. s[5] is 'F'.
            // 1st if (A-Z): 'B'>='A' T, 'F'<='Z' T. Enter.
            // Loop: prints B, C, D, E, F.
            // Inside loop: s[i] changes? No, `s[i]=s[i]+1` changes the character in the array!
            // s[3] becomes 'C', then 'D', then 'E', then 'F', then 'G'.
            // After loop, s[3] is 'G'.
            // Then `i=i+1` makes i=4.
            // Outer loop increments i to 5.
            // i=5 is 'F'.
            // s[6] is '\0'. Not '-'.
            // Else: prints 'F'.
            // Result: ...BCDEFF? No.
            
            // Let's re-read the buggy output: `abcdefghijklmnopqrstuBCDE-F`
            // It missed the last 'F' in the expansion? Or printed a hyphen?
            // If the first `if` executes, it prints B,C,D,E,F.
            // Why is there a hyphen in the output?
            // Maybe the `else` attached to the last `if` executed?
            // If the first `if` executes, the second `if` is checked.
            // s[i] is now 'G' (modified in place). s[i+2] is out of bounds or garbage?
            // Actually, if s[i] is modified, subsequent checks use modified values.
            
            // The primary logical error is using independent `if` statements instead of `else if`.
            // And modifying `s[i]` in place corrupts the string.
            // And the conditions like `s[i]>='A' && s[i+2]<='Z'` don't ensure `s[i]` is uppercase (could be lowercase 'a' which is >= 'A').
            
            printf("%c", s[i]);    } // @@ This else only applies to the lowercase check. If an earlier check (like uppercase) matched, this else is still skipped? No, if uppercase matched, lowercase check is performed next. If lowercase fails, this else runs. This causes duplicate or incorrect output. For 'B-F', uppercase matches. Then lowercase check runs ('B'>='a' is false). So this else runs, printing s[i] (which is 'B' or modified value). This leads to wrong output.
        }
        else{
            printf("%c", s[i]);
        }
    }
    return 0;}