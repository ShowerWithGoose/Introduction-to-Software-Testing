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
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ The condition for checking character types is incorrect. It only checks if start is greater than or equal to the lower bound and end is less than or equal to the upper bound, but fails to ensure that both start and end belong to the same specific range (e.g., both are lowercase, both are uppercase, or both are digits). For example, 'a' and 'Z' would pass this check incorrectly if logic allowed, but more importantly, it doesn't strictly enforce they are in the *same* category as required by "same type". A correct check would be: (start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z') || (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z') || (start >= '0' && start <= '9' && end >= '0' && end <= '9'). Also, the problem requires end > start, not just end >= start.
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