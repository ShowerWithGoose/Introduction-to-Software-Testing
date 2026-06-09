#include <stdio.h>
#include <math.h>
#include <string.h>

char str[110] = {0};

int main()
{
    char a, c;
    /*int k = 0;
    c= getchar();
    while (c != EOF)
    {
        str[k++] = c;
        c = getchar();
    }*/
    gets(str);

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '-')
        {
            if (i == 0)
            {
                printf("-");
            }

            else if (str[i - 1] >= 'A' && str[i - 1] < 'Z')
            {
                if (str[i + 1] > str[i - 1] && str[i + 1] <= 'Z')
                {
                    for (int p = 1; p < (str[i + 1]) - (str[i - 1]); p++)
                    {
                        a = str[i - 1] + p;
                        printf("%c", a);
                    }
                }
                else
                printf("-");
                
            }
			else if (str[i - 1] >= '0' && str[i - 1] < '9')
            {
                if (str[i + 1] > str[i - 1] && str[i + 1] <= '9')
                {
                    for (int p = 1; p < (str[i + 1] ) - (str[i - 1] ); p++)
                    {
                        a = str[i - 1] + p;
                        printf("%c", a);
                    }
                }
                else
                printf("-");
                
            }

            

            else if (str[i - 1] >= 'a' && str[i - 1] < 'z')
            {
                if (str[i + 1] > str[i - 1] && str[i + 1] <= 'z')
                {
                    for (int p = 1; p < (str[i + 1]) - (str[i - 1]); p++)
                    {
                        a = str[i - 1] + p;
                        printf("%c", a);
                    }
                }
                else
                {
                    printf("-");
                }
            }

            else
            printf("-");
            
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}




