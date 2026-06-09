#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    gets(str);
    int i;
    int j;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '-')
        {
            if (str[i - 1] >= '0' && str[i - 1] <= '9')
            {
                if (str[i + 1] >= '0' && str[i + 1] <= '9')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j);
                    }
                    else
                        printf("%c",str[i]); // @@ This prints only '-' when the condition fails, but should print the entire '-' and the following character as-is. Also, the else branch for non-matching types is missing, causing characters to be skipped.
                }
                else
                    printf("%c", str[i]); // @@ This prints only '-' when the character after '-' is not a digit, but should print the entire '-' and the following character as-is (e.g., "B-e" should output "B-e", not just "-").
            }
            else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
            {
                if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j);
                    }
                    else
                        printf("%c", str[i]); // @@ Same issue: prints only '-' when the expansion condition fails, but should output the '-' and the next character unchanged.
                }
                else
                    printf("%c", str[i]); // @@ Same issue: prints only '-' when the next character is not a lowercase letter, but should output the '-' and the next character unchanged.
            }
            else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
            {
                if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j);
                    }
                    else
                        printf("%c", str[i]); // @@ Same issue: prints only '-' when the expansion condition fails, but should output the '-' and the next character unchanged.
                }
                else
                    printf("%c", str[i]); // @@ Same issue: prints only '-' when the next character is not an uppercase letter, but should output the '-' and the next character unchanged.
            }
            else
                printf("%c", str[i]); // @@ This prints only '-' when the character before '-' is not alphanumeric, but should output the '-' and the next character unchanged.
        }
        else
            printf("%c", str[i]);
    }
}