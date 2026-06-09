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
                            printf("%c", j); @@ [Loop condition should be j <= str[i+1] to include the end character]
                    }
                    else
                        printf("%c",str[i]); @@ [Should print '-' and the next character as-is when expansion condition fails, but this only prints '-', and skips handling of str[i+1]]
                }
                else
                    printf("%c",str[i]); @@ [Missing else case: if str[i+1] is not a digit, should output '-' unchanged, but also need to ensure str[i+1] is printed later; current logic may skip it]
            }
            else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
            {
                if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j); @@ [Loop condition should be j <= str[i+1] to include the end character]
                    }
                    else
                        printf("%c", str[i]); @@ [Same issue: only prints '-', but str[i+1] will be printed again in next iteration, causing duplication or incorrect output]
                }
                else
                    printf("%c", str[i]); @@ [Same missing handling: should output '-' as-is, but str[i+1] may be printed again]
            }
            else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
            {
                if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j); @@ [Loop condition should be j <= str[i+1]]
                    }
                    else
                        printf("%c", str[i]); @@ [Only prints '-', but str[i+1] remains to be printed in next loop iteration]
                }
                else
                    printf("%c", str[i]); @@ [Same issue: incomplete handling of non-matching cases]
            }
            else
                printf("%c", str[i]); @@ [This handles cases where left char is not alphanumeric, but doesn't account for what happens to str[i+1]; also, no skipping of next char]
        }
        else
            printf("%c", str[i]);
    }
}