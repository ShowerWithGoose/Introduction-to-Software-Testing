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
        b[v] = '+'; @@ // This modifies the expression by appending '+', which changes operator precedence handling and leads to incorrect parsing of the last number.
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
                printf("%d", d[p]); @@ // Premature printing of intermediate numbers causes wrong output format and reveals internal state.
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
                    cr7 = '+'; @@ // Incorrect assumption that initial operator is always '+', but fails when first token is negative or missing context.
                if (c[g] == '*')
                {
                    d[g + 1] *= d[g];
                    d[g] = 0;
                    c[g] = cr7;
                }
                if (c[g] == '/')
                {
                    d[g + 1] = (d[g] / d[g + 1]); @@ // Division order is reversed: should be d[g] / d[g+1] only if left-to-right, but current logic overwrites d[g+1] incorrectly during traversal.
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
                d[0] -= d[s + 1]; @@ // Accumulation into d[0] assumes all prior multiplicative operations are resolved, but due to flawed earlier steps, operands may be zeroed or misassigned.
        }
        printf("%d", d[0]);
    }
    return 0;
}