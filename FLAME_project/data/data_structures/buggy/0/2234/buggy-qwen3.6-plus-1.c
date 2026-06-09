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
            if('0' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= '9') // @@ [Error: The characters 's[i-1]' and 's[i+1]' are enclosed in single quotes, treating them as character literals (multi-character constants) instead of variable accesses. This prevents the code from checking the actual values in the array. It should be s[i-1] and s[i+1].]
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('A' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'Z') // @@ [Error: Same as above. 's[i-1]' and 's[i+1]' are treated as character literals instead of variables. It should be s[i-1] and s[i+1].]
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('a' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'z') // @@ [Error: Same as above. 's[i-1]' and 's[i+1]' are treated as character literals instead of variables. It should be s[i-1] and s[i+1].]
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