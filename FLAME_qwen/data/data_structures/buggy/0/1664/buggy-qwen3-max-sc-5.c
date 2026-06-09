#include<stdio.h>
#include<string.h>

char s[10000];

int main()
{
    scanf("%s", &s); // @@ [Using &s is incorrect; s is already a pointer to the first element of the array. Should be scanf("%s", s);]
    
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
            if(i == 0 || i == k - 1) // @@ [Missing boundary check: when '-' is at the start or end, s[i-1] or s[i+1] accesses invalid memory]
            {
                printf("%c", s[i]);
            }
            else if(s[i - 1] <= 'z' && s[i - 1] >='a' && s[i + 1] <= 'z' && s[i + 1] >='a' && s[i - 1] < s[i + 1])
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
            }
            else
            {
                printf("%c", s[i]); // @@ [Missing else clause to output '-' when expansion conditions are not met]
            }
        }
    }
    return 0;
}