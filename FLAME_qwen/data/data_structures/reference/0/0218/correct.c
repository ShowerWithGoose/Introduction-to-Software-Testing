#include <stdio.h>
#include <string.h>
#define N (100 + 10)
int judge(char a, char b);
int main()
{
    char in[N], t;
    scanf("%s", in);
    int i, len;
    len = strlen(in);
    for (i = 0; i < len; ++i)
    {
        if (i == len - 1 || in[i + 1] != '-')
            printf("%c", in[i]);
        else
        {
            if (in[i] < in[i + 2] && judge(in[i], in[i + 2]))
            {
                for (t = in[i]; t < in[i + 2]; ++t)
                    printf("%c", t);
                i++;
            }
            else
            {
                printf("%c-", in[i++]);
            }
        }
    }
    printf("\n");
    return 0;
}
int is_digit(char a)
{
    return a >= '0' && a <= '9';
}
int is_upper(char a)
{
    return a >= 'A' && a <= 'Z';
}
int is_lower(char a)
{
    return a >= 'a' && a <= 'z';
}
int judge(char a, char b)
{
    if (is_digit(a) && is_digit(b))
        return 1;
    else if (is_lower(a) && is_lower(b))
        return 1;
    else if (is_upper(a) && is_upper(b))
        return 1;
    return 0;
}



