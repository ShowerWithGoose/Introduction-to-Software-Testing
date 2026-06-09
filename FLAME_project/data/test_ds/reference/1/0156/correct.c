#include <stdio.h>
#include <math.h>
#include <string.h>

char str[110] = {0};

int main()
{
    char a, c;
    int k = 0;
    c = getchar();
    while (c != EOF)
    {
        str[k++] = c;
        c = getchar();
    }

    int i=0,p=1; 
	
	for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '-')
        {
            if (i == 0)
            {
                printf("-");
            }

            else if (str[i - 1] >= '0' && str[i - 1] < '9')
            {
                if (str[i + 1] > str[i - 1] && str[i + 1] <= '9')
                {
                    for (p = 1; p < (str[i + 1] + '0') - (str[i - 1] + '0'); p++)
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

            else if (str[i - 1] >= 'A' && str[i - 1] < 'Z')
            {
                if (str[i + 1] > str[i - 1] && str[i + 1] <= 'Z')
                {
                    p=1;
					for (p = 1; p < (str[i + 1] + '0') - (str[i - 1] + '0'); p++)
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

            else if (str[i - 1] >= 'a' && str[i - 1] < 'z')
            {
                if (str[i + 1] > str[i - 1] && str[i + 1] <= 'z')
                {
                    p=1;
					for (p = 1; p < (str[i + 1] + '0') - (str[i - 1] + '0'); p++)
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
            {
                printf("-");
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    return 0;
}

