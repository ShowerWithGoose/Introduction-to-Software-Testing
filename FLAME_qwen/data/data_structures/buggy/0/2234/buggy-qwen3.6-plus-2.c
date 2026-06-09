#include <stdio.h>
#include <string.h>
char s[1001];

int main()
{
    char c;
    scanf("%s", s);
    int i = 0;
    
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == '-')
        {
            if('0' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= '9') // @@ Single quotes are incorrectly used around array access expressions 's[i-1]' and 's[i+1]', creating multi-character literals instead of accessing array elements, which causes a compilation error.
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('A' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'Z') // @@ Single quotes are incorrectly used around array access expressions 's[i-1]' and 's[i+1]', creating multi-character literals instead of accessing array elements, which causes a compilation error.
            {
                for(c = s[i-1] + 1; c < s[i+1]; c++)
                    printf("%c", c); 
            }
            else if('a' <= 's[i-1]' && 's[i-1]' < 's[i+1]' && 's[i+1]' <= 'z') // @@ Single quotes are incorrectly used around array access expressions 's[i-1]' and 's[i+1]', creating multi-character literals instead of accessing array elements, which causes a compilation error.
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