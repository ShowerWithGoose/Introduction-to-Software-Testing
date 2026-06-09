#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ The & is unnecessary; s is already a pointer to the first element. Should be scanf("%s", s);
    
    int i = 0;
    
    for(i = 0; i < strlen(s); i ++)
    {
        if(s[i] == '-')
        {
            if(islower(s[i - 1])) // @@ When i is 0, s[i-1] accesses memory before the array, causing undefined behavior. Should check i > 0 first.
            {
                if(islower(s[i + 1])) // @@ When i is at the last character, s[i+1] accesses memory beyond the string, causing undefined behavior. Should check i < strlen(s)-1 first.
                {
                    while((s[i - 1] - s[i + 1])< 0)
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
            else if(isupper(s[i - 1])) // @@ Same issue: potential out-of-bounds access when i is 0.
            {
                if(isupper(s[i + 1])) // @@ Same issue: potential out-of-bounds access when i is at the last character.
                {
                    while((s[i - 1] - s[i + 1])< 0)
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
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ Same issue: potential out-of-bounds access when i is 0.
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ This condition is identical to the outer condition; should check s[i+1] for digit.
                {
                    while((s[i - 1] - s[i + 1])< 0)
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
        else if(s[i + 1] != '-') // @@ When i is at the last character, s[i+1] accesses memory beyond the string, causing undefined behavior. Should check i < strlen(s)-1 first.
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}