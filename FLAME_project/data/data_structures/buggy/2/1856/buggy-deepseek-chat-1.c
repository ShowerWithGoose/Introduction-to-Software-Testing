#include <stdio.h>
int bj(char, char);
int js(int, int, char);
int main()
{
    char s[200];
    fgets(s, 200, stdin);
    int j = 0;
    for (int i = 0; s[i] != '\n'; i++)
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
            if (t2 >= 2) // @@ The condition should be t2 >= 1 to check if there is at least one operator in the operator stack; t2 >= 2 is incorrect because t2 is the count of operators, and we need to compare with the previous operator.
            {
                if (bj(f[t2 - 2], f[t2 - 1]) == 0) // @@ The indices f[t2-2] and f[t2-1] are incorrect; when t2 is the count of operators, the last operator is at index t2-1, and the one before that is at t2-2, but this logic is flawed because it assumes two operators exist when t2>=2, but the operator stack may not be properly ordered.
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]); // @@ This incorrectly uses f[t2-1] as the operator, but the logic for operator precedence and evaluation order is wrong.
                }
                else
                {
                    t1 -= 1;
                    d[t1 - 2] = js(d[t1 - 2], d[t1 - 1], f[t2 - 2]); // @@ This incorrectly modifies d[t1-2] and d[t1-1], and the operator f[t2-2] is used incorrectly, leading to wrong evaluation order.
                    d[t1 - 1] = d[t1];
                }
                t2 -= 1;
                if (bj(f[t2], s[i]) == 2) // @@ After decrementing t2, f[t2] refers to the previous operator, but this comparison with s[i] is misplaced and does not correctly handle operator precedence.
                {
                    t1 -= 1;
                    d[t1 - 1] = js(d[t1 - 1], d[t1], f[t2 - 1]); // @@ This further reduces t1 and uses f[t2-1] incorrectly, causing incorrect evaluation.
                    t2 -= 1;
                }
            }
            f[t2] = s[i];
            t2++;
        }
    }
    if (t1 == 1)
    {
        printf("%d", d[0]);
    }
    else
    {
        printf("%d", js(d[0], d[1], f[0])); // @@ This only handles the case with exactly two numbers and one operator, but does not correctly evaluate expressions with multiple operators; the entire evaluation logic is flawed.
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
}