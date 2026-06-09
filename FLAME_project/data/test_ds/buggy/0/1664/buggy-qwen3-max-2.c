#include<stdio.h>
#include<string.h>

char s[10000];

int main()
{
    scanf("%s", &s);
    
    int i, k = strlen(s);
    char j;
    
    for(i = 0; i < k; i++)
    {
        if(s[i] != '-')
        {
            printf("%c", s[i]);
        }
        else
        {
            if(s[i - 1] <= 'z' && s[i - 1] >='a' && s[i + 1] <= 'z' && s[i + 1] >='a' && s[i - 1] < s[i + 1]) @@ // The condition checks only that both characters are in [a-z], but does not ensure they are of the same type as required. However, the real issue is that when '-' appears at position 0 or at the end, s[i-1] or s[i+1] may be out of bounds, leading to undefined behavior. Also, for input like "B-e", this condition fails (as expected), but the program doesn't print the '-' itself in the else case.
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= 'Z' && s[i - 1] >='A' && s[i + 1] <= 'Z' && s[i + 1] >='A' && s[i - 1] < s[i + 1]) @@ // Same issue: if the '-' is not part of a valid expansion, the '-' itself is never printed. According to requirements, invalid patterns like "B-e" should output the original string unchanged, but this code skips printing '-' in such cases.
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= '9' && s[i - 1] >='0' && s[i + 1] <= '9' && s[i + 1] >='0' && s[i - 1] < s[i + 1]) @@ // Same problem: when none of the conditions match (e.g., "B-e"), the '-' is not printed at all, causing the output to miss the '-' character.
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
        }
    }
    return 0;
}