#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ [Error: scanf("%s", s) should be used instead of scanf("%s", &s) because s is already a pointer to the first element of the array; using &s is incorrect and may cause undefined behavior]
    
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
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: This modifies the original string s, which can cause incorrect behavior when processing subsequent characters; also, the loop condition should check for s[i-1] < s[i+1] rather than using subtraction, and the loop should stop before printing s[i+1] to avoid duplication]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: When the characters are not of the same type, the '-' should be printed as is, but this prints s[i-1] and s[i] which may be incorrect; also, the else branch does not handle the case where s[i-1] is not a letter or digit]
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same error as above: modifying the original string and loop logic issue]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Same error as above]
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ [Error: This condition checks s[i-1] again instead of s[i+1]; it should check if s[i+1] is a digit]
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same error as above]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Same error as above]
                }        
            }
        }
        else if(s[i + 1] != '-') // @@ [Error: This condition incorrectly skips printing characters that are followed by a '-', causing missing output; also, it does not handle the case where s[i] is the last character]
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}