#include <stdio.h>
int main()
{
    char qian = 0, hou = 0, mid = 0, in = 0, text[1000] = "\0";
    int i = 0;
    scanf("%s", text);
    for (; text[i] != '\0'; i++)
    {
        if (text[i] != '-')
        {
            printf("%c", text[i]);
        }
        else
        {
            if (text[i - 1] >= 'a' && text[i - 1] <= 'z' && text[i + 1] >= 'a' && text[i + 1] <= 'z' && text[i - 1] < text[i + 1] || text[i - 1] >= '0' && text[i - 1] <= '9' && text[i + 1] >= '0' && text[i + 1] <= '9' && text[i - 1] < text[i + 1] || text[i - 1] >= 'A' && text[i - 1] <= 'Z' && text[i + 1] >= 'A' && text[i + 1] <= 'Z' && text[i - 1] < text[i + 1])
            {
                for (mid = text[i - 1] + 1; mid < text[i + 1]; mid++)
                {
                    printf("%c", mid);
                }
            }
            else
            {
                printf("-");
            }
        }
    }
    return 0;
}
