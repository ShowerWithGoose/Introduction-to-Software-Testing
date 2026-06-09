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
            if (str[i - 1] >= '0' && str[i - 1] <= '9') // @@ [Access str[i-1] when i=0 causes out-of-bounds; also missing handling for cases where right character is not of same type]
            {
                if (str[i + 1] >= '0' && str[i + 1] <= '9') // @@ [Access str[i+1] when i is last index causes out-of-bounds; also this conditional branch lacks an else to print the dash when right character is not a digit]
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
            else if (str[i - 1] >= 'a' && str[i - 1] <= 'z') // @@ [Access str[i-1] when i=0 causes out-of-bounds]
            {
                if (str[i + 1] >= 'a' && str[i + 1] <= 'z') // @@ [Access str[i+1] when i is last index causes out-of-bounds; also lacks else for mismatched types]
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
            else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z') // @@ [Access str[i-1] when i=0 causes out-of-bounds]
            {
                if (str[i + 1] >= 'A' && str[i + 1] <= 'Z') // @@ [Access str[i+1] when i is last index causes out-of-bounds; also lacks else for mismatched types]
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