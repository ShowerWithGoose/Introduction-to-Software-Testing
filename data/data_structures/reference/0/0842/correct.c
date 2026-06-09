#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[1030];
int flag[1030];

int cal(char a, char b);

int main()
{
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '-' && i && (str[i - 1] < str[i + 1]) && cal(str[i - 1], str[i + 1]))
            flag[i] = 1;
    }
    for (int i = 0; i < len; i++)
    {
        if (flag[i])
        {
            for (int j = 1; j < str[i + 1] - str[i - 1]; j++)
            {
                printf("%c", str[i - 1] + j);
            }
            i++; //跳两个
        }
        printf("%c", str[i]); //如果不需要补充，输出原串
    }
    // printf("%s",str);
    return 0;
}

int cal(char a, char b)
{
    if (isdigit(a) && isdigit(b))
        return 1;
    else if (isupper(a) && isupper(b))
        return 1;
    else if (islower(a) && islower(b))
        return 1;
    return 0;
}
