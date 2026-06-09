#include<stdio.h>

char str[105];
int main()
{

    fgets(str, 104, stdin);
    int spot_count = 0, numb_start = 0, length = strlen(str);
    for (int i = 0; i < length - 1; i++)
    {

        if (str[i] == '0')
            continue;
        if (str[i] != '0' && str[i] != '.')
        {

            if (numb_start != 0)
                continue;
            numb_start = i + 1;
            if (str[0] == '0')
                numb_start = i - 1;
        }
        if (str[i] == '.')
            spot_count = i - 1;
    }
    if (str[0] == '0')
    {

        if (numb_start + 2 >= length - 1)
            printf("%c", str[numb_start + 1]);
        else
            printf("%c.", str[numb_start + 1]);
        for (int i = numb_start + 2; i < length - 1; i++)
        {

            printf("%c", str[i]);
        }
        printf("e-%d", abs(numb_start - spot_count));
    }
    // printf("%d %d", spot_count, numb_start);
    if (str[0] != '0')
    {

        printf("%c.", str[numb_start - 1]);
        for (int i = numb_start; i < length - 1; i++)
        {

            if (str[i] == '.')
                continue;
            printf("%c", str[i]);
        }
        printf("e%d", abs(numb_start - spot_count - 1));
    }
    return 0;
}

