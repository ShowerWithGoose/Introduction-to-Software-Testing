#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ 应使用 > 而不是 >=，因为要求后面的字符严格大于前面的字符
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9'))
            {
                i++; // 跳过'-' // @@ 此处缺少将起始字符 start 添加到 s2 中的语句，导致展开后丢失起始字符
                for (char k = start + 1; k <= end; k++) // @@ 循环条件应改为 k < end，否则会重复添加 end 字符（end 会被后续循环再次添加）
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