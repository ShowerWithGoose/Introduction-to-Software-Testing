#include <stdio.h>
#include <string.h>
#define len 100
int main()
{
    int i, j = 0;
    int flag = 0;
    char a[len], b[len], c[len];
    int d[len];
    gets(a); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use `fgets` instead.]
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
        b[v] = '+'; // @@ [Writing beyond the declared size of array `b` (which is `len=100`) may cause buffer overflow if `strlen(b)` is already 99 or more. Also, this modifies the string without ensuring space for the extra character.]
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
                printf("%d", d[p]); // @@ [This debug print alters expected output format; problem requires only final result to be printed once at the end.]
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
                if (c[g - 1] == '+') // @@ [When `g == 0`, `c[g - 1]` accesses `c[-1]`, which is out-of-bounds undefined behavior.]
                    cr7 = '+';
                if (c[g - 1] == '-') // @@ [Same as above: accessing `c[-1]` when `g == 0` leads to undefined behavior.]
                    cr7 = '-';
                if (g == 0)
                    cr7 = '+';
                if (c[g] == '*')
                {
                    d[g + 1] *= d[g];
                    d[g] = 0;
                    c[g] = cr7;
                }
                if (c[g] == '/')
                {
                    d[g + 1] = (d[g] / d[g + 1]); // @@ [Incorrect operand order: should be `d[g] / d[g+1]` but stored into `d[g+1]`; however, logic assumes left-to-right evaluation but overwrites operands incorrectly. Also, integer division by zero not handled, though problem states expression is valid.]
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
                d[0] -= d[s + 1];
        }
        printf("%d", d[0]);
    }
    return 0;
}