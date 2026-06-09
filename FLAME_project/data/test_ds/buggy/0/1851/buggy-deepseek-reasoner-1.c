#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ 条件不完善：应检查end>start且类型相同；且分支内缺少输出c的语句
        {
            char start = c;//首 // @@ 缺少将start输出到s2的语句
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ 类型检查条件有误，应同时限制start和end在同一字符范围内
            {
                i++; // 跳过'-' // @@ 只跳过了'-'，还应跳过结束字符，否则结束字符被重复输出，应改为`i += 2;`
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