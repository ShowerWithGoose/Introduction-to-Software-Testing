#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ [Error: should use 's' (without '&') for scanf, as 's' is already a pointer to the first element]
    
    int i = 0;
    
    for(i = 0; i < strlen(s); i ++) // @@ [Error: using strlen(s) in loop condition while modifying s inside causes undefined behavior; also inefficient]
    {
        if(s[i] == '-')
        {
            if(islower(s[i - 1])) // @@ [Error: out-of-bounds access when i = 0, no check for i > 0]
            {
                if(islower(s[i + 1])) // @@ [Error: out-of-bounds access when i is the last index (dash at end)]
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: modifies the original string, corrupting it for subsequent expansions]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: prints extra character s[i-1] when expansion is invalid; should only print the dash]
                }    
            }
            else if(isupper(s[i - 1]))
            {
                if(isupper(s[i + 1]))
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: modifies original string]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: prints extra character]
                }        
            }
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9'))
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ [Error: condition should check s[i+1] instead of s[i-1] again]
                {
                    while((s[i - 1] - s[i + 1])< 0)
                    {
                        printf("%c",s[i - 1]);
                        s[i - 1] = s[i - 1] + 1; // @@ [Error: modifies original string]
                    }
                }
                else
                {
                    printf("%c%c",s[i - 1],s[i]); // @@ [Error: prints extra character]
                }        
            } // @@ [Error: missing else here to print the dash alone when expansion is invalid (e.g., different types or out of range)]
        }
        else if(s[i + 1] != '-') // @@ [Error: condition suppresses printing of a character that is before a dash, causing the first character of a range to be lost]
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}