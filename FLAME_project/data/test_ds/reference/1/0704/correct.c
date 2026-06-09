#include <stdio.h>
#include <string.h>
char s[1000];
int main()
{
    gets(s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '-')
        {
            if ((s[i - 1] >= 'a' && s[i + 1] <= 'z') || (s[i - 1] >= 'A' && s[i + 1] <= 'Z') || (s[i - 1] >= '0' && s[i + 1] <= '9'))
            {
                int n = s[i + 1] - s[i - 1]; // n--interval
                if (n > 1)
                {
                    for (int k = 1;len - k != i; k++) // 右移k，即（n-2）格
                    {
                        s[len - 1 + n - 1 - k] = s[len - k];
                    }
                    s[len + n - 2] = '\0';
                    for (int l = 0; l < n - 1; l++)
                    {
                        s[i + l] = s[i - 1] + l + 1;
                    }
                    len += n-2 ;
                }
            }
        }
    }
    puts(s);
}
