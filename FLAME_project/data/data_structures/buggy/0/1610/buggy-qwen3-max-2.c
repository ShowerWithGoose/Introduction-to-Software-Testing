#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ [Using &s is incorrect; s is already a pointer to the first element, so it should be scanf("%s", s);]
    
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
                        s[i - 1] = s[i - 1] + 1; // @@ [Modifying the input string during iteration causes incorrect behavior and affects subsequent checks. Also, this loop prints from s[i-1] up to but not including s[i+1], which is correct in logic but flawed due to mutation.]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [This prints the previous character again, but that character was already printed in a prior iteration, leading to duplication.]
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same issue: modifying s[i-1] corrupts the original string and affects future processing.]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Again, duplicates the previous character which was already printed.]
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ [This condition checks s[i-1] twice instead of checking s[i+1]; should check if s[i+1] is also a digit.]
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same mutation problem; also, if s[i+1] is not a digit, this branch shouldn't execute at all.]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Duplication issue again.]
                }        
            }
        }
        else if(s[i + 1] != '-') // @@ [This condition skips printing the current character if the next character is '-', but the current character might be part of an expansion (e.g., 'a' in "a-c") and needs to be printed before expansion. Also, when i is at the last character, s[i+1] is '\0', so it gets printed, but logic is flawed overall.]
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}