#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ Condition uses '>=' instead of '>' as required by the problem; also lacks a check for s[i+1] != '\0', which could lead to out-of-bounds access if '-' is the last character.
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ Incorrect range validation logic; only checks the lower bound for start and upper bound for end, allowing mixed types (e.g., 'a' and 'Z'). Should verify both characters strictly belong to the same category.
            {
                i++; // 跳过'-' // @@ Only increments i by 1 to skip '-', but the loop's i++ will process 'end' again in the next iteration, causing duplicate output. Should increment i by 2 to skip both '-' and 'end'.
                for (char k = start + 1; k <= end; k++)
                {
                    s2[j++] = k;
                }
            }
            else
            {
                s2[j++] = c;
            }
        }
        else
        {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
    printf("%s\n", s2);
}

int main()
{
    char input[100];
    scanf("%s", input);

    expand(input);

    return 0;
}