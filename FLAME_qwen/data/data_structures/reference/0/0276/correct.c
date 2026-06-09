#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int f(char a, char b)
{
    return (isupper(a) && isupper(b)) + (islower(a) && islower(b)) + (isdigit(a) && isdigit(b));
}
char ch[1000000];
int main()
{
    gets(ch);
    for (int i = 0; ch[i]; i++)
    {
        if (ch[i + 1] == '-' && f(ch[i], ch[i + 2])&&ch[i]<ch[i+2])
        {
            for (int j = ch[i]; j < ch[i + 2]; j++)
            {
                putchar(j);
            }
            i++;
        }
        else
            putchar(ch[i]);
    }

    return 0;
}


