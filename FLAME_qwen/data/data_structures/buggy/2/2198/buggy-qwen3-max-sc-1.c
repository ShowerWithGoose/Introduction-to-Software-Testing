#include <stdio.h>
#include <string.h>
#define len 100
int main()
{
    int i, j = 0;
    int flag = 0;
    char a[len], b[len], c[len];
    int d[len];
    gets(a); // @@ [Using `gets()` is unsafe and deprecated; many modern compilers reject it, causing compilation error. Should use `fgets()` instead.]
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
        b[v] = '+'; // @@ [Writing beyond the declared size of array `b` (which is `len=100`) may cause buffer overflow if `strlen(b)` is already 99 or more. Also modifies input unexpectedly.]
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
                printf("%d", d[p]); // @@ [This debug print alters expected output format; problem requires only final result to be printed.]
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
                    cr7 = '+'; // @@ [Logic flaw: assumes preceding operator when handling multiplication/division, but doesn't correctly handle precedence in all cases (e.g., expression starting with negative number not supported). Also, division order is wrong: should be d[g] / d[g+1], but stored as d[g+1] = d[g]/d[g+1], which is correct mathematically but later steps misuse d[g]=0.]
                if (c[g] == '*')
                {
                    d[g + 1] *= d[g];
                    d[g] = 0;
                    c[g] = cr7;
                }
                if (c[g] == '/')
                {
                    d[g + 1] = (d[g] / d[g + 1]); // @@ [Division truncates toward zero as required, but if d[g+1] is zero, causes undefined behavior (division by zero). Also, after setting d[g]=0, later addition/subtraction uses incorrect values.]
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
                d[0] -= d[s + 1]; // @@ [After zeroing out d[g] during * and / processing, this accumulation uses d[0] as accumulator but includes zeroed terms incorrectly; also fails to skip processed * / terms properly.]
        }
        printf("%d", d[0]);
    }
    return 0;
}