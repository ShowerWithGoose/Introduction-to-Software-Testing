#include <stdio.h>
#include <string.h>
#define len 100
int main()
{
    int i, j = 0;
    int flag = 0;
    char a[len], b[len], c[len];
    int d[len];
    gets(a);
    for (i = 0; i < strlen(a) - 1; i++)
    {
        if ((a[i] != ' ') && (a[i] != '='))
            b[j++] = a[i];
        if (a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-')
        {
            flag = 1;
        }
    }
    b[j] = '\0';
    if (flag == 0)
    {
        puts(b);
    }
    else
    {
        int p = 0;
        int e = 0;
        int v = strlen(b);
        b[v] = '+'; @@ // Artificially appending '+' alters operator count and parsing logic, causing misalignment between numbers and operators.
        int temp;
        for (int w = 0; w <= v; w++)
        {
            if (b[w] >= '0' && b[w] <= '9')
            {
                e = e * 10 + (b[w] - '0');
                temp = e;
            }
            else
            {
                d[p] = temp, c[p] = b[w];
                printf("%d", d[p]); @@ // Premature printing of intermediate values corrupts final output format.
                p++;
                e = 0;
            }
        }
        c[p] = '\0';
        char cr7;
        for (int g = 0; g < p - 1; g++)
        {
            if (c[g] == '*' || c[g] == '/')
            {
                if (c[g - 1] == '+')
                    cr7 = '+';
                if (c[g - 1] == '-')
                    cr7 = '-';
                if (g == 0)
                    cr7 = '+'; @@ // Incorrect assumption that initial operator is always '+', but fails to handle cases where first number is negative or expression starts with number without preceding operator.
                if (c[g] == '*')
                {
                    d[g + 1] *= d[g];
                    d[g] = 0;
                    c[g] = cr7;
                }
                if (c[g] == '/')
                {
                    d[g + 1] = (d[g] / d[g + 1]); @@ // Division order is reversed: should be d[g] / d[g+1], but current logic uses wrong operands due to left-to-right parsing without proper precedence handling.
                    d[g] = 0;
                    c[g] = cr7;
                }
            }
        }
        for (int s = 0; s < p - 1; s++)
        {
            if (c[s] == '+')
                d[0] += d[s + 1];
            if (c[s] == '-')
                d[0] -= d[s + 1]; @@ // Accumulation into d[0] assumes all prior multiplicative operations are resolved, but incorrect handling of operator precedence and operand indices leads to wrong results.
        }
        printf("%d", d[0]);
    }
    return 0;
}