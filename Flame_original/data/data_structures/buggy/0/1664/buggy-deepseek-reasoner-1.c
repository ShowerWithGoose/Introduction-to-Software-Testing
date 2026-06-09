#include<stdio.h>
#include<string.h>

char s[10000];

int main()
{
    scanf("%s", &s); // @@ [Error: scanf expects a char*, but &s is of type char(*)[10000]; use s instead]
    
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
            if(s[i - 1] <= 'z' && s[i - 1] >='a' && s[i + 1] <= 'z' && s[i + 1] >='a' && s[i - 1] < s[i + 1]) // @@ [Error: No boundary check for i=0 or i=len-1, causing out-of-bounds access; also missing else to output '-' when expansion conditions fail]
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= 'Z' && s[i - 1] >='A' && s[i + 1] <= 'Z' && s[i + 1] >='A' && s[i - 1] < s[i + 1]) // @@ [Error: same boundary issue]
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= '9' && s[i - 1] >='0' && s[i + 1] <= '9' && s[i + 1] >='0' && s[i - 1] < s[i + 1]) // @@ [Error: same boundary issue]
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