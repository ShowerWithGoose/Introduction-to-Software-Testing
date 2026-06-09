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
                        printf("%c",str[i]); // @@ This prints '-' when the characters are of the same type but the second is not greater than the first, but it fails to also print the character after '-'. According to the problem, when no expansion is performed, the entire input should be output unchanged, meaning both '-' and the following character should be printed. However, the reference program prints "-%c" for such cases, so this line should be changed to print both '-' and str[i+1].
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
                        printf("%c", str[i]); // @@ Same issue as above: should print both '-' and str[i+1] when no expansion occurs.
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
                        printf("%c", str[i]); // @@ Same issue: should print '-' and str[i+1] when no expansion.
                }
            }
            else
                printf("%c", str[i]); // @@ This prints only '-' when the characters around '-' are of different types (e.g., 'B' and 'e'), but the problem requires that in such cases the input is output unchanged, meaning both '-' and the following character should be printed. The reference program prints "-%c" for this case, so this line should be changed to print '-' and str[i+1].
        }
        else
            printf("%c", str[i]);
    }
}