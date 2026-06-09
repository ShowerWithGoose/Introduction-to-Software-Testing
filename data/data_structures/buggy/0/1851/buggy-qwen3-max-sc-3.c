#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c)
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ [The condition incorrectly checks only the bounds of 'start' and 'end' independently, not whether both belong to the same category (e.g., both lowercase). For example, 'a' and 'Z' would pass 'start >= a' and 'end <= Z', but they are different types. Also, it doesn't ensure that both are in the same group (like both digits), which violates the problem requirement.]
            {
                i++; // 跳过'-'
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