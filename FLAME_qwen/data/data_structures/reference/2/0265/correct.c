#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define i64 long long int

int main()
{
    char s[1000];
    i64 num = 0;
    i64 stack[500], top = 0;
    char sign = '+';
    fgets(s, 1000, stdin);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (c == ' ') continue;
        if (isdigit(c))
        {
            num = 10 * num + (c - '0');
        }
        if (!isdigit(c) || i == len - 1)
        {
            switch (sign)
            {
            case '+':
                stack[top++] = num;
                break;
            case '-':
                stack[top++] = -num;
                break;
            case '*':
                stack[top - 1] *= num;
                break;
            case '/':
                stack[top - 1] /= num;
                break;
            }
            sign = c;
            num = 0;
        }
    }

    i64 sum = 0;
    for (int i = 0; i < top; i++)
    {
        sum += stack[i];
        // printf("%lld ", stack[i]);
    }
    printf("%lld\n", sum);
    return 0;
}
