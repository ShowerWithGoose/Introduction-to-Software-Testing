#include<stdio.h>
#include<string.h>

char s[10000];

int main()
{
    scanf("%s", &s); // @@ [Compilation Error: 's' is an array name that decays to a pointer. '&s' passes a pointer to an array (char (*)[10000]) instead of a char pointer, causing a type mismatch with '%s'. Should be 's'.]
    
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
            if(s[i - 1] <= 'z' && s[i - 1] >='a' && s[i + 1] <= 'z' && s[i + 1] >='a' && s[i - 1] < s[i + 1])
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= 'Z' && s[i - 1] >='A' && s[i + 1] <= 'Z' && s[i + 1] >='A' && s[i - 1] < s[i + 1])
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            }
            else if(s[i - 1] <= '9' && s[i - 1] >='0' && s[i + 1] <= '9' && s[i + 1] >='0' && s[i - 1] < s[i + 1])
            {
                for(j = s[i - 1] + 1; j < s[i + 1]; j++)
                {
                    printf("%c", j);
                }
            } // @@ [Logical Error: When expansion conditions are not met, the '-' character is not printed. An 'else' clause should be added here to print s[i] to output the input unchanged.]
        }
    }
    return 0;
}