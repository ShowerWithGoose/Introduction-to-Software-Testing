#include <stdio.h>
#include <string.h>
char prepare[2000];
char print[2000];
int main()
{
    int len, k, j, i = 0, m = 0, l;
    gets(prepare);
    len = strlen(prepare);
    for (i = 0; i < len; i++)
    {
        if (prepare[i] == '.')
        {
            k = i;
            break;
        }
    }
    if (k == 1)
    {
        if (prepare[0] == '0')
        {
            for (i = 2; i < len; i++)
            {
                if (prepare[i] != '0')
                {
                    j = i;
                    break;
                }
            }
            print[0] = prepare[j];
            if (j != (len - 1))
            {
                print[1] = '.';
                for (i = j + 1, m = 2; i < len; i++, m++)
                    print[m] = prepare[i];
            }
            else
                m = 1;
            for (i = 0; i < m; i++)
                printf("%c", print[i]);
            printf("e-%d", j - 1);
        }
        else
        {
            for (i = 0; i < len; i++)
                printf("%c", prepare[i]);
            printf("e0");
        }
    }
    else
    {
        print[0] = prepare[0];
        print[1] = '.';
        for (i = 1, m = 2; i < len; i++)
        {
            if (prepare[i] != '.')
            {
                print[m] = prepare[i];
                m++;
            }
        }
        for (i = 0; i < len; i++)
            printf("%c", print[i]);
        printf("e%d", k - 1);
    }
    return 0;
}
