#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and may cause compilation errors with modern compilers. Use 'fgets' instead.]
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
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases where the character after '-' is not a digit, leading to no output of '-' in such cases.]
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
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases where the character after '-' is not a lowercase letter, leading to no output of '-' in such cases.]
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
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases where the character after '-' is not an uppercase letter, leading to no output of '-' in such cases.]
            }
            else
                printf("%c", str[i]);
        }
        else
            printf("%c", str[i]);
    }
}