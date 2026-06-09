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
                        printf("%c",str[i]); // @@ This prints only the '-' when the left character is not less than the right, but the problem requires printing the entire '-' and the following character unchanged. For example, "B-e" should output "B-e", but here it only prints '-', missing the 'e'.
                }
                else
                    printf("%c", str[i]); // @@ This prints only the '-' when the right character is not a digit, but the problem requires printing the entire '-' and the following character unchanged. For example, "B-e" should output "B-e", but here it only prints '-', missing the 'e'.
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
                        printf("%c", str[i]); // @@ Same issue: should print the '-' and the following character, not just '-'.
                }
                else
                    printf("%c", str[i]); // @@ Same issue: should print the '-' and the following character, not just '-'.
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
                        printf("%c", str[i]); // @@ Same issue: should print the '-' and the following character, not just '-'.
                }
                else
                    printf("%c", str[i]); // @@ Same issue: should print the '-' and the following character, not just '-'.
            }
            else
                printf("%c", str[i]); // @@ Same issue: should print the '-' and the following character, not just '-'.
        }
        else
            printf("%c", str[i]);
    }
}