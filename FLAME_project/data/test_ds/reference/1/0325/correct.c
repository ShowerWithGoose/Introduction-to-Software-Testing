#include <stdio.h>
#include <string.h>
char str[1028];
char h_light[1001] = {0};

int main()
{
    fgets(str, 1028, stdin);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '-' && i != 0)
        {
            if (str[i - 1] >= str[i + 1])
                break;
            if (str[i + 1] - str[i - 1] > 25)
                break;
            if (str[i - 1] < 58 && str[i - 1] > 47)
                if (str[i + 1] < 58)
                    h_light[i] = '1';
            if (str[i - 1] < 91 && str[i - 1] > 64)
                if (str[i + 1] < 91)
                    h_light[i] = '1';
            if (str[i - 1] < 123 && str[i - 1] > 96)
                if (str[i + 1] < 123)
                    h_light[i] = '1';
        }
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (h_light[i] == '1')
        {
            for (int j = 1; j < str[i + 1] - str[i - 1]; j++)
            {
                printf("%c", str[i - 1] + j);
            }
            i++;
        }
        printf("%c", str[i]);
    }
    // printf("%s",str);
    return 0;
}


