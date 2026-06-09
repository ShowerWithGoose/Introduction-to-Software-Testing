#include <stdio.h>
#include <string.h>
#include <ctype.h>
int judge(char c1, char c2)
{
    if (c1 >= c2)
        return 0;
    if (isupper(c1) && isupper(c2) || islower(c1) && islower(c2) || isdigit(c1) && isdigit(c2))
        return 1;
    return 0;
}
int main()
{
    char ch1 = 0, ch2 = 0;
    while (~(ch2 = getchar()))
    {
        if (ch2 == '-')
        {
            if (!ch1)
                putchar(ch2);
            else
            {
                char ch3 = getchar();
                if (judge(ch1, ch3))
                {
                    for (char k = ch1 + 1; k <= ch3; k++)
                        putchar(k);
                }
                else
                {
                    putchar(ch2);
                    putchar(ch3);
                }
                ch1 = ch3;
            }
        }
        else
        {
            putchar(ch2);
            ch1 = ch2;
        }
    }
    return 0;
}


