//1. 扩展字符A
#include <stdio.h>
#include <string.h>
#define SIZE 200
int main()
{
    char s[SIZE];
    char b, a;
    int i, length;
    gets(s);
    length = strlen(s);
    for (i = 0; i < length; i++)
    {
        if (s[i] == '-')
        {
            b = s[i - 1];
            a = s[i + 1];
            if (('a' <= b && b < a && a <= 'z') || ('A' <= b && b < a && a <= 'Z') || ('0' <= b && b < a && a <= '9'))
            {
                for (b = b + 1; b < a; b++)
                {
                    putchar(b);
                }
            }
            else
                putchar(s[i]);
        }
        else
            putchar(s[i]);
    }
    return 0;
}


