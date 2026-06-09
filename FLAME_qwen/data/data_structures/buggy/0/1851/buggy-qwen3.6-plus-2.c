#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ s[i+1] >= c only checks ASCII order, not type compatibility. Accessing s[i+1] without checking for '\0' may be unsafe if the string ends with '-'.
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9'))
            {
                i++; // 跳过'-' // @@ After incrementing, i points to end. The loop will process end again in the next iteration, causing duplication. Additionally, start (c) is never printed.
                for (char k = start + 1; k <= end; k++) // @@ The loop starts from start + 1, which misses the first character of the expansion range. It should start from start.
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
    scanf("%s", input); // @@ Using scanf("%s") without a width specifier risks buffer overflow. Should use scanf("%99s", input).

    expand(input);

    return 0;
}