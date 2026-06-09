#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ 条件应使用 '>' 而不是 '>='，因为要求后面字符大于前面字符（严格大于）
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ 类型检查不完整，应确保 start 和 end 属于同一类别（例如 start>='a'&&start<='z' && end>='a'&&end<='z'），且未包含顺序检查
            {
                i++; // 跳过'-' // @@ 无条件跳过'-'，但在内层 else（类型不匹配）分支中不应跳过，应在内层判断后再决定是否跳过
                for (char k = start + 1; k <= end; k++) // @@ 缺少输出起始字符 start；同时循环结束后未跳过结束字符 end，导致下次循环会重复输出 end
                {
                    s2[j++] = k;
                }
            }
            else
            {
                s2[j++] = c; // @@ 类型不匹配时应输出完整的“c, '-', end”，但此处只输出了 c，并且之前已跳过 '-'，导致缺失 '-'
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