#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    if(strlen(s)<=2)
    printf("%s",s);
    else
    {
        for(int i=1;i<=strlen(s)-2;)
        {if(s[i]!='-')
        {printf("%c",s[i-1]);
        i+=1;
        }
        else
        {
        int flag=0;
        if(s[i-1]<='z'&&s[i-1]>='a')
        {if(s[i+1]<='z'&&s[i+1]>='a'&&s[i+1]>s[i-1])
        flag=1;
        }
        else if(s[i-1]<='Z'&&s[i-1]>='A')
        {if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i+1]>s[i-1])
        flag=1;
        }
        // Missing check for digit range [0-9] similar to letters. 
        // However, the specific error in the test case a-uB-F is about the loop logic below.
        
        if(flag==1)
        {for(int j=0;j<=s[i+1]-s[i-1];j++) // @@ The loop condition j<=s[i+1]-s[i-1] causes the end character to be printed twice if not handled correctly with index advancement, but more importantly, this logic prints the full expansion including start and end.
        printf("%c",s[i-1]+j);
        }
        else
        printf("%c%c%c",s[i-1],s[i],s[i+1]);
        i+=2;} // @@ The index advancement i+=2 skips the character after the hyphen (s[i+1]). If expansion happened, s[i+1] was already printed as part of the loop. If no expansion happened, it was printed in the else block. However, the next iteration starts at i+2. The character at s[i+1] is effectively consumed. But wait, if we have a-uB-F:
                 // 1. i=1 ('-'). Expands a-u. Prints a..u. i becomes 3.
                 // 2. i=3 ('B'). s[3]!='-'. Prints s[2] which is 'u'. @@ This is the error. The character 'u' (s[i-1] where i=3, so s[2]) is printed again.
                 // The logic `if(s[i]!='-') { printf("%c",s[i-1]); i+=1; }` assumes that s[i-1] hasn't been processed yet. 
                 // But when we processed the hyphen at i=1, we consumed s[0], s[1], s[2]. The next unprocessed character should be s[3].
                 // The loop structure is flawed because it always looks back at s[i-1].
                 // When i advances by 2 after processing a hyphen triplet, the next character to check for being a hyphen is at the new i.
                 // But the `if(s[i]!='-')` branch prints s[i-1]. 
                 // In the case of a-uB-F:
                 // i=1 is '-'. Process a-u. Output: abc...u. i becomes 3.
                 // Loop continues. i=3. s[3] is 'B'. Not '-'.
                 // Executes: printf("%c", s[3-1]) -> printf("%c", s[2]) -> prints 'u' again.
                 // Then i becomes 4.
                 // i=4. s[4] is '-'. Process B-F. Output: BCDEF. i becomes 6.
                 // Loop ends.
                 // Result: ...uuBCDEF.
                 // The error is that after expanding a hyphen sequence, the character immediately following the sequence (s[i+1] of the hyphen) has been printed. The next iteration should start checking from the character *after* that one, but the logic `printf("%c", s[i-1])` re-prints the last character of the previous expansion if the next char is not a hyphen.
                 // Actually, the variable `i` points to the current character being examined as a potential hyphen.
                 // If s[i] is not '-', it prints s[i-1] and increments i. This means it's printing the character *before* the current one.
                 // This implies the algorithm assumes that if s[i] is not '-', then s[i-1] is a "standalone" character that hasn't been printed yet.
                 // However, if we just finished processing a hyphen at i_prev, we incremented i by 2. So the new i is i_prev + 2.
                 // The character at i_prev + 1 (which is s[i-1] for the new i) was the end of the expansion or the third char of the literal triplet. It was ALREADY printed.
                 // So, when we enter the `else` branch of `if(s[i]!='-')`, we are re-printing s[i-1].
                 // To fix this, we need to track whether the previous character was already printed.
                 // Or simply change the logic to iterate differently.
                 // Given the constraint to only mark errors:
                 // The line `printf("%c",s[i-1]);` is incorrect in the context where the previous step was an expansion or literal triplet print that included s[i-1].
                 
    }
    
}
}