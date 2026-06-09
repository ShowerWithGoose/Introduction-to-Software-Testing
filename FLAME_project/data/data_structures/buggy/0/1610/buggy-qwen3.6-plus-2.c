#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s);
    
    int i = 0;
    
    for(i = 0; i < strlen(s); i ++)
    {
        if(s[i] == '-')
        {
            if(islower(s[i - 1]))
            {
                if(islower(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ Modifying the original string array causes subsequent characters to be corrupted or misinterpreted, leading to incorrect expansion for later parts of the string (e.g., '0-A' becomes invalid because previous expansions overwrote memory or logic flow is broken by state change). Also, it fails to print the end character of the range.
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ When types don't match, it should output the previous character, the hyphen, and potentially handle the next character correctly. However, the main issue is that this branch doesn't prevent the next iteration from processing the next character incorrectly if logic isn't careful. More critically, the reference logic implies if expansion doesn't happen, we just output the hyphen. The previous char was already printed in a previous iteration or needs to be handled. Actually, looking at the loop structure: if s[i] is '-', s[i-1] was likely printed in the previous iteration unless it was part of a previous expansion. Wait, in the provided buggy code, s[i-1] is NOT printed before hitting '-'. So if expansion fails, we must print s[i-1] and s[i]. But what about s[i+1]? It will be processed in the next iteration. If s[i+1] is not '-', it will be printed. This seems okay for non-expansion, BUT the modification of s[i-1] in the expansion block is the critical error.
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ Same error: modifying the source string leads to undefined behavior and incorrect output for subsequent segments.
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ Similar logic issue as above regarding outputting unchanged segments.
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i + 1] >= '0') && (s[i + 1] <= '9')) // @@ The condition here checks s[i-1] again instead of s[i+1], which is a copy-paste error. It should check if s[i+1] is a digit.
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ Same error: modifying the source string.
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ Similar logic issue.
                }        
            }
        }
        else if(s[i + 1] != '-') // @@ This condition skips printing characters that are followed by a '-'. However, if the character before '-' was not expanded (e.g. mismatched types), it was printed inside the 'else' block of the expansion check. If it WAS expanded, the characters were printed inside the while loop. The character AFTER the hyphen (s[i+1]) needs to be printed if it's not part of an expansion start. But this logic is flawed because if s[i] is not '-', we check if the NEXT char is '-'. If the next char IS '-', we skip printing current char? No, if s[i+1]=='-', s[i] is the left operand. It should NOT be printed here because it's handled in the s[i]=='-' block (either expanded or printed as literal). If s[i+1]!='-', s[i] is a normal char and should be printed. This logic actually seems partially correct for avoiding double printing of the left operand, BUT it fails to print the right operand if it's not followed by a hyphen? No, the right operand will be processed when i increments. If s[i] is the right operand of a previous hyphen, s[i-1] was '-'. So s[i] is not '-', and s[i+1] is likely not '-'. So it prints. The real issue is that the expansion blocks modify s[i-1], corrupting the string.
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}