#include <stdio.h>
#include <string.h>
int j(char a, char b)
{
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z' && a < b)
        return 1;
    else if (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z' && a < b)
        return 1;
    else if (a >= '0' && a <= '9' && b >= '0' && b <= '9' && a < b)
        return 1;
    else
        return 0;
}
int main()
{
    char s[100000];
    while (gets(s) != NULL)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] != '-' && s[i + 1] != '-' && s[i - 1] != '-')
            {
                printf("%c", s[i]);
            }
            else if (s[i] == '-')
            {
                if (j(s[i - 1], s[i + 1]) == 1)
                {
                    if(s[i-2]!='-')
                    {
                    printf("%c", s[i - 1]);
                    }
                    if(s[i + 1] - s[i - 1]!=1)
                    {

                    for (int j = 0; j <= (int)(s[i + 1] - s[i - 1]-2)+1; j++)
                    {
                        printf("%c", s[i - 1] + j+1 );
                    }
                
                    }
                    else
                    {
                        printf("%c", s[i + 1]);
                    }
                }
                else
                {
                   if(s[i-2]!='-')
                    {
                    printf("%c", s[i - 1]);
                    }
                    printf("-");
                    printf("%c", s[i + 1]);
                }
            }
        }
    }

    return 0;
}

