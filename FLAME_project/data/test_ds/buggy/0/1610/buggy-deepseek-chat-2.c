#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ [Error: scanf("%s", s) should be used instead of scanf("%s", &s); s is an array, so &s is unnecessary and incorrect type]
    
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
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: Should print s[i-1] and then the hyphen, but the hyphen should be printed only if no expansion occurs; also missing handling for s[i+1] after hyphen]
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: Same issue as above - modifying the original string]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: Same issue as above]
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ [Error: This condition checks s[i-1] again instead of s[i+1]; should check if s[i+1] is a digit]
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
        else if(s[i + 1] != '-') // @@ [Error: This condition incorrectly skips printing characters that are followed by a hyphen, causing missing output]
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}