#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define mian main
typedef long long ll;
typedef unsigned long long ull;
#define forsx(i, a, b) for (int i = (a); i < (b); ++i)
#define forjx(i, a, b) for (int i = (a); i > (b); --i)

#define ElementType int
ElementType max(ElementType a, ElementType b)
{
    return a > b ? a : b;
}

ElementType min(ElementType a, ElementType b)
{
    return a < b ? a : b;
}
char a[100], b;
int main(int argc, const char *argv[])
{
    gets(a);
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == '-')
        {
            if (islower(a[i - 1]) && islower(a[i + 1]) && a[i + 1] > a[i - 1])
            {
                for (b = a[i - 1] + 1; b < a[i + 1]; b++)
                    printf("%c", b);
            }
            else if (isupper(a[i - 1]) && isupper(a[i + 1]) && a[i + 1] > a[i - 1])
            {
                for (b = a[i - 1] + 1; b < a[i + 1]; b++)
                    printf("%c", b);
            }
            else if (isdigit(a[i - 1]) && isdigit(a[i + 1]) && a[i + 1] > a[i - 1])
            {
                for (b = a[i - 1] + 1; b < a[i + 1]; b++)
                    printf("%c", b);
            }
            else
                printf("%c", a[i]);
        }
        else
            printf("%c", a[i]);
    }
    putchar('\n');
    return 0;
}
