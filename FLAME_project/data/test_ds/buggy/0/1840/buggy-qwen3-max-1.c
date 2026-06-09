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
                            printf("%c", j); @@ [The loop condition should be j <= str[i+1] to include the ending character, but more importantly, this entire block fails to handle cases where expansion shouldn't happen (like mixed types), and doesn't skip the next character after '-', leading to duplication. Also, when expansion conditions aren't met, it only prints '-', but should print '-' followed by the next character as-is.]
                    }
                    else
                        printf("%c",str[i]); @@ [Should print "-X" (the dash and the following character) when expansion isn't valid, not just '-'.]
                }
                else
                    printf("%c",str[i]); @@ [Missing case: if previous is digit but next is not, should output '-' as-is (but actually should output "-<next>" together). However, this else is missing entirely — current code falls through incorrectly.]
            }
            else if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
            {
                if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j); @@ [Same issue: loop should be j <= str[i+1]. Also, even if fixed, the logic doesn't skip the next character, so it will be printed again in the next iteration.]
                    }
                    else
                        printf("%c", str[i]); @@ [Should output "-X", not just '-'.]
                }
                else
                    printf("%c",str[i]); @@ [Again, missing proper handling: should output the dash and let the next char be printed normally, but current structure causes incomplete output.]
            }
            else if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
            {
                if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
                {
                    if (str[i + 1] > str[i - 1])
                    {
                        for (j = str[i - 1] + 1; j < str[i + 1]; j++)
                            printf("%c", j); @@ [Loop condition error: should be j <= str[i+1]. Also, fails to skip next character, causing duplication or incorrect output.]
                    }
                    else
                        printf("%c", str[i]); @@ [Should print "-X", not just '-'.]
                }
                else
                    printf("%c",str[i]); @@ [Incorrect: when types don't match (e.g., B-e), should output "-e", but this only outputs '-', and then 'e' gets printed in next iteration, resulting in "B-e" becoming "Be" — which matches the buggy output. This is the core error.]
            }
            else
                printf("%c", str[i]); @@ [This handles cases where the character before '-' is not alphanumeric, but still only prints '-', and the next character will be printed separately, which may be acceptable only if we ensure no double-printing. However, the bigger issue is that in mixed-type cases like B-e, the code enters the uppercase block, finds that 'e' is not uppercase, prints '-', then on next iteration prints 'e', resulting in "Be" instead of "B-e".]
        }
        else
            printf("%c", str[i]);
    }
}