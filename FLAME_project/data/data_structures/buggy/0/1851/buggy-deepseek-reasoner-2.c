#include <stdio.h>

void expand(char s[])
{
    char c;
    int i = 0, j = 0;
    char s2[100]; // 新的字符数组

    while ((c = s[i++]) != '\0')
    {
        if (s[i] == '-' && s[i+1] >= c) // @@ Error: should be > not >=; also index logic leads to missing start and duplicate end
        {
            char start = c;//首
            char end = s[i+1];//尾
            if ((start >= 'a' && end <= 'z') || (start >= 'A' && end <= 'Z') || (start >= '0' && end <= '9')) // @@ Error: condition does not correctly ensure both characters are in same valid range; should check start <= 'z', etc.
            {
                i++; // 跳过'-' // @@ Error: only skipping '-', but should also skip the end character to prevent duplicate output
                for (char k = start + 1; k <= end; k++) // @@ Error: starts from start+1, missing start character; also results in end being output again later
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