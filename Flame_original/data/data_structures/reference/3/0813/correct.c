#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    char type_in[200] = {'\0'};
    int point, i, flag = 0, zero = 0;
    gets(type_in);
    for (i = 0; type_in[i] != '\0'; i++)
    {
        if (type_in[i] != '0' && type_in[i] != '.' && flag == 0)
        {
            printf("%c", type_in[i]);
            flag++;
        }
        else if (flag == 1 && type_in[i] != '.')
        {
            printf(".%c", type_in[i]);
            flag++;
        }
        else if (flag == 2 && type_in[i] != '.')
        {
            printf("%c", type_in[i]);
        }
    }
    if (type_in[0] == '0')
    {
        for (i = 2; type_in[i] == '0'; i++)
        {
            zero++;
        }
        printf("e-%d", zero + 1);
    }
    else
    {
        for (point = 0; type_in[point] != '.'; point++)
            ;
        printf("e%d", point - 1);
    }
    return 0;
}
