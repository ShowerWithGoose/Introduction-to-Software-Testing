#include <stdio.h>
#include <string.h>
char s[500], sym[500];
int digit[500];

int calculate(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else if (c == '/')
        return a / b;
}

int issymbol(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
        return 1;
    else
        return 0;
}

void squeez(char s[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != ' ')
            s[j++] = s[i];
    s[j] = '\0';
}

int main()
{
    int i, j = 0, k = 0;
    gets(s);
    squeez(s);
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            digit[j] = digit[j] * 10 + s[i] - '0';
            if (issymbol(s[i + 1]) == 1)
                j++;
        }
        if (issymbol(s[i]) == 1)
        {
            sym[k++] = s[i];
        }
    }
    int n = 0;
    while (sym[n] != '=')
    {
        if (sym[n + 1] != '=')
        {
            if ((sym[n + 1] == '*' || sym[n + 1] == '/') && (sym[n] == '+' || sym[n] == '-'))
            {
                digit[n + 2] = calculate(digit[n + 1], digit[n + 2], sym[n + 1]);
                digit[n + 1] = digit[n];
                sym[n + 1] = sym[n];
            }
            else
                digit[n + 1] = calculate(digit[n], digit[n + 1], sym[n]);
        }
        else
            digit[n + 1] = calculate(digit[n], digit[n + 1], sym[n]);
        n++;
    }
    printf("%d", digit[n]);
    return 0;
}
