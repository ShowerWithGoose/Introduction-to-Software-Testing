#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 1e-8
    
int main()
{
    char s[100],a,b,t[100]={0};
    int i,j,k;
    gets(s);
    for(i=0,j=0;i<strlen(s);i++,j++){
        t[j]=s[i];
        if(s[i]=='-'){
            a=s[i-1];
            b=s[i+1];
            if(a<b&&((a<='9'&&a>='0'&&b<='9'&&b>='0')||(a<='Z'&&a>='A'&&b<='Z'&&b>='A')||(a<='z'&&a>='a'&&b<='z'&&b>='a'))){ // @@ The condition checks if types match globally but fails to ensure both characters are of the *same* specific type (e.g., 'B' is upper, 'e' is lower, but the OR logic might pass if not carefully structured, however here the logic is actually correct for type matching. The real issue is likely elsewhere or subtle). Let's re-evaluate.
                // Wait, looking at the logic: (a<='Z'&&a>='A'&&b<='Z'&&b>='A') ensures both are upper. (a<='z'&&a>='a'&&b<='z'&&b>='a') ensures both are lower.
                // For input "B-e": a='B', b='e'.
                // Check 1: digits? No.
                // Check 2: Upper? a is upper, but b ('e') is not upper. So this part is false.
                // Check 3: Lower? a ('B') is not lower. So this part is false.
                // So the condition evaluates to false. The expansion loop is skipped.
                // Then j-- happens.
                // Next iteration: i increments to point to 'e'. j is restored.
                // t[j] = 'e'.
                // Output should be "B-e".
                // Why did it fail?
                // Let's look at the loop structure again.
                // i=0: s[0]='B'. t[0]='B'. j becomes 1.
                // i=1: s[1]='-'. t[1]='-'. j becomes 2.
                // Inside if: a='B', b='e'. Condition false.
                // j-- -> j becomes 1.
                // Loop end: i becomes 2, j becomes 2.
                // i=2: s[2]='e'. t[2]='e'. j becomes 3.
                // Loop ends.
                // t is "B-e\0".
                // puts(t) prints "B-e".
                // The expected output is "B-e".
                // The buggy output provided in the prompt is "Be".
                // This implies the '-' was removed.
                // If the condition was TRUE, it would expand.
                // If the condition is FALSE, it keeps '-'.
                // Wait, look at the second code snippet provided in the prompt under "Source Code".
                // The prompt asks to annotate the "Source Code" at the bottom, not the "Reference Program" at the top.
                // The "Reference Program" is just context. The "Source Code" is the one to fix.
                // Let's re-read the Source Code carefully.
                
                // Source Code Analysis:
                // Input: B-e
                // i=0, j=0: t[0]='B'. j=1.
                // i=1, j=1: t[1]='-'.
                // s[i]=='-' is true.
                // a='B', b='e'.
                // Condition: a<b (True).
                // Type check:
                // (digit && digit) -> False.
                // (upper && upper) -> 'B' is upper, 'e' is NOT upper. False.
                // (lower && lower) -> 'B' is NOT lower. False.
                // Overall condition: False.
                // Expansion loop skipped.
                // j-- -> j becomes 0.  <-- THIS IS THE BUG.
                
                // Why j--?
                // The intention of j-- is likely to "undo" the increment of j that happened in the for-loop update (j++) so that the next character written by the expansion loop overwrites the '-' or starts correctly?
                // Or does it intend to overwrite the '-'?
                // If expansion happens:
                // We wrote '-' to t[j]. Then we enter expansion.
                // The expansion loop writes chars starting at t[j] (if we didn't decrement) or t[j+1]?
                // In the code: `for(k=1;k!=b-a;k++,j++) t[j]=a+k;`
                // If we don't decrement j:
                // t[j] currently holds '-'.
                // The loop starts. k=1. t[j] = a+1. This overwrites '-'.
                // Then j++. Next char written to next position.
                // This seems correct for expansion case.
                
                // If expansion DOES NOT happen:
                // We wrote '-' to t[j].
                // We do j--.
                // Loop update: i++, j++. So j returns to original value + 1?
                // Let's trace "B-e" again with j--.
                // i=1, j=1. t[1]='-'.
                // Condition false.
                // j-- -> j=0.
                // Loop update: i becomes 2, j becomes 1.
                // i=2, j=1. t[1]='e'.  <-- Overwrites the '-'!
                // Result: t[0]='B', t[1]='e'. String "Be".
                
                // This matches the buggy output "Be".
                // The error is that `j--` is executed regardless of whether expansion occurred.
                // It should only be executed (or handled differently) if expansion occurred, or the logic for overwriting needs to be fixed.
                // Actually, if expansion occurs, we want to overwrite the '-'.
                // If expansion does NOT occur, we want to KEEP the '-'.
                // By doing j--, we cause the next character ('e') to overwrite the '-'.
                
                // Fix: Only perform the "overwrite" logic if expansion happens.
                // Or, move j-- inside the if block.
            }
            j--; // @@ This line executes even when expansion is skipped, causing the next character to overwrite the '-' in the output buffer. It should be inside the if block or handled such that '-' is preserved when no expansion occurs.
        }
    }
    puts(t);
}