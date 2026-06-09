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
                        printf("%c",str[i]); // @@ This prints only the '-' character when the condition fails, but the expected behavior is to print the entire '-' and the following character unchanged. For example, for "B-e", when the first character is 'B' (uppercase) and the third is 'e' (lowercase), this branch is not taken, but the else branch at line 50 prints only '-', missing the 'e'. The logic should handle cases where the characters are not of the same type by printing the '-' and the next character.
                }
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
                        printf("%c", str[i]); // @@ Same issue as above: when the condition fails (e.g., 'z' before '-'), it prints only '-', but should print the entire '-' and the following character unchanged.
                }
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
                        printf("%c", str[i]); // @@ Same issue: when the condition fails (e.g., 'A' before '-'), it prints only '-', but should print the entire '-' and the following character unchanged.
                }
            }
            else
                printf("%c", str[i]); // @@ This prints only '-' when the characters are of different types (e.g., 'B' and 'e'), but the expected output is "B-e", meaning the '-' and the following character should both be printed. The code should print "-" followed by str[i+1] in this case.
        }
        else
            printf("%c", str[i]);
    }
}