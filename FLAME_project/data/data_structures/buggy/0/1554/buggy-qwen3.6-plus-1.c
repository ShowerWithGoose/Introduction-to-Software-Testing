#include <stdio.h>
#include <string.h>

int main()
{
    char sim[101];
    char ha;
    int i,j;
    gets(sim);
    for(i=0;i<strlen(sim);i++)
    {
        if(sim[i]=='-'&&sim[i+1]>sim[i-1]) 
        {
            if(sim[i-1]>='a'&&sim[i-1]<='z'&&sim[i+1]>='a'&&sim[i+1]<='z')
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else if(sim[i-1]>='A'&&sim[i-1]<='Z'&&sim[i+1]>='A'&&sim[i+1]<='Z') // @@ The original code used independent 'if' statements. If the first 'if' (lowercase) is false, it falls through to the second 'if'. If the second 'if' (uppercase) is also false, it falls through to the third 'if'. If the third 'if' (digits) is false, it executes the 'else' block which prints "-". However, if the first 'if' is true, it expands. If the first is false but the second is true, it expands. The problem arises because the 'else' is only attached to the last 'if'. So if we have lowercase letters, the first 'if' executes expansion. Then the second 'if' is checked (false), then the third 'if' is checked (false), and its 'else' executes, printing an extra "-". We need 'else if' to ensure only one block executes or none, and handle the non-expansion case correctly. Actually, looking closer: if it's lowercase, first if runs. Then second if fails. Third if fails. Else of third if runs -> prints "-". This causes the bug where a valid expansion is followed by a hyphen.
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else if(sim[i-1]>='0'&&sim[i-1]<='9'&&sim[i+1]>='0'&&sim[i+1]<='9') // @@ Same logic as above, needs to be else if to prevent falling into the final else incorrectly when a previous condition was met, or to correctly group the mutually exclusive types.
            {
                for(j=1;j<sim[i+1]-sim[i-1];j++)
                {
                    ha=sim[i-1]+j;
                    printf("%c", ha);
                }
            }
            else
            {
                printf("-"); // @@ This else belongs to the digit check. If the type is not digits (and not uppercase due to previous if/else-if structure fix), it prints hyphen. But we should only print the hyphen if NO expansion happened. With the 'else if' chain, this else covers cases where types don't match or are invalid, so printing '-' is correct here IF the outer if condition (sim[i]=='-') was met. Wait, if the types don't match (e.g. a-R), the outer if is true (a < R is true in ASCII? 'a'=97, 'R'=82. No. 97 > 82. So outer if is false. It goes to else branch printing chars. Correct. What about A-b? 'A'=65, 'b'=98. Outer if true. First if (lower) false. Second if (upper) false (b is not upper). Third if (digit) false. Else executes: prints "-". But we should print "A-b" unchanged. The current logic prints "A" (from else branch of outer loop? No. i is at '-'. Outer if is true. Inner checks fail. Else prints "-". Next iteration i is at 'b'. Outer if false (no next char or not '-'). Prints 'b'. So "A-b" becomes "A-b". Wait. The input is processed char by char.
                // Let's trace A-b.
                // i=0 ('A'): outer if false. Prints 'A'.
                // i=1 ('-'): outer if true ('-'=='-' and 'b'>'A').
                //   inner if 1 (lower): false.
                //   inner if 2 (upper): false ('b' is not >= 'A' && <= 'Z'? 'b' is 98, 'Z' is 90. False).
                //   inner if 3 (digit): false.
                //   else: prints "-".
                // i=2 ('b'): outer if false. Prints 'b'.
                // Result: A-b. Correct.
                
                // Let's trace a-u.
                // i=0 ('a'): Prints 'a'.
                // i=1 ('-'): outer if true.
                //   inner if 1 (lower): true. Loop prints b..t.
                //   inner if 2 (upper): false.
                //   inner if 3 (digit): false.
                //   else: prints "-".  <-- BUG. It prints the hyphen again after expansion.
                // i=2 ('u'): Prints 'u'.
                // Result: abc...t-u. Expected: abc...tu.
                
                // So the error is indeed that the `else` prints "-" even when expansion occurred in a previous `if` block within the same iteration. Using `else if` prevents falling through to the final `else` if a previous condition was met.
            }
        }
        else
        {
            printf("%c", sim[i]);
        }
    }
    return 0;
}