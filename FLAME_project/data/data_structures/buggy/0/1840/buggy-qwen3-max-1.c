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
                            printf("%c", j); @@ [The loop condition should be j <= str[i+1] to include the ending character, but more critically, this entire block fails to handle cases where the surrounding characters are of different types (e.g., B-e). In such cases, the '-' and the following character should be printed as-is, but the current logic only prints '-' in the else branches of same-type checks, and completely skips printing the next character when types differ.]
                    }
                    else
                        printf("%c",str[i]); @@ [When expansion condition fails (e.g., '5-3'), it should output "-3", not just "-". The current code prints only '-', and the next character (str[i+1]) will be printed again in the next iteration, causing duplication or incorrect output. Also, i is not incremented to skip the next character.]
                }
                else
                    printf("%c", str[i]); @@ [Missing handling for cross-type cases like '0-a'. Should output "-a", but only outputs '-', and 'a' will be printed again later.]
            }
            else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
            {
                if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j); @@ [Loop should be j <= str[i+1] to include the end character.]
                    }
                    else
                        printf("%c", str[i]); @@ [Same issue: should output "-x" (where x is next char), not just "-".]
                }
                else
                    printf("%c", str[i]); @@ [Fails to output the next character in cross-type cases.]
            }
            else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
            {
                if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j); @@ [Loop should be j <= str[i+1].]
                    }
                    else
                        printf("%c", str[i]); @@ [Should output "-X", not just "-".]
                }
                else
                    printf("%c", str[i]); @@ [In case like "B-e", this branch is taken (since 'B' is uppercase), but 'e' is not uppercase, so it prints '-', and then 'e' is printed again in the next iteration, resulting in "Be" instead of "B-e".]
            }
            else
                printf("%c", str[i]); @@ [This handles cases where the character before '-' is not alphanumeric, but still doesn't print the next character, leading to missing output.]
        }
        else
            printf("%c", str[i]);
    }
}