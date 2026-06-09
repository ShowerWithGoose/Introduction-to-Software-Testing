#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ [Error: scanf should use s without &, as s is already an array name representing the address]
    
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
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: Modifying s[i-1] corrupts the original string, causing incorrect behavior for subsequent characters]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: Should print the character before '-' and the '-' itself, but this prints the character before '-' twice and misses the character after '-']
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: Same issue as above - modifying the string corrupts it]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: Same issue as above]
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ [Error: This condition checks s[i-1] again instead of s[i+1], so it never correctly checks if the next character is a digit]
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: Same issue as above]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: Same issue as above]
                }        
            }
        }
        else if(s[i + 1] != '-') // @@ [Error: This condition incorrectly skips printing characters that are followed by '-', causing missing output]
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}