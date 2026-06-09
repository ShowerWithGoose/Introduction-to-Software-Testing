#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
        S[j]=s[i];
        if (s[i+1]=='-'){
            if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
                if (s[i+2] > s[i]) { // @@ The expansion should only happen if the end character is greater than the start character. Without this check, invalid ranges or reverse ranges might be processed incorrectly or the loop condition behaves unexpectedly for non-expansion cases where we just want to output the dash. However, the main issue here is that if it's not a valid expansion (e.g., B-e), we should output the '-' and the next char as is. The current logic enters the if/else-if blocks based on type match. For 'B' and 'e', types don't match, so it goes to else.
                    for (char ch=s[i];ch<s[i+2];j++,ch++){
                        S[j] = ch;
                    }
                } else {
                     // If types match but end <= start, no expansion. The '-' was already copied. We need to copy the next char too.
                     // But wait, the structure copies s[i] first. Then checks s[i+1]=='-'.
                     // If we don't expand, we have copied 'B'. We need to copy '-' and 'e'.
                     // The current code falls through to the else block below if types don't match.
                }
            }else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
                if (s[i+2] > s[i]) { // @@ Same logic: check if end > start before expanding
                    for (char ch=s[i];ch<s[i+2];j++,ch++){
                        S[j] = ch;
                    }
                }
            }else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
                if (s[i+2] > s[i]) { // @@ Same logic: check if end > start before expanding
                    for (char ch=s[i];ch<s[i+2];j++,ch++){
                        S[j] = ch;
                    }
                }
            }else {
                j++; // @@ This handles the case where types don't match (like B-e). s[i] ('B') is already in S[j]. We increment j to prepare for the next character. However, the loop increment i++ and j++ will happen at the end of the for loop. 
                // Let's trace B-e.
                // i=0, j=0. s[0]='B'. S[0]='B'.
                // s[1]=='-'. True.
                // Types: 'B' is Upper, 'e' is Lower. Mismatch. Goes to else.
                // j becomes 1.
                // Then i++ (i becomes 1), j-- (j becomes 0). 
                // Wait, the code has `i++; j--;` after the if-else block.
                // So after else: j=1. Then j-- makes j=0. i becomes 1.
                // Loop end: i++ -> i=2, j++ -> j=1.
                // Next iter: i=2. s[2]='e'. S[1]='e'.
                // s[3] is '\0'. s[3]!='-'.
                // Loop ends.
                // Output: "Be".
                // Expected: "B-e".
                // The problem is that when we don't expand, we still need to output the '-' character.
                // Currently, S[0]='B'. The '-' at s[1] is skipped in terms of being copied to S explicitly in the non-expansion path, although the logic tries to manage indices.
                // In the `else` branch (mismatched types), we have copied s[i] ('B'). We need to copy '-' and then the next char 'e' will be copied in the next iteration?
                // If we don't expand, we should just let the loop proceed normally?
                // If we remove the special handling for '-', it would copy 'B', then '-', then 'e'.
                // The current code attempts to handle expansion by looking ahead. If it doesn't expand, it should effectively treat the '-' as a normal character.
                // By entering the `if (s[i+1]=='-')` block, we consume the context.
                // In the `else` case (no expansion due to type mismatch or order), we have written s[i]. We need to write s[i+1] ('-') as well.
                // The code does `j++` in else. So S[1] is uninitialized/garbage or 0? No, S is initialized to 0.
                // Then `i++` makes i=1. `j--` makes j=0.
                // Loop increment: i=2, j=1.
                // Next iteration: s[2]='e'. S[1]='e'.
                // So S contains "Be". The '-' is missing.
                // To fix: In the else case, we should also copy the '-' character.
            }
            i++;j--;
        }
    }
    printf ("%s", S);
    return 0;
}