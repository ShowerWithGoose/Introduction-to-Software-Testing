#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    gets(str); // @@ gets() is unsafe and deprecated, prone to buffer overflow; fgets() should be used instead.
    int i;
    int j;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '-')
        {
            if (str[i - 1] >= '0' && str[i - 1] <= '9') // @@ Accessing str[i-1] when i=0 causes out-of-bounds undefined behavior.
            {
                if (str[i + 1] >= '0' && str[i + 1] <= '9') // @@ Missing else branch: if str[i+1] is not a digit, '-' is not printed, causing incorrect output for mixed types like "0-b".
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j);
                    }
                    else
                        printf("%c",str[i]);
                }
            }
            else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
            {
                if (str[i + 1] >= 'a' && str[i + 1] <= 'z') // @@ Missing else branch: if str[i+1] is not a lowercase letter, '-' is omitted from output.
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j);
                    }
                    else
                        printf("%c", str[i]);
                }
            }
            else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
            {
                if (str[i + 1] >= 'A' && str[i + 1] <= 'Z') // @@ Missing else branch: if str[i+1] is not an uppercase letter, '-' is omitted from output.
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j);
                    }
                    else
                        printf("%c", str[i]);
                }
            }
            else
                printf("%c", str[i]);
        }
        else
            printf("%c", str[i]);
    }
}