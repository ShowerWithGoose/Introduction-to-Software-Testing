#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
// char a[1000000];
// char b[1000000];
char a[100];
char b[100];
int ifsame(char *p)
{
    if ((isupper(*(p - 1)) && isupper(*(p + 1))) || (islower(*(p - 1)) && islower(*(p + 1))) || (isdigit(*(p - 1)) && isdigit(*(p + 1))))
    {
        if ((*(p + 1) - *(p - 1)) > 0)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int main()
{
    scanf("%s", a);
    char *p = a;
    p = strstr(a, "-");
    while (p != NULL)
    {
        if (ifsame(p))
        {
            int num;
            num = *(p + 1) - *(p - 1) - 1;
            strcpy(b, p + 1); //没有去掉多出来的2
            int i;
            for (i = 0; i < num; i++)
            {
                *(p + i) = *(p - 1) + i + 1;
            }
            while (*(p + i) != '\0')
            {
                *(p + i) = '\0';
                i++;
            }
            strcat(a, b);
            memset(b, 0, sizeof(b));
        }
        p++;
        p = strstr(p, "-");
    }
    puts(a);
    return 0;
}


