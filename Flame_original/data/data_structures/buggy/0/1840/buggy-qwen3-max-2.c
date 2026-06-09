#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, some compilers may not support it, leading to compilation errors.]
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
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases where the character after '-' is not a digit when the one before is; this leads to skipping output of '-' in mixed-type cases like '0-a'.]
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
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases where the character after '-' is not a lowercase letter when the one before is; e.g., 'a-B' should output '-'.]
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
                    printf("%c", str[i]); // @@ [Missing else clause to handle cases where the character after '-' is not an uppercase letter when the one before is; e.g., 'A-9' should output '-'.]
            }
            else
                printf("%c", str[i]);
        }
        else
            printf("%c", str[i]);
    }
}