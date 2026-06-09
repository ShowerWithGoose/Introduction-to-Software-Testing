#include <stdio.h>
#include <string.h>
int main()
{
    char num[2000];
    int count_lower = 2, count_upper = 0;
    scanf("%s", num);
    if (num[0] == '0')
    {
        while (num[count_lower] == '0')
            count_lower++;
        if (count_lower < strlen(num) - 1)
        {
            printf("%c.", num[count_lower]);
            for (int i = count_lower + 1; i <= strlen(num) - 1; i++)
            {
                printf("%c", num[i]);
            }
            printf("e%d", -(count_lower - 1));
        }
        else
        {
            printf("%ce%d", num[count_lower], -(count_lower - 1));
        }
    }
    if (num[0] != '0')
    {
        int flag_dot = 0;
        while (num[++count_upper] != '.' && (count_upper <= strlen(num) - 1))
            ; // count_upper既可作为10的count_upper次方
        printf("%c.", num[0]);
        for (int i = 1; i < strlen(num); i++)
        {
            if (num[i] == '.')
                continue;
            printf("%c", num[i]);
        }
        printf("e%d", count_upper - 1);
    }
}
