#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

void prt(char a, char b)
{
    for (char i = a + 1; i < b; ++i)
        printf("%c", i);
}

int main()
{
    char s[200];
    scanf("%s", s);
    int len = strlen(s);
    printf("%c", s[0]);
    for (int i = 1; i < len; ++i)
    {
        if (s[i] == '-')
        {
            if (isdigit(s[i - 1]) && isdigit(s[i + 1]) && s[i - 1] < s[i + 1])
                prt(s[i - 1], s[i + 1]);
            else if (isupper(s[i - 1]) && isupper(s[i + 1]) && s[i - 1] < s[i + 1])
                prt(s[i - 1], s[i + 1]);
            else if (islower(s[i - 1]) && islower(s[i + 1]) && s[i - 1] < s[i + 1])
                prt(s[i - 1], s[i + 1]);
            else
                printf("%c", s[i]);
        }
        else
            printf("%c", s[i]);
    }
    return 0;
}
