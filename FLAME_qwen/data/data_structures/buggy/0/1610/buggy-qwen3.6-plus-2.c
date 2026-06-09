#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ Incorrect argument type for scanf; should be 's' instead of '&s' to match expected char* pointer.
    
    int i = 0;
    
    for(i = 0; i < strlen(s); i ++)
    {
        if(s[i] == '-') // @@ Missing boundary checks for i > 0 and s[i+1] != '\0'; accessing s[i-1] when i=0 causes out-of-bounds memory access.
        {
            if(islower(s[i - 1]))
            {
                if(islower(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0) // @@ Modifies s[i-1] in place, corrupting the original string; also fails to print the right boundary character.
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1;
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
                    while((s[i - 1] - s[i + 1])< 0) // @@ Same issue: modifies s[i-1] directly and misses printing the end character of the range.
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1;
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]);
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ Copy-paste error: checks s[i-1] again instead of s[i+1] to verify the right character is a digit.
                {
                    while((s[i - 1] - s[i + 1])< 0) // @@ Same issue: modifies s[i-1] and misses printing the end character.
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1;
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]);
                }        
            }
        }
        else if(s[i + 1] != '-') // @@ Incorrect logic; skips printing characters preceding '-', which causes missing output when expansion conditions are not met.
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}