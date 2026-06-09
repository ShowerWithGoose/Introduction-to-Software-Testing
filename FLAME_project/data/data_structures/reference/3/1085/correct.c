#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define check(VAR, CONV) printf("check:" #VAR "=%" #CONV "\n", VAR)
typedef long long ll;
typedef double db;
int main(void)
{
    int digit = 0, flag = 1;
    char temp;
    //
    scanf("%c", &temp);
    if (temp == '0')
    {
        scanf("%c", &temp);
        digit--;
        while (scanf("%c", &temp) != EOF)
        {
            if (temp == '0' && flag == 1)
            {
                digit--;
            }
            else if ('0' <= temp && temp <= '9')
            {
                if (flag == 1)
                {
                    flag++;
                }
                else if (flag == 2)
                {
                    printf(".");
                    flag++;
                }
                printf("%c", temp);
            }
        }
        printf("e%d", digit);
    }
    else
    {
        if ('0' <= temp && temp <= '9')
            printf("%c", temp);
        printf(".");
        while (scanf("%c", &temp) != EOF)
        {
            if (temp != '.' && '0' <= temp && temp <= '9')
            {
                printf("%c", temp);
                digit++;
            }
            else
            {
                while (scanf("%c", &temp) != EOF)
                {
                    if ('0' <= temp && temp <= '9')
                        printf("%c", temp);
                }
                printf("e%d", digit);
                break;
            }
        }
    }

    return 0;
}
