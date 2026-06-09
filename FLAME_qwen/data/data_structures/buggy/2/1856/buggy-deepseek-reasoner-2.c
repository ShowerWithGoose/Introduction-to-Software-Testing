#include <stdio.h>
int bj(char, char);
int js(int, int, char);
int main()
{
    char s[200];
    fgets(s, 200, stdin);
    int j = 0;
    for (int i = 0; s[i] != '\n'; i++) // @@ This loop stops at newline, but the expression includes '=' which should be processed; however, it does not handle '=' specially.
    {
        if (s[i] != ' ')
        {
            s[j] = s[i];
            j += 1;
        }
    }
    s[j] = '\0';
    int m = 0;
    int d[100] = {0};
    char f[100] = {0};
    int t1 = 0, t2 = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            m = m * 10 + (s[i] - '0');
        }
        else
        {
            d[t1] = m;
            t1 += 1;
            m = 0;
            if (t2 >= 2) // @@ The reduction logic for operators is incorrect; it does not correctly implement operator precedence.
            {
                if (bj(f[t2 - 2], f[t2 - 1]) == 0) // @@ bj returns 0 when earlier operator has lower precedence, but the combination may be wrong.
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]); // @@ This combines the last two numbers with the second operator; but indices may be off.
                }
                else
                {
                    t1 -= 1;
                    d[t1 - 2] = js(d[t1 - 2], d[t1 - 1], f[t2 - 2]); // @@ Combining first two numbers with first operator, but then shifting.
                    d[t1 - 1] = d[t1];
                }
                t2 -= 1;
                if (bj(f[t2], s[i]) == 2) // @@ Using f[t2] after decrement; array indices may be invalid.
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]); // @@ Further reduction logic is confusing and likely wrong.
                    t2 -= 1;
                }
            }
            f[t2] = s[i];
            t2++; // @@ Pushes '=' as an operator, but js does not handle '=', causing undefined behavior.
        }
    }
    if (t1 == 1) // @@ The final evaluation is insufficient; for expressions with more than two numbers, the result is incorrect.
    {
        printf("%d", d[0]);
    }
    else
    {
        printf("%d", js(d[0], d[1], f[0])); // @@ Only handles one operator left, but there could be multiple operators.
    }
    return 0;
}
int bj(char a, char b)
{
    if (a == '+' || a == '-')
    {
        if (b == '+' || b == '-')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (b == '+' || b == '-')
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}
int js(int a, int b, char x)
{
    if (x == '+')
    {
        return a + b;
    }
    else if (x == '-')
    {
        return a - b;
    }
    else if (x == '*')
    {
        return a * b;
    }
    else if (x == '/')
    {
        return a / b;
    }
    // @@ Missing handling for '=' operator; will cause undefined behavior if x is '='.
}