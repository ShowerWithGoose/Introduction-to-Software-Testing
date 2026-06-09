#include<stdio.h>
#include<string.h>

char s[10000];

int main()
{
    scanf("%s", &s); // @@ Error: scanf("%s", s) should be used instead of scanf("%s", &s) because s is already an array (pointer to the first element). Using &s passes the address of the array, which is technically the same address but of a different type (pointer to array), leading to undefined behavior or compiler warnings.
    
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
            }
        }
    }
    return 0;
}