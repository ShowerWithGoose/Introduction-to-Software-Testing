#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0') // @@ 索引使用方式容易导致后续逻辑错误，但非直接原因
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ 条件应为严格大于 '>'，相等时不应扩展
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9'))
            {
                i++; // 跳过'-'
                for (char k = start + 1; k <= end; k++) // @@ 循环条件应为 k < end，且缺少输出 start (c)
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