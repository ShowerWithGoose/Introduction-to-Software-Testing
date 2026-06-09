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
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ The condition for checking character types is incorrect. It only checks if the start is greater than or equal to the lower bound and end is less than or equal to the upper bound, but fails to ensure they are of the same type (e.g., both lowercase, both uppercase, or both digits). For example, 'a' and 'Z' would pass this check incorrectly because 'a' >= 'a' and 'Z' <= 'z' is false, but 'a' >= 'A' is true and 'Z' <= 'Z' is true, leading to mixed type expansion. More critically, it doesn't check if start and end are in the SAME range. E.g. a-z is valid, A-Z is valid, 0-9 is valid. But a-Z is not. The current logic `(start >= 'a' && end <= 'z')` allows start='a' and end='z'. But `(start >= 'A' && end <= 'Z')` allows start='A' and end='Z'. However, if start='a' and end='Z', the first part `start >= 'a'` is true, `end <= 'z'` is true ('Z' < 'z'), so it enters. This is wrong. It must ensure both are lowercase, OR both are uppercase, OR both are digits.
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