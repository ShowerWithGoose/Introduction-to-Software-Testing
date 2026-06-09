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
            if('0' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= '9') // @@ Error: Using character literals 's[i-1]' instead of the variable s[i-1]; also the condition logic is incorrect, should check s[i-1] and s[i+1] are digits and s[i-1] < s[i+1]
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('A' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'Z') // @@ Error: Same issue with character literals; should use s[i-1] and s[i+1] without quotes
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('a' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'z') // @@ Error: Same issue with character literals; should use s[i-1] and s[i+1] without quotes
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