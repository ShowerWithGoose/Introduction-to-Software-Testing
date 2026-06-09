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
                    printf("%c", str[i]); // @@ [Missing else clause: if the character after '-' is not a digit, the '-' should be printed, but current code falls through without printing anything in this branch.]
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
                    printf("%c", str[i]); // @@ [Missing else clause: similar to digit case, if next char is not lowercase, '-' should be printed, but it's not handled.]
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
                    printf("%c", str[i]); // @@ [Missing else clause: same issue for uppercase letters.]
            }
            else
                printf("%c", str[i]);
        }
        else
            printf("%c", str[i]);
    }
}