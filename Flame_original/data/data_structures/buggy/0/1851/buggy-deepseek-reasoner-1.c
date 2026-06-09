#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ condition insufficient; need to check same type and end>start
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ incorrect range check; should ensure both in same range and end>start
            {
                i++; // 跳过'-' // @@ should increment i by 2 (i+=2) to also skip end character
                for (char k = start + 1; k <= end; k++) // @@ missing start character; should start from start
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