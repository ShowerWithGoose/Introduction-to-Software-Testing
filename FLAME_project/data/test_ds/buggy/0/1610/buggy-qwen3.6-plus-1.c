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
                    while((s[i - 1] - s[i + 1])< 0) // @@ Modifies s[i-1] in place, corrupting the original string; also incorrectly prints starting from the left character instead of left+1.
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1;
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ Prints s[i-1] again, causing duplicate output since it was already printed or skipped in the previous iteration.
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0) // @@ Modifies s[i-1] in place, corrupting the original string; incorrect expansion logic.
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1;
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ Prints s[i-1] again, causing duplicate output.
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ Incorrectly checks s[i-1] again instead of s[i+1] to verify the right boundary is a digit.
                {
                    while((s[i - 1] - s[i + 1])< 0) // @@ Modifies s[i-1] in place, corrupting the original string; incorrect expansion logic.
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1;
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ Prints s[i-1] again, causing duplicate output.
                }        
            }
        }
        else if(s[i + 1] != '-') // @@ Incorrectly skips printing the character immediately before '-', leading to missing characters in the output.
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}