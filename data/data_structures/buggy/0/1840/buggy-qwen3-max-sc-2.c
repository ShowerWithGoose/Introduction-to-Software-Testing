#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
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
                        printf("%c",str[i]);
                }
                else
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases like '0-a'; should output '-' unchanged when types differ]
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
                        printf("%c", str[i]);
                }
                else
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases like 'a-Z'; should output '-' unchanged when types differ]
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
                        printf("%c", str[i]);
                }
                else
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases like 'A-9'; should output '-' unchanged when types differ]
            }
            else
                printf("%c", str[i]);
        }
        else
            printf("%c", str[i]);
    }
}