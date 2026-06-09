#include <stdio.h>
#include <string.h>
char s[10001];

int main()
{
    char c;
    scanf("%s", s);
    int i = 0;
    
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == '-')
        {
            if('0' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= '9') // @@ [Character literals like 's[i-1]' are invalid; should be s[i-1] without quotes to refer to the actual character in the array]
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('A' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'Z') // @@ [Same error: 's[i-1]' is a multi-character literal, not the variable; should be s[i-1]]
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('a' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'z') // @@ [Same error: 's[i-1]' and 's[i+1]' should not be in single quotes]
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else
                printf("%c",s[i]);
        }
        else
            printf("%c", s[i]);
    }
    return 0;
}