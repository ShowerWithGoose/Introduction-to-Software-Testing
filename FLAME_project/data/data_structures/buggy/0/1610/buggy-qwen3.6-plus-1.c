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
                        s[i - 1] = s[i - 1] + 1; // @@ Modifying the original string array causes subsequent characters to be corrupted (e.g., 'a' becomes 'b', affecting future iterations or logic). Also, this loop prints the start character and increments it, but fails to print the end character if the loop condition stops before it, or prints incorrectly depending on boundary. More critically, modifying s[i-1] changes the source data which might be referenced again or affects the logical flow if the string is re-read. The primary issue here is that modifying the input buffer `s` leads to undefined behavior or incorrect state for subsequent processing, especially since `s[i-1]` is part of the original string structure.
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]);
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ Same error: modifying the original string buffer `s` instead of using a temporary variable for iteration. This corrupts the input data.
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]);
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i + 1] >= '0') && (s[i + 1] <= '9')) // @@ The original code checked s[i-1] again instead of s[i+1]. This is a logical error preventing correct digit range validation.
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ Same error: modifying the original string buffer `s` instead of using a temporary variable for iteration. This corrupts the input data.
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]);
                }        
            }
            else 
            {
                 printf("%c", s[i]); // @@ Missing else block for cases where types don't match (e.g., a-R). Without this, the '-' is not printed when expansion doesn't happen, leading to missing characters in output.
            }
        }
        else if(s[i + 1] != '-') // @@ This condition skips printing the character immediately preceding a '-'. For example, in "a-c", when i points to 'a', s[i+1] is '-', so 'a' is not printed here. It relies on the expansion block to print it. However, if expansion doesn't happen (e.g. invalid range), the previous block handles printing s[i-1] and s[i]. But for the last character or characters not involved in expansion properly, this logic is flawed. Specifically, if we have "0-A", '0' is at index 0. If i=0, s[1] is '-', so it skips. Then i=1 is '-'. It goes into the if block. The else-if prevents printing characters that are left operands of a hyphen, assuming the hyphen block handles them. But if the hyphen block doesn't expand, it prints s[i-1] and s[i]. This double printing or skipping logic is fragile. The main issue causing the specific WA "abcdefg0123456789:;<=>?@A" vs "abcdefg0-A" is that the digit expansion logic is broken (checking s[i-1] twice) AND the modification of s[i-1] corrupts memory/logic. 
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}