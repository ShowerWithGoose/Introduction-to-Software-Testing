#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main()
{
    char s[5000];
    scanf("%s",&s); // @@ Error: scanf with %s expects a char* pointer, not a pointer to an array. Should be scanf("%s", s);
    
    int i = 0;
    
    for(i = 0; i < strlen(s); i ++)
    {
        if(s[i] == '-')
        {
            if(islower(s[i - 1])) // @@ Error: When i is 0, s[i-1] accesses out-of-bounds memory. Should check i > 0 first.
            {
                if(islower(s[i + 1])) // @@ Error: When i is at the last character, s[i+1] accesses out-of-bounds memory. Should check i < strlen(s)-1 first.
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
            else if(isupper(s[i - 1])) // @@ Error: Same out-of-bounds issue as above.
            {
                if(isupper(s[i + 1])) // @@ Error: Same out-of-bounds issue as above.
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
            else if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ Error: Same out-of-bounds issue as above.
            {
                if((s[i - 1] >= '0') && (s[i - 1] <= '9')) // @@ Error: This condition is identical to the outer condition, should check s[i+1] instead.
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
        else if(s[i + 1] != '-') // @@ Error: When i is at the last character, s[i+1] accesses out-of-bounds memory. Should check i < strlen(s)-1 first.
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}