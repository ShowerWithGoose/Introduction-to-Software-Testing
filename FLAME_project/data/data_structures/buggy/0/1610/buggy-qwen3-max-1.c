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
                        s[i - 1] = s[i - 1] + 1; // @@ [Modifying the input string during iteration leads to incorrect behavior and affects future comparisons. Also, this loop prints the starting character repeatedly instead of expanding from s[i-1]+1 to s[i+1]-1.]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [This prints the previous character again, but it was already printed in a prior iteration, causing duplication.]
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same error as above: modifying input string and incorrect expansion logic.]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Duplication of previous character which was already printed.]
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ [This condition checks s[i-1] again instead of checking s[i+1]; should check if s[i+1] is a digit.]
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Same issues: modifies input, wrong expansion range, prints wrong characters.]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Duplication issue again.]
                }        
            }
            // @@ [Missing else case: if '-' doesn't meet any valid expansion condition, it should print '-', but current code may skip printing it entirely in some paths.]
        }
        else if(s[i + 1] != '-') // @@ [This condition causes characters before a '-' to be skipped if the next character is '-', leading to missing output of the character just before '-'. For example, in "a-c", when i=0 ('a'), s[1]=='-' so it skips printing 'a', but then inside '-' handling it may or may not print 'a' again — causing either duplication or omission.]
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}