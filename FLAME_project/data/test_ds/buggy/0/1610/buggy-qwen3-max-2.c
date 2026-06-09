#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ [Using &s is incorrect; s is already a pointer to char array, should be scanf("%s", s);]
    
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
                        s[i - 1] = s[i - 1] + 1; // @@ [Modifying the input string during iteration causes incorrect behavior and affects future comparisons]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [This prints the previous character again, but it was already printed in a prior iteration, causing duplication]
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same issue: modifying s[i-1] corrupts the original string and leads to wrong output]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Again, duplicate printing of s[i-1]]
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ [This condition checks s[i-1] twice instead of checking s[i+1]; should check if s[i+1] is digit]
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same modification error]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Duplicate printing again]
                }        
            }
        }
        else if(s[i + 1] != '-') // @@ [This condition skips printing current character if next is '-', but then '-' case doesn't print the left char properly, leading to missing or duplicated characters]
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}