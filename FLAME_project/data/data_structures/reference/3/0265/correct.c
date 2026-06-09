#include <stdio.h>
#include <string.h>

int main()
{
    char n;
    int p = 0, map[888], dot = -1;
    while (scanf("%c", &n) != 'EOF')
    {
        if ('0' <= n && n <= '9')
        {
            map[p++] = n - '0';
        }
        else if (n == '.')
        {
            dot = p;
        }
        else
        {
            break;
        }
    }
    if (dot == -1)
        dot = p;
    int dotto = -1;
    for (int i = 0; i < p; i++)
    {
        if (map[i] != 0)
        {
            dotto = i + 1;
            break;
        }
        else
        {
            map[i] = -1;
        }
    }
    for (int i = p - 1; i >= 0; i--)
    {
        if (map[i] != 0)
            break;
        else
            map[i] = -1;
    }
    if (dotto == -1)
    {
        printf("0");
        return 0;
    }

    int c = dot - dotto;
    for (int i = 0; i < p; i++)
    {
        if (dotto == i)
        {
            int flag = 0;
            for (int j = i; j < p; j++)
            {
                if (map[j] != -1 && map[j] != 0)
                {

                    flag = 1;
                    // printf("[zkhu is map[%d], value is %d]", j, map[j]);
                    break;
                }
            }
            if (flag == 1)
                printf(".");
        }
        if (map[i] != -1)
            printf("%d", map[i]);
    }
    printf("e%d\n", c);
    return 0;
}
