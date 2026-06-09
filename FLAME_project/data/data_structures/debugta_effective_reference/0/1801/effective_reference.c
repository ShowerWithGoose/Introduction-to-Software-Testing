#include <stdio.h>
#include <string.h>
char str[200];
char s[400];
int main()
{
    scanf("%s",str);
    int i = 0, j = 0, flag = 0;
    int len1 = strlen(str);
    for (i = 0; i < len1; i++)
    {
        s[j] = str[i];
        if (str[i] == '-' && ((str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z') || (str[i - 1] >= '0' && str[i + 1] <= '9')))
        {
            int num = str[i + 1] - str[i - 1];
            while (num)
            {
                s[j] = s[j - 1] + 1;
                j++;
                flag = 1;
                num--;
            }
            i++;
        }
        if (flag == 0)
            j++;
        else
        {
            flag = 0;
        }
    }
    printf("%s", s);
    return 0;
}
