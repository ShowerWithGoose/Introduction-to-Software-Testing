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
                    while((s[i - 1] - s[i + 1])< 0) // @@ Only handles expansion when s[i-1] < s[i+1]; if s[i-1] >= s[i+1], the loop is skipped and s[i-1] and '-' are not printed, violating the requirement to output unchanged.
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
                    while((s[i - 1] - s[i + 1])< 0) // @@ Same error: fails to print s[i-1] and '-' when s[i-1] >= s[i+1].
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
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ Error: checks s[i-1] again instead of checking if s[i+1] is a digit. Should be (s[i+1] >= '0' && s[i+1] <= '9').
                {
                    while((s[i - 1] - s[i + 1])< 0) // @@ Same error: fails to print s[i-1] and '-' when s[i-1] >= s[i+1].
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
        else if(s[i + 1] != '-') // @@ Incorrect condition: skips printing characters that are immediately followed by '-', even when no expansion occurs. Should simply be 'else' to print all non-'-' characters.
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}